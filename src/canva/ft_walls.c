/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:07:47 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/09 13:25:12 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>

#define N_WALL 'N'
#define S_WALL 'S'
#define W_WALL 'W'
#define E_WALL 'E'

void	ft_set_camera(void)
{
	char	dir;

	all()->player = ft_player_pos(all()->file->map);
	all()->caster.player.pos_x = (double)all()->player.x;
	all()->caster.player.pos_y = (double)all()->player.y;
	dir = all()->map[all()->player.x][all()->player.y];
	dir = 'E';
	if (dir == 'N' || dir == 'S')
		all()->caster.player.dir_x = 0;
	if (dir == 'W' || dir == 'E')
		all()->caster.player.dir_y = 0;
	if (dir == 'W')
		all()->caster.player.dir_x = -1;
	if (dir == 'E')
		all()->caster.player.dir_x = 1;
	if (dir == 'N')
		all()->caster.player.dir_y = 1;
	if (dir == 'S')
		all()->caster.player.dir_y = -1;
}

void	ft_calc_plane(void)
{
	all()->caster.view.plane_x = all()->caster.player.dir_y;
	all()->caster.view.plane_y = all()->caster.player.dir_x * -1;
	if (abs(all()->caster.view.plane_x) == (double)1)
		all()->caster.view.plane_x *= 0.66;
	if (abs(all()->caster.view.plane_y) == (double)1)
		all()->caster.view.plane_y *= 0.66;
}

void	ft_walls(void)
{
	t_data	*data[4];
	t_view	*view;
	t_alg	*a;

	data[0] = (canva())->sprite(N_WALL);
	data[1] = (canva())->sprite(S_WALL);
	data[2] = (canva())->sprite(W_WALL);
	data[3] = (canva())->sprite(E_WALL);
	if (!data[2] || !data[1] || !data[2] || !data[3])
		return ;
	ft_set_camera();
	ft_calc_plane();
	view = &(all()->caster.view);
	a = &(all()->caster.alg);
	//WALL CASTING
	a->x = -1;
	while (++(a->x) < a->w)
	{
		//calculate ray position and direction
		a->cam_x = 2 * a->x / (double)(a->w) - 1; //x-coordinate in camera space
		a->ray_x = view->dir_x + view->plane_x * a->cam_x;
		a->ray_y = view->dir_y + view->plane_y * a->cam_x;

		//which box of the map we're in
		a->map_x = (int)(view->pos_x);
		a->map_y = (int)(view->pos_y);

		//length of ray from current position to next x or y-side
		// double sideDistX;
		// double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		if (a->ray_x == 0)
			a->delta_x = 1e30;
		else
			a->delta_x = abs(1 / a->ray_x);
		if (a->ray_y == 0)
			a->delta_y = 1e30;
		else
			a->delta_y = abs(1 / a->ray_y);
		// double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		// int stepX;
		// int stepY;

		a->hit = 0; //was there a wall hit?
		// int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (a->ray_x < 0)
		{
			a->step_x = -1;
			a->side_x = (view->pos_x - a->map_x) * a->delta_x;
		}
		else
		{
			a->step_x = 1;
			a->side_x = (a->map_x + 1.0 - view->pos_x) * a->delta_x;
		}
		if (a->ray_y < 0)
		{
			a->step_y = -1;
			a->side_y = (view->pos_y - a->map_y) * a->delta_y;
		}
		else
		{
			a->step_y = 1;
			a->side_y = (a->map_y + 1.0 - view->pos_y) * a->delta_y;
		}
		//perform DDA
		while (a->hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (a->side_x < a->side_y)
			{
				a->side_x += a->delta_x;
				a->map_x += a->step_x;
				a->side = 0;
			}
			else
			{
				a->side_y += a->delta_y;
				a->map_y += a->step_y;
				a->side = 1;
			}
			//Check if ray has hit a wall
			if (all()->map[a->map_x][a->map_y] > '0')
				a->hit = 1;
		}
		//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
		if (a->side == 0)
			a->perp_dist = (a->side_x - a->delta_x);
		else
			a->perp_dist = (a->side_y - a->delta_y);

		//Calculate height of line to draw on screen
		a->ln_hgt = (int)(a->h / a->perp_dist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h) drawEnd = h - 1;
		//texturing calculations
		int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!

		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if (side == 0) wallX = posY + perpWallDist * rayDirY;
		else					 wallX = posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));

		//x coordinate on the texture
		int texX = int(wallX * double(texWidth));
		if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
		if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;

		// How much to increase the texture coordinate per screen pixel
		double step = 1.0 * texHeight / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - h / 2 + lineHeight / 2) * step;
		for(int y = drawStart; y<drawEnd; y++)
		{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		int texY = (int)texPos & (texHeight - 1);
		texPos += step;
		Uint32 color = texture[texNum][texWidth * texY + texX];
		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		if(side == 1) color = (color >> 1) & 8355711;
		buffer[y][x] = color;
		}
}
