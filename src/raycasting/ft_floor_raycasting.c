/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_raycasting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:32:15 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/26 11:06:31 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

#define FLR "23dmM"

void	ft_floor_part1(t_alg_fl *b, t_view *view)
{
	t_alg_fl	a;

	a = *b;
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
	*b = a;
}

int	ft_grade_color(t_view *view, float x, float y, int color)
{
	double	grade;
	int		arr[2];
	float	time;

	time = ft_convert_time((engine())->time, 20);
	arr[0] = all()->fog_color;
	arr[1] = color;
	grade = ft_dist_pts(view->pos_x, view->pos_y, x, y);
	if (grade < 1)
		grade = 1;
	time *= (100.0 / (float)grade);
	if (time > 100.0F)
		time = 100.0F;
	return (ft_linear_gradient(arr, time));
}

void	ft_floor_print(t_view *view, t_alg_fl a)
{
	a.flrtex = 8;
	a.c_tex = 7 + (all()->map[a.celly][a.cellx] == '3');
	a.tx = (int)(a.data[a.flrtex]->larg * (a.floorx - a.cellx));
	a.ty = (int)(a.data[a.flrtex]->alt * (a.floory - a.celly));
	a.color = canva()->getPxColor(a.data[a.flrtex], a.tx, a.ty);
	a.color = ft_grade_color(view, a.floorx, a.floory, a.color);
	ft_print_color(1, 1, a.x, a.y, a.color);
	a.color = canva()->getPxColor(a.data[a.c_tex], a.tx, a.ty);
	a.color = ft_grade_color(view, a.floorx, a.floory, a.color);
	ft_print_color(1, 1, a.x, a.h - a.y - 1, a.color);
}

void	ft_ray_floor(t_view *view, t_alg_fl a)
{
	a.h = canva()->data->alt;
	a.w = canva()->data->larg;
	a.y = -1;
	while (++(a.y) < a.h)
	{
		ft_floor_part1(&a, view);
		a.x = -1;
		while (++(a.x) < a.w)
		{
			a.cellx = (int)(a.floorx);
			a.celly = (int)(a.floory);
			if (a.cellx <= 0 || a.celly <= 0)
				;
			else if (a.celly >= array().len(all()->map))
				;
			else if (a.cellx < string().len(all()->map[a.celly]) && a.p >= 0)
			{
				if (string().index_char(FLR, all()->map[a.celly][a.cellx]) >= 0)
					ft_floor_print(view, a);
			}
			a.floorx += a.stepx;
			a.floory += a.stepy;
		}
	}
}
