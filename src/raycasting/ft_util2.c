/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:11:21 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/28 18:25:17 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>
#include <ft_raycaster.h>

t_spr	*ft_setup_sprites(t_object *objs)
{
	t_spr	*sprites;
	int		len;
	int		i;

	len = ft_objects_len(objs);
	if (!len)
		return (NULL);
	sprites = malloc(sizeof(t_spr) * len);
	if (!sprites)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		sprites[i].len = len;
		sprites[i].texture = objs->sprite;
		sprites[i].x = objs->pos[0] + 0.5;
		sprites[i].y = objs->pos[1] + 0.5;
		ft_choose_spr_size(&sprites[i], objs);
		objs = objs->next;
	}
	return (sprites);
}

int	ft_return_tex_x(t_spr_vls	a, int i)
{
	return ((int)(256 * (a.stripe - (-a.sprite_wdt / 2 + a.sprite_scrn_x)) \
	* a.sprite[a.sprite_order[i]].texture->larg / a.sprite_wdt) / 256);
}

void	ft_color_strip_y(t_spr_vls a, t_view *view, int i)
{
	if (a.sprite[a.sprite_order[i]].texture)
	{
		a.tex_y = ((a.d * a.sprite[a.sprite_order[i]].texture->alt) \
			/ a.sprite_hgt) / 256;
		a.color = canva()->getPxColor(\
		a.sprite[a.sprite_order[i]].texture, a.tex_x, a.tex_y);
		if (a.color > 0)
			a.color = ft_grade_color(view, a.sprite[a.sprite_order[i]].x, \
			a.sprite[a.sprite_order[i]].y, a.color);
		if ((a.color & 0x00FFFFFF) != 0)
			(canva())->color(ft_aux(1, 1, a.stripe, a.y), a.color);
	}
}

float	ft_conv_t_block(int t, int t2, int n, int *past_value)
{
	if (t == n)
	{
		all()->fog_checker = (all()->fog_checker == 0);
		if (all()->fog_checker)
			return ((float)t);
		*past_value = t2;
		return ((float)t2);
	}
	if (all()->fog_checker)
	{
		*past_value = t2;
		return ((float)t2);
	}
	return (0.0F);
}
