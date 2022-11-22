/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:27 by rteles            #+#    #+#             */
/*   Updated: 2022/11/22 16:46:45 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_sound.h>

static void	player_movement(int move_x, int move_y, int dir_x, int dir_y)
{
	if (!is_collision(0, (player())->pos[X] + (move_x * ((player())->vel *\
		(player())->dir[dir_x])), (player())->pos[Y]))
	{
		(player())->pos[X] += move_x * ((player())->vel * (player())->dir[dir_x]);
		all_interation(0, (player())->pos[X], (player())->pos[Y]);
	}
	if (!is_collision(0, (player())->pos[X], (player())->pos[Y] +\
		(move_y * ((player())->vel * (player())->dir[dir_y]))))
	{
		(player())->pos[Y] += move_y * ((player())->vel * (player())->dir[dir_y]);
		all_interation(0, (player())->pos[X], (player())->pos[Y]);
	}
}

static void	player_interation(void)
{
	t_object *obj;

	obj = is_interation(0, (player())->pos[X], (player())->pos[Y]);
	if (!obj)
		return ;
	if (obj->title == DOOR && obj->collision == 1)
	{
		obj->avatar = (canva())->sprite(DOOR_OPEN);
		obj->sprite = (canva())->sprite(DOOR_OPEN);
		obj->collision = 0;
		(engine())->sound->play(&(engine())->sound[SD_DOOR]);
	}
	else if (obj->title == DOOR && obj->collision == 0)
	{
		obj->avatar = (canva())->sprite(DOOR);
		obj->sprite = (canva())->sprite(DOOR);
		obj->collision = 1;
		(engine())->sound->play(&(engine())->sound[SD_DOOR]);
	}
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
	(player())->life = 1000;
	(player())->lives = 3;
	(player())->collision = 1;
	(player())->interation = 0.1;
	(player())->move = 0;
	(player())->fadigue = 100;
	(player())->atack = 0;
	(player())->movement = player_movement;
	(player())->obj_interation = player_interation;
}

t_player1	*player(void)
{
	static t_player1	p;

	return (&p);
}
