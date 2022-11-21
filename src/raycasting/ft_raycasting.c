/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:07:47 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/21 12:30:18 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

void	ft_ray_sprites(double *buffer, t_view *view, t_data **data, t_spr *sprite)
{
	t_spr_vls	a;
	int			i;

	i = -1;
	while (++i < NUMSPRITES)
	{
		a.sprite_order[i] = i;
		a.sprite_dist[i] = ((view->pos_x - sprite[i].x) * (view->pos_x - sprite[i].x) + (view->pos_x - sprite[i].y) * (view->pos_y - sprite[i].y)); //sqrt not taken, unneeded
	}
	// sortSprites(a.sprite_order, a.sprite_dist, NUMSPRITES);
	i = -1;
	while (++i < NUMSPRITES)
	{
		//translate sprite position to relative to camera
		a.sprite_x = sprite[a.sprite_order[i]].x - view->pos_x;
		a.sprite_y = sprite[a.sprite_order[i]].y - view->pos_y;

		//transform sprite with the inverse camera matrix
		// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
		// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
		// [ planeY   dirY ]                                          [ -planeY  planeX ]

		a.invdet = 1.0 / (view->plane_x * view->dir_y - view->dir_x * view->plane_y); //required for correct matrix multiplication

		a.transform_x = a.invdet * (view->dir_y * a.sprite_x - view->dir_x * a.sprite_y);
		a.transform_y = a.invdet * (-view->plane_y * a.sprite_x + view->plane_x * a.sprite_y); //this is actually the depth inside the screen, that what Z is in 3D

		a.sprite_scrn_x = (int)(((double)(canva()->data->larg) / 2) * (1 + a.transform_x / a.transform_y));

		//calculate height of the sprite on screen
		a.sprite_hgt = abs((int)((double)(canva()->data->alt) / (a.transform_y))); //using 'transformY' instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		a.draw_str_y = -a.sprite_hgt / 2 + canva()->data->alt / 2;
		if (a.draw_str_y < 0)
			a.draw_str_y = 0;
		a.draw_end_y = a.sprite_hgt / 2 + canva()->data->alt / 2;
		if (a.draw_end_y >= canva()->data->alt)
			a.draw_end_y = canva()->data->alt - 1;

		//calculate width of the sprite
		a.sprite_wdt = abs((int)((double)(canva()->data->alt) / (a.transform_y)));
		a.draw_str_x = -a.sprite_wdt / 2 + a.sprite_scrn_x;
		if (a.draw_str_x < 0)
			a.draw_str_x = 0;
		a.draw_end_x = a.sprite_wdt / 2 + a.sprite_scrn_x;
		if (a.draw_end_x >= canva()->data->larg)
			a.draw_end_x = canva()->data->larg - 1;

		//loop through every vertical stripe of the sprite on screen
		a.stripe = a.draw_str_x - 1;
		while (++(a.stripe) < a.draw_end_x)
		{
			a.tex_x = (int)(256 * (a.stripe - (-a.sprite_wdt / 2 + a.sprite_scrn_x)) * data[sprite[a.sprite_order[i]].texture]->alt / a.sprite_wdt) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if (a.transform_y > 0 && a.stripe > 0 && a.stripe < canva()->data->larg && a.transform_y < buffer[a.stripe])
			{
				a.y = a.draw_str_y - 1;
				while (++(a.y) < a.draw_end_y)
				{
					a.d = (a.y) * 256 - canva()->data->alt * 128 + a.sprite_hgt * 128; //256 and 128 factors to avoid floats
					a.tex_y = ((a.d * data[sprite[a.sprite_order[i]].texture]->alt) / a.sprite_hgt) / 256;
					a.color = canva()->getPxColor(data[sprite[a.sprite_order[i]].texture], a.tex_x, a.tex_y);
					if ((a.color & 0x00FFFFFF) != 0)
						ft_print_color(1, 1, a.stripe, a.y, a.color);
				}
			}
		}
	}
}

void	ft_ray_floor(t_view *view, t_alg_fl a)
{
	a.h = canva()->data->alt;
	a.w = canva()->data->larg;
	a.y = -1;
	while (++(a.y) < a.h)
	{
		a.ray_x0 = (float)(view->dir_x - view->plane_x);
		a.ray_y0 = (float)(view->dir_y - view->plane_y);
		a.ray_x1 = (float)(view->dir_x + view->plane_x);
		a.ray_y1 = (float)(view->dir_y + view->plane_y);
		a.p = a.y - a.h / 2;
		a.posz = 0.5 * (float)a.h;
		a.rowdist = a.posz / a.p;
		a.stepx = a.rowdist * (a.ray_x1 - a.ray_x0) / (float)a.w;
		a.stepy = a.rowdist * (a.ray_y1 - a.ray_y0) / (float)a.w;
		a.floorx = (float)view->pos_x + a.rowdist * a.ray_x0;
		a.floory = (float)view->pos_y + a.rowdist * a.ray_y0;
		a.x = -1;
		while (++(a.x) < a.w)
		{
			a.floortex = 5;
			a.c_tex = 5;
			a.cellx = (int)(a.floorx);
			a.celly = (int)(a.floory);
			a.tx = (int)(a.data[a.floortex]->larg * (a.floorx - a.cellx));
			a.ty = (int)(a.data[a.floortex]->alt * (a.floory - a.celly));
			a.floorx += a.stepx;
			a.floory += a.stepy;
			if(a.floorx > 0 && a.floory > 0 && (int)a.floory < array().len(all()->map) && (int)a.floorx < string().len(all()->map[(int)a.floory]))
			{
				if ((all()->map[(int)a.floory][(int)a.floorx] == '3' || all()->map[(int)a.floory][(int)a.floorx] == '4' || all()->map[(int)a.floory][(int)a.floorx] == '2') && a.p >= 0)
				{
					// double grade = ft_dist_pts(view->pos_x, view->pos_y, a.floorx, a.floory);
					// if (grade < 5)
					// 	grade = 5;
					// int	arr[2];
					// arr[0] = 11251376;
					a.color = canva()->getPxColor(a.data[a.floortex], a.tx, a.ty);
					// if (a.c_tex == 5)
					// {
					// 	arr[1] = a.color;
					// 	a.color = ft_linear_gradient(arr, 100.0 * 5 / (float)grade);
					// }
					ft_print_color(1, 1, a.x, a.y, a.color);
					
					a.color = canva()->getPxColor(a.data[a.c_tex], a.tx, a.ty);
					// if (a.c_tex == 5)
					// {
					// 	arr[1] = a.color;
					// 	a.color = ft_linear_gradient(arr, 100.0 * 5 / (float)grade);
					// }
					ft_print_color(1, 1, a.x, a.h - a.y - 1, a.color);
				}
			}
		}
	}
}

void	ft_ray(int x, t_view *view, t_data **data, t_alg a)
{
	if (a.x == 0)
	{	
		a.cam_x = 2 * x / (double)(canva()->data->larg) - 1;
		a.ray_x = view->dir_x + view->plane_x * a.cam_x;
		a.ray_y = view->dir_y + view->plane_y * a.cam_x;
		a.map_x = (int)(view->pos_x);
		a.map_y = (int)(view->pos_y);
		if (a.ray_x == 0)
			a.delta_x = 1e30;
		else
			a.delta_x = ft_abs(1 / a.ray_x);
		if (a.ray_y == 0)
			a.delta_y = 1e30;
		else
			a.delta_y = ft_abs(1 / a.ray_y);
		a.hit = 0;
		a.step_x = 1 - ((a.ray_x < 0) * 2);
		if (a.ray_x < 0)
			a.side_x = (view->pos_x - a.map_x) * a.delta_x;
		else
			a.side_x = (a.map_x + 1.0 - view->pos_x) * a.delta_x;
		a.step_y = 1 - ((a.ray_y < 0) * 2);
		if (a.ray_y < 0)
			a.side_y = (view->pos_y - a.map_y) * a.delta_y;
		else
			a.side_y = (a.map_y + 1.0 - view->pos_y) * a.delta_y;
	}
	else
	{
		while (all()->map[a.map_y][a.map_x] == '4')
		{
			a.check = (a.side_x < a.side_y);
			a.side = !a.check;
			a.side_x += a.delta_x * a.check;
			a.map_x += a.step_x * a.check;
			a.side_y += a.delta_y * !a.check;
			a.map_y += a.step_y * !a.check;
		}
	}
	while (a.hit == 0)
	{
		a.check = (a.side_x < a.side_y);
		a.side = !a.check;
		a.side_x += a.delta_x * a.check;
		a.map_x += a.step_x * a.check;
		a.side_y += a.delta_y * !a.check;
		a.map_y += a.step_y * !a.check;
		// if (a.map_x <= 0 || a.map_y <= 0 || a.map_y >= (array().len(all()->map) - 1) || a.map_x >= (string().len(all()->map[a.map_y]) - 1))
		// 	a.hit = 1;
		if (all()->map[a.map_y][a.map_x] > '0' && all()->map[a.map_y][a.map_x] != '3')
			a.hit = 1;
		if (all()->map[a.map_y][a.map_x] == '4')
		{
			a.x = 1;
			a.hit = 0;
			ft_ray(x, view, data, a);
			a.hit = 1;
		}
	}
	if (a.side == 0)
		a.perp_dist = (a.side_x - a.delta_x);
	else
		a.perp_dist = (a.side_y - a.delta_y);
	a.ln_hgt = (int)(canva()->data->alt / a.perp_dist);
	a.draw_str = -a.ln_hgt / 2 + canva()->data->alt / 2;
	if (a.draw_str < 0)
		a.draw_str = 0;
	a.draw_end = a.ln_hgt / 2 + canva()->data->alt / 2;
	if (a.draw_end >= canva()->data->alt)
		a.draw_end = canva()->data->alt - 1;
	a.texnum = ft_texture_num(a.map_x, a.map_y, a.side, *view);
	if (a.side == 0)
		a.wall_x = view->pos_y + a.perp_dist * a.ray_y;
	else
		a.wall_x = view->pos_x + a.perp_dist * a.ray_x;
	a.wall_x -= floor(a.wall_x);
	a.tex_x = (int)(a.wall_x * (double)(data[a.texnum]->larg));
	if ((a.side == 0 && a.ray_x > 0) || (a.side == 1 && a.ray_y < 0))
		a.tex_x = data[a.texnum]->larg - a.tex_x - 1;
	a.step = 1.0 * data[a.texnum]->alt / a.ln_hgt;
	a.texpos = (a.draw_str - canva()->data->alt / 2 + a.ln_hgt / 2) * a.step;
	a.y = a.draw_str - 1;
	while (++(a.y) < a.draw_end)
	{
		a.color = ft_get_ray_color(data[a.texnum], a.tex_x, (int)a.texpos, (a.side == 1 || a.texnum <= 3));
		a.texpos += a.step;
		// int	arr[2];
		// arr[0] = 11251376;
		// arr[1] = a.color;
		// double grade = ft_dist_pts(view->pos_x, view->pos_y, (double)a.map_x, (double)a.map_y);
		// if (grade < 5)
		// 	grade = 5;
		// a.color = ft_linear_gradient(arr, 100.0 * 5 / (float)grade);
		ft_print_color(1, 1, x, a.y, a.color);
	}
	a.z_buffer[x] = a.perp_dist;
}

void	ft_raycasting(void)
{
	t_data		*data[9];
	t_spr		sprite[2];
	t_view		*view;
	int			x;
	t_alg_fl	b;
	t_alg		a;

	data[0] = (canva())->sprite(N_WALL);
	data[1] = (canva())->sprite(S_WALL);
	data[2] = (canva())->sprite(W_WALL);
	data[3] = (canva())->sprite(E_WALL);
	data[4] = (canva())->sprite(HAY);
	data[5] = (canva())->sprite(CAVE);
	data[6] = (canva())->sprite(WINDOW);
	data[7] = (canva())->sprite(DOOR);
	data[8] = (canva())->sprite(CAVE);
	if (!data[2] || !data[1] || !data[2] || !data[3] || !data[4] || !data[5] || !data[6]\
		|| !data[7] || !data[8])
		return ;
	sprite[0].texture = 6;
	sprite[0].x = 10;
	sprite[0].y = 10;
	sprite[1].texture = 6;
	sprite[1].x = 20;
	sprite[1].y = 10;
	all()->data = data;
	if ((player())->pos[X] < 0 || (player())->pos[Y] < 0)
		return ;
	ft_set_camera();
	ft_calc_plane();
	view = &(all()->caster.view);
	b.data = data;
	x = -1;
	a.x = 0;
	ft_ray_floor(view, b);
	a.z_buffer = malloc(sizeof(double) * canva()->data->larg);
	while (++x < canva()->data->larg)
		ft_ray(x, view, data, a);
	ft_ray_sprites(a.z_buffer, view, data, sprite);
	free(a.z_buffer);
}
