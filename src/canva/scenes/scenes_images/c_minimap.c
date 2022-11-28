/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:00:10 by rteles            #+#    #+#             */
/*   Updated: 2022/11/28 19:18:44 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

void	ft_time(void)
{
	(canva())->color(ft_aux((engine())->size[X] * 0.112, (engine())->size[Y] * \
	0.086, (engine())->size[X] * 0.461, (engine())->size[Y] * 0.010), 0X6b4324);
	(canva())->color(ft_aux((engine())->size[X] * 0.105, (engine())->size[Y] * \
	0.074, (engine())->size[X] * 0.464, (engine())->size[Y] * 0.017), 0xe6be7e);
	(canva())->word((string()).itoa((engine())->time), ft_aux(\
	(engine())->size[X] * 0.05, (engine())->size[Y] * 0.05, \
	(engine())->size[X] * 0.491, (engine())->size[Y] * 0.030), 1);
}

void	ft_put_enimies(t_aux sz, t_object *aux, double board_x, double board_y)
{
	aux = (engine())->enemies;
	while (aux)
	{
		if (aux->pos[X] >= (player())->pos[X] - sz.x && \
		aux->pos[X] <= (player())->pos[X] + sz.x && \
		aux->pos[Y] >= (player())->pos[Y] - sz.y && \
		aux->pos[Y] <= (player())->pos[Y] + sz.y)
			if (aux->avatar)
				(canva())->resize(aux->avatar, ft_aux((engine())->size[X] * \
				0.020, (engine())->size[Y] * 0.018, sz.larg + ((aux->pos[X] - \
				board_x) * (canva())->rsz[X]),
				sz.alt + ((aux->pos[Y] - board_y) * (canva())->rsz[Y])));
		aux = aux->next;
	}
	(canva())->resize((player())->avatar, ft_aux((engine())->size[X] * 0.020, \
	(engine())->size[Y] * 0.018, sz.larg + (((player())->pos[X] - board_x) * \
	(canva())->rsz[X]), sz.alt + (((player())->pos[Y] - board_y) * \
	(canva())->rsz[Y])));
}

void	ft_put_minimap(t_aux sz, t_object *aux, double board_x, double board_y)
{
	if (((player())->pos[X] - sz.x) > 0)
		board_x = ((player())->pos[X] - sz.x);
	if (((player())->pos[Y] - sz.y) > 0)
		board_y = ((player())->pos[Y] - sz.y);
	(canva())->rsz[X] = (engine())->size[X] * 0.221 / 20;
	(canva())->rsz[Y] = (engine())->size[Y] * 0.174 / 16;
	aux = (engine())->object;
	while (aux)
	{
		if (aux->pos[X] >= (player())->pos[X] - sz.x && \
		aux->pos[X] <= (player())->pos[X] + sz.x && \
		aux->pos[Y] >= (player())->pos[Y] - sz.y && \
		aux->pos[Y] <= (player())->pos[Y] + sz.y)
			if (aux->avatar)
				(canva())->resize(aux->avatar, ft_aux((engine())->size[X] * \
				0.020, (engine())->size[Y] * 0.018, \
				sz.larg + ((aux->pos[X] - board_x) * (canva())->rsz[X]),
				sz.alt + ((aux->pos[Y] - board_y) * (canva())->rsz[Y])));
		aux = aux->next;
	}
	ft_put_enimies(sz, 0, board_x, board_y);
}

void	ft_minimap(t_scene_img *scene)
{
	t_data		*data;

	(void)scene;
	data = (canva())->sprite(MINIMAP);
	if (!data)
		return ;
	(canva())->color(ft_aux((engine())->size[X] * 0.221, (engine())->size[Y] * \
	0.174, (engine())->size[X] * 0.741, (engine())->size[Y] * 0.086), 0xe6be7e);
	ft_put_minimap(ft_aux((canva())->data->larg * 0.725, \
	(canva())->data->alt * 0.08, 11, 9), 0, 0, 0);
	(canva())->resize(data, ft_aux((engine())->size[X] * 0.30, \
	(engine())->size[Y] * 0.35, (engine())->size[X] * 0.70, \
	(engine())->size[Y] * 0.00));
	(canva())->word("MINI MAP", ft_aux((engine())->size[X] * 0.15, \
	(engine())->size[Y] * 0.04, (engine())->size[X] * 0.775, \
	(engine())->size[Y] * 0.26), 0);
	ft_time();
}
