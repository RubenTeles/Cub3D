/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:07:47 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/27 14:12:11 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

void	ft_ray(int x, t_view *view, t_data **data, t_alg a)
{
	// all()->pitch = 100.0;
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
	while (a.hit == 0)
	{
		a.check = (a.side_x < a.side_y);
		a.side = !a.check;
		a.side_x += a.delta_x * a.check;
		a.map_x += a.step_x * a.check;
		a.side_y += a.delta_y * !a.check;
		a.map_y += a.step_y * !a.check;
		if (string().index_char("1DMC", all()->map[a.map_y][a.map_x]) >= 0)
			a.hit = 1;
		if (string().index_char("dm", all()->map[a.map_y][a.map_x]) >= 0)
		{
			a.x = 1;
			ft_ray(x, view, data, a);
			a.hit = 1;
		}
	}
	if (a.side == 0)
		a.perp_dist = (a.side_x - a.delta_x);
	else
		a.perp_dist = (a.side_y - a.delta_y);
	a.ln_hgt = (int)(canva()->data->alt / a.perp_dist);
	a.draw_str = -a.ln_hgt / 2 + canva()->data->alt / 2 + all()->pitch;
	if (a.draw_str < 0)
		a.draw_str = 0;
	a.draw_end = a.ln_hgt / 2 + canva()->data->alt / 2 + all()->pitch;
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
	a.texpos = (a.draw_str - all()->pitch - canva()->data->alt / 2 + a.ln_hgt / 2) * a.step;
	a.y = a.draw_str - 1;
	while (++(a.y) < a.draw_end)
	{
		a.color = ft_get_ray_color(data[a.texnum], a.tex_x, (int)a.texpos, (a.side == 1 || a.texnum <= 3));
		a.texpos += a.step;
		a.color = ft_grade_color(view, (float)a.map_x, (float)a.map_y, a.color);
		(canva())->color(ft_aux(1, 1, x, a.y), a.color);
	}
	a.z_buffer[x] = a.perp_dist;
}

void	ft_raycasting(t_scene_img *scene)
{
	t_data		*data[10];
	t_spr		*sprites;
	t_alg		a;
	t_alg_fl	b;
	int			x;

	(void)scene;
	if (ft_setup_ray_imgs(data))
		return ;
	sprites = ft_setup_sprites((engine())->enemies);
	all()->data = data;
	ft_set_camera();
	ft_calc_plane();
	b.data = data;
	x = -1;
	a.x = 0;
	all()->pitch = 0.0;
	ft_ray_floor(&(all()->caster.view), b);
	a.z_buffer = malloc(sizeof(double) * canva()->data->larg);
	while (++x < canva()->data->larg)
		ft_ray(x, &(all()->caster.view), data, a);
	if (sprites)
		ft_ray_sprites(a.z_buffer, &(all()->caster.view), sprites);
	free(a.z_buffer);
}
