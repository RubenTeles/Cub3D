/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie_bull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:25:28 by rteles            #+#    #+#             */
/*   Updated: 2022/11/29 19:30:08 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_sound.h>
#include <ft_scenes_images.h>
#include <ft_keys.h>

static void	_player_near_bull(t_object *bull, int key)
{
	(void)key;
	bull->move = bull->is_near;
	if (!bull->is_near && bull->sprite)
		bull->sprite = (canva())->sprite(BULL);
}

static void	_interation_bull(t_object *bull, int key)
{
	(void)key;
	(void)bull;
}

static void	_is_atacked_bull(t_object *bull, int damage)
{
	double		d_x;
	double		d_y;

	bull->life -= damage;
	(engine())->sound->play(&(engine())->sound[SD_PIG_ATACKED]);
	d_x = (bull->pos[X] > player()->pos[X]) - (bull->pos[X] < player()->pos[X]);
	d_y = (bull->pos[Y] > player()->pos[Y]) - (bull->pos[Y] < player()->pos[Y]);
	if (!bull->is_collision(bull, bull->pos[X] + (d_x * bull->vel * 2) + 0.5, \
	bull->pos[Y] + 0.5, 0))
		bull->pos[X] += (d_x * bull->vel * 2);
	if (!bull->is_collision(bull, bull->pos[X] + 0.5, \
	bull->pos[Y] + (d_y * bull->vel * 2) + 0.5, 0))
		bull->pos[Y] += (d_y * bull->vel * 2);
	if (bull->life <= 0)
	{
		bull->move = 0;
		bull->avatar = 0;
		bull->sprite = 0;
		bull->interation = 0;
		bull->collision = 0;
		bull->life = 0;
		bull->is_near = 0;
		(engine())->sound->play(&(engine())->sound[SD_PIG_DIED]);
	}
}

static void	_bull_move(t_object *bull, int move_x)
{
	static int	i = -1;
	double		d_x;
	double		d_y;
	int			move_y;

	move_y = 0;
	d_x = (bull->pos[X] < player()->pos[X]) - (bull->pos[X] > player()->pos[X]);
	d_y = (bull->pos[Y] < player()->pos[Y]) - (bull->pos[Y] > player()->pos[Y]);
	if (!bull->is_collision(bull, bull->pos[X] + (d_x * bull->vel) + 0.5, \
	bull->pos[Y] + 0.5, 0) && ++move_x)
		bull->pos[X] += (d_x * bull->vel);
	if (!bull->is_collision(bull, bull->pos[X] + 0.5, \
	bull->pos[Y] + (d_y * bull->vel) + 0.5, 0) && ++move_y)
		bull->pos[Y] += (d_y * bull->vel);
	if (move_y || move_x)
	{
		//(engine())->sound->play(&(engine())->sound[SD_bull_RUN]);
		bull->sprite = (canva())->sprite(BULL_1 + i++);
		if (i > 3)
			i = 0;
	}
	else if (bull->sprite)
		bull->sprite = (canva())->sprite(BULL);
	if (i == 0)
		_player_near_bull(bull, 0);
}

int	ft_create_bull(t_object *bull)
{
	bull->avatar = (canva())->sprite(BULL);
	bull->sprite = (canva())->sprite(BULL);
	bull->life = 200;
	bull->collision = 1;
	bull->interation = 5;
	bull->dimension[X] = 1;
	bull->dimension[Y] = 1;
	bull->dimension[2] = 100;
	bull->vel = 0.2;
	bull->player_interation = _interation_bull;
	bull->player_near = _player_near_bull;
	bull->is_atack = _is_atacked_bull;
	bull->is_move = _bull_move;
	return (1);
}
