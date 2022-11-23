/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:00:10 by rteles            #+#    #+#             */
/*   Updated: 2022/11/22 18:05:46 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

void	ft_time(void)
{
	ft_print_color((engine())->size[X] * 0.112, (engine())->size[Y] * 0.086,\
		(engine())->size[X] * 0.461, (engine())->size[Y] * 0.010, 0X6b4324);
	ft_print_color((engine())->size[X] * 0.105, (engine())->size[Y] * 0.074,\
		(engine())->size[X] * 0.464, (engine())->size[Y] * 0.017, 0xe6be7e);
	ft_put_word((string()).itoa((engine())->time),\
	(engine())->size[X] * 0.05, (engine())->size[Y] * 0.05,\
	(engine())->size[X] * 0.491, (engine())->size[Y] * 0.030);
}

void	ft_put_minimap(int x, int y, double larg, double alt)
{
	t_object	*aux;
	double		board_x;
	double		board_y;

	board_x = 0;
	if (((player())->pos[X] - x) > 0)
		board_x = ((player())->pos[X] - x);
	board_y = 0;
	if (((player())->pos[Y] - y) > 0)
		board_y = ((player())->pos[Y] - y);
	(canva())->rsz[X] = (engine())->size[X] * 0.221 / 20;
	(canva())->rsz[Y] = (engine())->size[Y] * 0.174 / 16;
	aux = (engine())->object;
	while (aux)
	{
		if (aux->pos[X] >= (player())->pos[X] - x && aux->pos[X] <= (player())->pos[X] + x &&\
			aux->pos[Y] >= (player())->pos[Y] - y && aux->pos[Y] <= (player())->pos[Y] + y)
			if (aux->avatar)
				(canva())->resize(aux->avatar, (engine())->size[X] * 0.020, (engine())->size[Y] * 0.018,\
				larg + ((aux->pos[X] - board_x) * (canva())->rsz[X]),
				alt + ((aux->pos[Y] - board_y) * (canva())->rsz[Y]));
		aux = aux->next;
	}
	(canva())->resize((player())->avatar, (engine())->size[X] * 0.020, (engine())->size[Y] * 0.018,\
	larg + (((player())->pos[X] - board_x) * (canva())->rsz[X]),\
	alt + (((player())->pos[Y] - board_y) * (canva())->rsz[Y]));	
}

void	ft_minimap(t_scene_img *scene)
{
	t_data		*data;

	(void)scene;
	data = (canva())->sprite(MINIMAP);
	if (!data)
		return ;
	ft_print_color((engine())->size[X] * 0.221, (engine())->size[Y] * 0.174,\
		 (engine())->size[X] * 0.741, (engine())->size[Y] * 0.086, 0xe6be7e);
	ft_put_minimap(10, 8, (canva())->data->larg * 0.745,\
		(canva())->data->alt * 0.09);
	(canva())->resize(data, (engine())->size[X] * 0.30, (engine())->size[Y] *\
		0.35, (engine())->size[X] * 0.70, (engine())->size[Y] * 0.00);
	ft_put_word("MINI MAP", (engine())->size[X] * 0.15, (engine())->size[Y] *\
		0.04, (engine())->size[X] * 0.775, (engine())->size[Y] * 0.26);
	ft_time();
}