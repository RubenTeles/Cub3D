/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:11:30 by rteles            #+#    #+#             */
/*   Updated: 2022/11/27 12:23:24 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

void	ft_print_map(t_data *data, double x, double y)
{
	if (!data)
		return ;
	if (data->title == MAP)
		(canva())->resize(data, (engine())->size[X], (canva())->rsz[Y], x, y);
	else if (data->title == (player())->avatar->title)
		(canva())->resize(data, (canva())->rsz[X] * 1.3, (canva())->rsz[Y] * \
			1, ((engine())->size[X] * 0.17) + (x * (canva())->rsz[X]) - \
			(((canva())->rsz[Y] * 0.50) / 2), ((engine())->size[Y] * 0.29) + \
			(y * (canva())->rsz[Y]) - (((canva())->rsz[Y] * 0.50) / 2));
	else
		(canva())->resize(data, (canva())->rsz[X], (canva())->rsz[Y], \
			((engine())->size[X] * 0.17) + (x * (canva())->rsz[X]),
			((engine())->size[Y] * 0.29) + (y * (canva())->rsz[Y]));
}

void	ft_map_2(t_object *aux)
{
	while (aux)
	{
		if (aux->avatar)
			ft_print_map(aux->avatar, aux->pos[X], aux->pos[Y]);
		aux = aux->next;
	}
}

void	ft_map(t_scene_img *scene)
{
	static int		avatar = 0;

	(void)scene;
	avatar++;
	if ((player())->move > 0)
	{
		avatar = 8;
		(player())->move = 0;
	}
	else if (avatar >= 16)
		avatar = 0;
	(canva())->rsz[Y] = (engine())->size[Y] * 0.85;
	ft_print_map((canva())->sprite(MAP), 0, (engine())->size[Y] * 0.12);
	(canva())->rsz[X] = (engine())->size[X] * 0.66 / (engine())->max[X];
	(canva())->rsz[Y] = (engine())->size[Y] * 0.58 / (engine())->max[Y];
	ft_put_word("MAP", (engine())->size[X] * 0.15, \
	(engine())->size[Y] * 0.05, (engine())->size[X] * 0.425, \
	(engine())->size[Y] * 0.22);
	ft_map_2((engine()->object));
	ft_map_2((engine()->enemies));
	if (avatar >= 8)
		ft_print_map((player())->avatar, (player())->pos[X], \
			(player())->pos[Y]);
}
