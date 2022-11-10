/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:07:47 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/10 21:19:34 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>

#define N_WALL 'N'
#define S_WALL 'S'
#define W_WALL 'W'
#define E_WALL 'E'

double	ft_abs(double x)
{
	if (x < (double)0)
		return (x * (double)-1);
	return (x);
}

void	ft_set_camera(void)
{
	char	dir;
	//int		mem;

	all()->player = ft_player_pos(all()->file->map);
	//mem = all()->player.x;
	all()->player.x = (player())->pos[X];//all()->player.y;
	all()->player.y = (player())->pos[Y];//mem;
	all()->caster.player.pos_x = (double)all()->player.x;
	all()->caster.player.pos_y = (double)all()->player.y;
	dir = all()->map[all()->player.y][all()->player.x];
	all()->map[all()->player.y][all()->player.x] = '0';
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
	all()->caster.view.plane_y = all()->caster.player.dir_x * (double)-1;
	if (ft_abs(all()->caster.view.plane_x) == (double)1)
		all()->caster.view.plane_x *= 0.66;
	if (ft_abs(all()->caster.view.plane_y) == (double)1)
		all()->caster.view.plane_y *= 0.66;
	all()->caster.view.dir_x = all()->caster.player.dir_x;
	all()->caster.view.dir_y = all()->caster.player.dir_y;
	all()->caster.view.pos_x = all()->caster.player.pos_x;
	all()->caster.view.pos_y = all()->caster.player.pos_y;
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
	a->x = -1;
	a->h = canva()->data->alt;
	a->w = canva()->data->larg;
	a->tex_hgt = data[0]->alt;
	a->tex_wdh = data[0]->larg;
	while (++(a->x) < a->w)
	{
		a->cam_x = 2 * a->x / (double)(a->w) - 1;
		a->ray_x = view->dir_x + view->plane_x * a->cam_x;
		a->ray_y = view->dir_y + view->plane_y * a->cam_x;
		a->map_x = (int)(view->pos_x);
		a->map_y = (int)(view->pos_y);
		if (a->ray_x == 0)
			a->delta_x = 1e30;
		else
			a->delta_x = ft_abs(1 / a->ray_x);
		if (a->ray_y == 0)
			a->delta_y = 1e30;
		else
			a->delta_y = ft_abs(1 / a->ray_y);
		a->hit = 0;
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
		while (a->hit == 0)
		{
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
			if (all()->map[a->map_y][a->map_x] > '0')
				a->hit = 1;
		}
		if (a->side == 0)
			a->perp_dist = (a->side_x - a->delta_x);
		else
			a->perp_dist = (a->side_y - a->delta_y);
		a->ln_hgt = (int)(a->h / a->perp_dist);
		a->draw_str = -a->ln_hgt / 2 + a->h / 2;
		if (a->draw_str < 0)
			a->draw_str = 0;
		a->draw_end = a->ln_hgt / 2 + a->h / 2;
		if (a->draw_end >= a->h)
			a->draw_end = a->h - 1;
		a->texnum = all()->map[a->map_y][a->map_x] - 1;
		if (a->side == 0)
			a->wall_x = view->pos_y + a->perp_dist * a->ray_y;
		else
			a->wall_x = view->pos_x + a->perp_dist * a->ray_x;
		a->wall_x -= floor(a->wall_x);
		a->tex_x = (int)(a->wall_x * (double)(a->tex_wdh));
		if (a->side == 0 && a->ray_x > 0)
			a->tex_x = a->tex_wdh - a->tex_x - 1;
		if (a->side == 1 && a->ray_y < 0)
			a->tex_x = a->tex_wdh - a->tex_x - 1;
		a->step = 1.0 * a->tex_hgt / a->ln_hgt;
		a->texpos = (a->draw_str - a->h / 2 + a->ln_hgt / 2) * a->step;
		a->y = a->draw_str - 1;
		while (++(a->y) < a->draw_end)
		{
			a->tex_y = ((int)(a->texpos)) & (data[0]->alt - 1);
			a->texpos += a->step;
			// a->color = canva()->getPxColor(data[0], a->x, a->y);
			// printf("x: %i, y: %i\n", );
			a->color = canva()->getPxColor(data[0], a->x, a->y);
			// a->color = 12324;
			// printf("x: %i, y:%i\n", a->tex_x, a->tex_y);
			// printf("color: %i\n", a->color);
			// color = data[a->texnum]->addr[data[0]->larg * a->tex_y + a->tex_x];
			if (a->side == 1)
				a->color = (a->color >> 1) & 8355711;
			// printf("x: %i, y: %i\n", a->tex_x, a->tex_y);
			ft_print_color(1, 1, a->x, a->y, a->color);
			//a->buffer[a->y][a->x] = color;
		}
	}
}

// void	ft_walls1(void)
// {
	
// }
