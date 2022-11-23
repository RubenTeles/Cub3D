/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_raycasting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:32:15 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/23 01:00:33 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

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

	time = ft_convert_time((engine())->time);
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
					a.color = canva()->getPxColor(a.data[a.floortex], a.tx, a.ty);
					a.color = ft_grade_color(view, a.floorx, a.floory, a.color);
					ft_print_color(1, 1, a.x, a.y, a.color);
					a.color = canva()->getPxColor(a.data[a.c_tex], a.tx, a.ty);
					a.color = ft_grade_color(view, a.floorx, a.floory, a.color);
					ft_print_color(1, 1, a.x, a.h - a.y - 1, a.color);
				}
			}
		}
	}
}
