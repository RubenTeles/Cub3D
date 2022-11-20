/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:11:30 by rteles            #+#    #+#             */
/*   Updated: 2022/11/19 19:16:24 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

void	ft_print_map(int sprite, double x, double y)
{
	t_data	*data;

	data = (canva())->sprite(sprite);
	if (sprite == (player())->sprite->title)
		data = (player())->avatar;
	if (!data)
		return ;
	if (data->title == MAP)
		(canva())->resize(data, (canva())->rsz[X], (canva())->rsz[Y], x, y);
	else if (data->title == (player())->avatar->title)
		(canva())->resize(data, (canva())->rsz[X] * 0.50, (canva())->rsz[Y] * 0.50,\
			((engine())->size[X] * 0.17) + (x * (canva())->rsz[X]) - (((canva())->rsz[Y] * 0.50) / 2),\
			((engine())->size[Y] * 0.25) + (y * (canva())->rsz[Y]) - (((canva())->rsz[Y] * 0.50) / 2));
	else
		(canva())->resize(data, (canva())->rsz[X], (canva())->rsz[Y],\
			((engine())->size[X] * 0.17) + (x * (canva())->rsz[X]),
			((engine())->size[Y] * 0.25) + (y * (canva())->rsz[Y]));
}

void	ft_map(void)
{
	t_object		*aux;
	static int		avatar = 0;

	aux = (engine())->object;
	avatar++;
	if ((player())->move > 0)
	{
		avatar = 8;
		(player())->move = 0;
	}
	else if (avatar >= 16)
		avatar = 0;
	(canva())->rsz[X] = (engine())->size[X] * 0.85;
	(canva())->rsz[Y] = (engine())->size[Y] * 0.85;
	ft_print_map(MAP, (engine())->size[X] - (engine())->size[X] * 0.94,\
		(engine())->size[Y] - (engine())->size[Y] * 0.94);
	(canva())->rsz[X] = (engine())->size[X] * 0.63 / (engine())->max[X];
	(canva())->rsz[Y] = (engine())->size[Y] * 0.80 / (engine())->max[X];
	ft_put_word("MAP", (engine())->size[X] * 0.15, (engine())->size[Y] *\
		0.05, (engine())->size[X] * 0.425, (engine())->size[Y] * 0.16);
	while (aux)
	{
		if (aux->title)
			ft_print_map(aux->title, aux->pos[X], aux->pos[Y]);
		aux = aux->next;
	}
	if (avatar >= 8)
		ft_print_map((player())->sprite->title, (player())->pos[X],\
			(player())->pos[Y]);
}
