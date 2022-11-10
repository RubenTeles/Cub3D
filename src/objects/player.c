/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:27 by rteles            #+#    #+#             */
/*   Updated: 2022/11/10 20:15:50 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

#define HAND 'H'

void	new_player(void)
{
	(player())->title = 'P';
	(player())->sprite = (canva())->sprite(HAND);
	(player())->pos[X] = all()->player.x;
	(player())->pos[Y] = all()->player.y;
	(player())->dir[X] = all()->caster.player.pos_x;
	(player())->dir[Y] = all()->caster.player.pos_y;
	(player())->key = 'W';
	(player())->move = 0;
	(player())->life = 100;
	(player())->lives = 3;
}

t_player1	*player(void)
{
	static t_player1	p;

	return (&p);
}
