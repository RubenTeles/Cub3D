/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_atack_breath.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:25:28 by rteles            #+#    #+#             */
/*   Updated: 2022/11/30 19:53:06 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_sound.h>
#include <ft_scenes_images.h>
#include <ft_keys.h>

static int	_breath_in_move(t_object *breath)
{
	int	colide_x;
	int	colide_y;

	colide_x = 0;
	colide_y = 0;
	if (!is_collision(breath, breath->pos[X] + (1 * (breath->vel * \
		breath->dir[X])), breath->pos[Y], 0))
	{
		colide_x = 1;
		breath->pos[X] += 1 * (breath->vel * \
		breath->dir[X]);
	}
	if (!is_collision(breath, breath->pos[X], breath->pos[Y] + \
		(1 * (breath->vel * breath->dir[Y])), 0))
	{
		colide_y = 1;
		breath->pos[Y] += 1 * (breath->vel * \
		breath->dir[Y]);
	}
	if (colide_x && colide_y)
		return (1);
	return (0);
}

static void	_breath_move(t_object *breath, int destroy_breath)
{
	destroy_breath = 0;
	if (breath->life - 10 > 0)
	{
		breath->life -= 13;
		_breath_in_move(breath);
	}
	else
		destroy_breath = 1;
	if (destroy_breath)
	{
		breath->avatar = 0;
		breath->sprite = 0;
		breath->prev->next = breath->next;
		if (breath->next)
			breath->next->prev = breath->prev;
		free(breath);
	}
}

int	ft_create_breath(t_object *breath)
{
	breath->avatar = (canva())->sprite(BREATH);
	breath->sprite = (canva())->sprite(BREATH);
	breath->life = (player())->atack_breath_life;
	breath->collision = 0;
	breath->interation = 0;
	breath->pos[X] = (player())->pos[X] - 0.5;
	breath->pos[Y] = (player())->pos[Y] - 0.5;
	breath->dir[X] = (player())->dir[X];
	breath->dir[Y] = (player())->dir[Y];
	breath->dimension[X] = 1;
	breath->dimension[Y] = 1;
	breath->dimension[2] = 100;
	breath->vel = 0.8;
	breath->move = 1;
	breath->is_move = _breath_move;
	return (1);
}
