/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:27 by rteles            #+#    #+#             */
/*   Updated: 2022/11/20 16:03:55 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

static void	player_movement(int move_x, int move_y, int dir_x, int dir_y)
{
	if (!is_collision(0,\
		(player())->pos[X] +\
		(move_x * ((player())->vel * (player())->dir[dir_x])),\
		(player())->pos[Y]))
		(player())->pos[X] += move_x * ((player())->vel * (player())->dir[dir_x]);
	if (!is_collision(0,\
		(player())->pos[X],\
		(player())->pos[Y] +\
		(move_y * ((player())->vel * (player())->dir[dir_y]))))
		(player())->pos[Y] += move_y * ((player())->vel * (player())->dir[dir_y]);
}

void	new_player(void)
{
	(player())->title = 'P';
	(player())->avatar = (canva())->sprite(AVATAR);
	(player())->sprite = (canva())->sprite(HAND);
	(player())->pos[Y] = (double)all()->player.x + 0.5;
	(player())->pos[X] = (double)all()->player.y + 0.5;
	(player())->dir[X] = all()->caster.player.dir_x;
	(player())->dir[Y] = all()->caster.player.dir_y;
	(player())->vel = 0.10;
	(player())->turn = 0.05;
	(player())->turn_times = 0;
	(player())->vision = 0.66;
	(player())->move = 0;
	(player())->fadigue = 100;
	(player())->life = 1000;
	(player())->lives = 3;
	(player())->movement = player_movement;
}

t_player1	*player(void)
{
	static t_player1	p;

	return (&p);
}
