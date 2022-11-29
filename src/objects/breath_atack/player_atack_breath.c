/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_atack_breath.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:25:28 by rteles            #+#    #+#             */
/*   Updated: 2022/11/29 19:29:22 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_sound.h>
#include <ft_scenes_images.h>
#include <ft_keys.h>
/*
static void	_breath_move(t_object *atack, int move_x)
{
	static int	i = -1;
	double		d_x;
	double		d_y;
	int			move_y;

	move_y = 0;
	d_x = (player()->pos[X] * 2 < player()->pos[X]) - \
	(player()->pos[X] * 2 > player()->pos[X]);
	d_y = (atack->pos[Y] < player()->pos[Y]) - \
	(atack->pos[Y] > player()->pos[Y]);
	if (!atack->is_collision(atack, atack->pos[X] + (d_x * atack->vel) + 0.5, \
	atack->pos[Y] + 0.5, 0) && ++move_x)
		atack->pos[X] += (d_x * atack->vel);
	if (!atack->is_collision(atack, atack->pos[X] + 0.5, \
	atack->pos[Y] + (d_y * atack->vel) + 0.5, 0) && ++move_y)
		atack->pos[Y] += (d_y * atack->vel);
	if (move_y || move_x)
	{
		//(engine())->sound->play(&(engine())->sound[SD_atack_RUN]);
		atack->sprite = (canva())->sprite(atack_1 + i++);
		if (i > 3)
			i = 0;
	}
	else if (atack->sprite)
		atack->sprite = (canva())->sprite(atack);
	if (i == 0)
		_player_near_atack(atack, 0);
}

int	ft_create_breath(t_object *breath)
{
	breath->avatar = (canva())->sprite(breath);
	breath->sprite = (canva())->sprite(breath);
	breath->life = 200;
	breath->collision = 1;
	breath->interation = 5;
	breath->dimension[X] = 1;
	breath->dimension[Y] = 1;
	breath->dimension[2] = 100;
	breath->vel = 0.2;
	breath->player_interation = _interation_breath;
	breath->player_near = _player_near_breath;
	breath->is_atack = _is_atacked_breath;
	breath->is_move = _breath_move;
	return (1);
}
*/