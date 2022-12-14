/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:16:14 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/28 16:42:43 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

void	ft_sort_sprites(int *order, double *dist, int amount)
{
	int	check;
	int	i;

	if (amount < 2)
		return ;
	check = 1;
	while (check == 1)
	{
		check = 0;
		i = -1;
		while (++i < amount - 1)
		{
			if (dist[order[i]] < dist[order[i + 1]])
			{
				check = order[i];
				order[i] = order[i + 1];
				order[i + 1] = check;
				check = 1;
			}
		}
	}
}

void	ft_print_stripe(t_spr_vls *copy, int i, int vmovescreen, t_view *view)
{
	t_spr_vls	a;

	a.tex_x = 0;
	a.tex_y = 0;
	a = *copy;
	if (a.sprite[a.sprite_order[i]].texture)
		a.tex_x = ft_return_tex_x(a, i);
	if (a.transform_y > 0 && a.stripe > 0 && a.stripe < canva()->data->larg && \
	a.transform_y < a.buffer[a.stripe])
	{
		a.y = a.draw_str_y - 1;
		while (++(a.y) < a.draw_end_y)
		{
			a.d = (a.y - vmovescreen) * 256 - canva()->data->alt * 128 + \
			a.sprite_hgt * 128;
			ft_color_strip_y(a, view, i);
		}
	}
	*copy = a;
}

int	ft_spr_part1(t_spr_vls *b, t_view *view, int i, t_spr *sprite)
{
	t_spr_vls	a;

	a = *b;
	a.sprite_x = sprite[a.sprite_order[i]].x - view->pos_x;
	a.sprite_y = sprite[a.sprite_order[i]].y - view->pos_y;
	a.invdet = 1.0 / (view->plane_x * view->dir_y - view->dir_x * \
	view->plane_y);
	a.transform_x = a.invdet * (view->dir_y * a.sprite_x - view->dir_x * \
	a.sprite_y);
	a.transform_y = a.invdet * (-view->plane_y * a.sprite_x + \
	view->plane_x * a.sprite_y);
	*b = a;
	return ((int)(sprite[a.sprite_order[i]].vmove / a.transform_y));
}

void	ft_spr_part2(t_spr_vls *b, int vms, double *buffer, t_spr *sprite)
{
	t_spr_vls	a;

	a = *b;
	a.sprite_scrn_x = (int)(((double)(canva()->data->larg) / 2) * (1 + \
	a.transform_x / a.transform_y));
	a.sprite_hgt = abs((int)((double)(canva()->data->alt) / \
	(a.transform_y))) / sprite[a.sprite_order[a.i]].vdiv;
	a.draw_str_y = -a.sprite_hgt / 2 + canva()->data->alt / 2 + vms;
	if (a.draw_str_y < 0)
		a.draw_str_y = 0;
	a.draw_end_y = a.sprite_hgt / 2 + canva()->data->alt / 2 + vms;
	if (a.draw_end_y >= canva()->data->alt)
		a.draw_end_y = canva()->data->alt - 1;
	a.sprite_wdt = abs((int)((double)(canva()->data->alt) / (a.transform_y))) \
	/ sprite[a.sprite_order[a.i]].udiv;
	a.draw_str_x = -a.sprite_wdt / 2 + a.sprite_scrn_x;
	if (a.draw_str_x < 0)
		a.draw_str_x = 0;
	a.draw_end_x = a.sprite_wdt / 2 + a.sprite_scrn_x;
	if (a.draw_end_x >= canva()->data->larg)
		a.draw_end_x = canva()->data->larg - 1;
	a.stripe = a.draw_str_x - 1;
	a.buffer = buffer;
	a.sprite = sprite;
	*b = a;
}

void	ft_ray_sprites(double *buffer, t_view *view, t_spr *spr)
{
	t_spr_vls	a;
	int			i;
	int			vmovescreen;

	i = -1;
	while (++i < spr->len)
	{
		a.sprite_order[i] = i;
		a.sprite_dist[i] = ((view->pos_x - spr[i].x) * \
		(view->pos_x - spr[i].x) + (view->pos_x - \
		spr[i].y) * (view->pos_y - spr[i].y));
	}
	ft_sort_sprites(a.sprite_order, a.sprite_dist, spr->len);
	i = -1;
	while (++i < spr->len)
	{
		a.i = i;
		vmovescreen = ft_spr_part1(&a, view, i, spr);
		ft_spr_part2(&a, vmovescreen, buffer, spr);
		while (++(a.stripe) < a.draw_end_x)
			ft_print_stripe(&a, i, vmovescreen, view);
	}
	free(spr);
}
