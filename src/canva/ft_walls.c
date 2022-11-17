/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:07:47 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/17 11:16:34 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

// #define N_WALL 'N'
// #define S_WALL 'S'
// #define W_WALL 'W'
// #define E_WALL 'E'
// #define HAY '#'

double	ft_abs(double x)
{
	if (x < (double)0)
		return (x * (double)-1);
	return (x);
}

void	ft_rotate_dir(double a)
{
	double	dir_x;
	double	dir_y;

	dir_x = all()->caster.player.dir_x;
	dir_y = all()->caster.player.dir_y;
	all()->caster.player.dir_x = dir_x * cos(a) - dir_y * sin(a);
	all()->caster.player.dir_y = dir_x * sin(a) + dir_y * cos(a);
}

void	ft_set_camera(void)
{
	char	dir;

	all()->caster.player.pos_x = (player())->pos[X];
	all()->caster.player.pos_y = (player())->pos[Y];
	if (all()->caster.player.dir_x == 0 && all()->caster.player.dir_y == 0)
	{
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
			all()->caster.player.dir_y = -1;
		if (dir == 'S')
			all()->caster.player.dir_y = 1;
	}
}

void	ft_calc_plane(void)
{
	all()->caster.view.plane_x = all()->caster.player.dir_y;
	all()->caster.view.plane_y = all()->caster.player.dir_x * (double)-1;
	all()->caster.view.plane_x *= -(player())->vision;
	all()->caster.view.plane_y *= -(player())->vision;
	all()->caster.view.dir_x = all()->caster.player.dir_x;
	all()->caster.view.dir_y = all()->caster.player.dir_y;
	all()->caster.view.pos_x = all()->caster.player.pos_x;
	all()->caster.view.pos_y = all()->caster.player.pos_y;
	player()->dir[X] = all()->caster.player.dir_x;
	player()->dir[Y] = all()->caster.player.dir_y;
}

void	ft_floor(t_view *view, t_alg_fl a)
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
				if ((all()->map[(int)a.floory][(int)a.floorx] == '3' || all()->map[(int)a.floory][(int)a.floorx] == '4') && a.p >= 0)
				{
					a.color = canva()->getPxColor(a.data[a.floortex], a.tx, a.ty);
					a.color = (a.color >> 1) & 8355711;
					ft_print_color(1, 1, a.x, a.y, a.color);
					a.color = canva()->getPxColor(a.data[a.c_tex], a.tx, a.ty);
					a.color = (a.color >> 1) & 8355711;
					ft_print_color(1, 1, a.x, a.h - a.y - 1, a.color);
				}
			}
		}
	}
}

void	ft_ray(int x, t_view *view, t_data **data, int hit)
{
	t_alg	a;

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
		if (all()->map[a.map_y][a.map_x] == '4' && hit)
			a.hit = 0;
		if (all()->map[a.map_y][a.map_x] == '4' && !hit)
			ft_ray(x, view, data, 1);
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
	a.texnum = all()->map[a.map_y][a.map_x] - 49;
	if (a.texnum == 0)
	{
		if (a.side == 1 && a.map_y > view->pos_y)
			a.texnum = 1;
		else if (a.side == 0 && a.map_x > view->pos_x)
			a.texnum = 3;
		else if (a.side == 0 && a.map_x < view->pos_x)
			a.texnum = 2;
		else if (a.side == 0 && view->dir_x == 0 && a.map_x > view->pos_x)
			a.texnum = 3;
		else if (a.side == 0 && view->dir_x == 0)
			a.texnum = 2;
	}
	else
		a.texnum += 3;
	if (a.side == 0)
		a.wall_x = view->pos_y + a.perp_dist * a.ray_y;
	else
		a.wall_x = view->pos_x + a.perp_dist * a.ray_x;
	a.wall_x -= floor(a.wall_x);
	a.tex_x = (int)(a.wall_x * (double)(data[a.texnum]->larg));
	if (a.side == 0 && a.ray_x > 0)
		a.tex_x = data[a.texnum]->larg - a.tex_x - 1;
	if (a.side == 1 && a.ray_y < 0)
		a.tex_x = data[a.texnum]->larg - a.tex_x - 1;
	a.step = 1.0 * data[a.texnum]->alt / a.ln_hgt;
	a.texpos = (a.draw_str - canva()->data->alt / 2 + a.ln_hgt / 2) * a.step;
	a.y = a.draw_str - 1;
	while (++(a.y) < a.draw_end)
	{
		a.tex_y = (int)a.texpos;
		a.texpos += a.step;
		a.color = canva()->getPxColor(data[a.texnum], a.tex_x, a.tex_y);
		if (a.side == 1 || a.texnum <= 3)
			a.color = (a.color >> 1) & 8355711;
		ft_print_color(1, 1, x, a.y, a.color);
	}
}

void	ft_walls(void)
{
	t_data		*data[7];
	t_view		*view;
	int			x;
	t_alg_fl	b;

	data[0] = (canva())->sprite(N_WALL);
	data[1] = (canva())->sprite(S_WALL);
	data[2] = (canva())->sprite(W_WALL);
	data[3] = (canva())->sprite(E_WALL);
	data[4] = (canva())->sprite(HAY);
	data[5] = (canva())->sprite(WOOD_FLOOR);
	data[6] = (canva())->sprite(DOOR);
	if (!data[2] || !data[1] || !data[2] || !data[3] || !data[4] || !data[5] || !data[6])
		return ;
	if ((player())->pos[X] < 0 || (player())->pos[Y] < 0)
		return ;
	ft_set_camera();
	ft_calc_plane();
	view = &(all()->caster.view);
	b.data = data;
	ft_floor(view, b);
	x = -1;
	while (++x < canva()->data->larg)
		ft_ray(x, view, data, 0);
}
