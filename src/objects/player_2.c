/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:27 by rteles            #+#    #+#             */
/*   Updated: 2022/11/29 23:37:34 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_sound.h>
#include <ft_keys.h>

static int	is_in_player_interation(double x, double y, double colision)
{
	int	x_vallid;
	int	y_vallid;

	x_vallid = 0;
	y_vallid = 0;
	if (x + colision >= ((player())->pos[X] - (player())->interation) && \
		x - colision <= ((player())->pos[X] - (player())->interation))
		x_vallid = 1;
	if (x + colision >= ((player())->pos[X] + (player())->interation) && \
		x - colision <= ((player())->pos[X] + (player())->interation))
		x_vallid = 1;
	if (y + colision >= ((player())->pos[Y] - (player())->interation) && \
		y - colision <= ((player())->pos[Y] - (player())->interation))
		y_vallid = 1;
	if (y + colision >= ((player())->pos[Y] + (player())->interation) && \
		y - colision <= ((player())->pos[Y] + (player())->interation))
		y_vallid = 1;
	if (y_vallid + x_vallid == 2)
		return (1);
	return (0);
}

void	player_interation_atack(int key)
{
	t_object	*aux;

	if (key != _BUTTON_LEFT)
		return ;
	aux = ((engine())->enemies);
	while (aux)
	{
		if (aux->is_near)
		{
			if (is_in_player_interation(aux->pos[X] + 0.5, \
				aux->pos[Y] + 0.5, 0.6))
				aux->is_atack(aux, 20);
		}
		aux = aux->next;
	}
}
