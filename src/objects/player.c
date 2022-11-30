/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:27 by rteles            #+#    #+#             */
/*   Updated: 2022/11/30 00:18:12 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_sound.h>
#include <ft_scenes.h>
#include <ft_scenes_images.h>

static void	player_movement(int move_x, int move_y, int dir_x, int dir_y)
{
	if (!is_collision(0, (player())->pos[X] + (move_x * ((player())->vel * \
		(player())->dir[dir_x])), (player())->pos[Y], 0))
	{
		(player())->pos[X] += move_x * ((player())->vel * \
		(player())->dir[dir_x]);
		all_interation((engine())->object, (player())->pos[X], \
		(player())->pos[Y], 1);
	}
	if (!is_collision(0, (player())->pos[X], (player())->pos[Y] + \
		(move_y * ((player())->vel * (player())->dir[dir_y])), 0))
	{
		(player())->pos[Y] += move_y * ((player())->vel * \
		(player())->dir[dir_y]);
		all_interation((engine())->object, (player())->pos[X], \
		(player())->pos[Y], 0);
	}
}

static int	_player_dead(void)
{
	(player())->life = 0;
	(engine())->start_pause = time_current();
	(engine())->pause = 1;
	if ((player())->lives - 1 >= 0)
	{
		(canva())->scene->complete = 1;
		(canva())->scene_img[S_YOU_DIE].on = 1;
		(player())->lives -= 1;
		(player())->life = 1000;
		(player())->fadigue = 100;
		(player())->pos[Y] = (double)all()->player.x + 0.5;
		(player())->pos[X] = (double)all()->player.y + 0.5;
		(player())->dir[X] = all()->caster.player.dir_x;
		(player())->dir[Y] = all()->caster.player.dir_y;
		(engine())->time = time_current();
		return (1);
	}
	(canva())->scene = &(canva())->scene_show[SC_END_GAME];
	(canva())->scene->init();
	return (1);
}

static void	player_interation(int key)
{
	is_interation((engine())->object, key);
	is_interation((engine())->enemies, key);
	player_interation_atack(key);
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
	(player())->interation = 0.2;
	(player())->move = 0;
	(player())->fadigue = 100;
	(player())->atack = 0;
	(player())->atack_breath_life = 0;
	(player())->movement = player_movement;
	(player())->obj_interation = player_interation;
	(player())->dead = _player_dead;
}

t_player1	*player(void)
{
	static t_player1	p;

	return (&p);
}
