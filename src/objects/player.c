/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:27 by rteles            #+#    #+#             */
/*   Updated: 2022/11/11 12:44:40 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

#define HAND 'H'

void	new_player(void)
{
	(player())->title = 'P';
	(player())->sprite = (canva())->sprite(HAND);
	(player())->pos[X] = (double)all()->player.x;
	(player())->pos[Y] = (double)all()->player.y;
	(player())->dir[X] = all()->caster.player.dir_x;
	(player())->dir[Y] = all()->caster.player.dir_y;
	(player())->vel = 0.1;
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
