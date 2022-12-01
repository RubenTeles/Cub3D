/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie_pig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:25:28 by rteles            #+#    #+#             */
/*   Updated: 2022/12/01 18:38:52 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_sound.h>
#include <ft_scenes_images.h>
#include <ft_keys.h>

static void	_player_near_pig(t_object *pig, int key)
{
	(void)key;
	pig->move = pig->is_near;
	if (!pig->is_near && pig->sprite)
	{
		if (pig->sprite == (canva())->sprite(PIG))
			pig->sprite = (canva())->sprite(PIG + 2);
		pig->sprite = (canva())->sprite(PIG);
	}
}

static void	_pig_die(t_object *pig)
{
	pig->move = 0;
	pig->avatar = 0;
	pig->sprite = 0;
	pig->interation = 0;
	pig->collision = 0;
	pig->life = 0;
	pig->is_near = 0;
	(engine())->sound->play(&(engine())->sound[SD_PIG_DIED]);
	(engine())->task.pig++;
	ft_destroy_enemies(pig);
	ft_tasks(0);
}

static void	_is_atacked_pig(t_object *pig, int damage)
{
	double		d_x;
	double		d_y;

	pig->life -= damage;
	d_x = (pig->pos[X] < player()->pos[X]) - (pig->pos[X] > player()->pos[X]);
	d_y = (pig->pos[Y] < player()->pos[Y]) - (pig->pos[Y] > player()->pos[Y]);
	if (!pig->is_collision(pig, pig->pos[X] + (d_x * pig->vel) + 0.5, \
	pig->pos[Y] + 0.5, 0))
		pig->pos[X] += (d_x * pig->vel);
	if (!pig->is_collision(pig, pig->pos[X] + 0.5, \
	pig->pos[Y] + (d_y * pig->vel) + 0.5, 0))
		pig->pos[Y] += (d_y * pig->vel);
	(engine())->sound->play(&(engine())->sound[SD_PIG_ATACKED]);
	if (pig->life <= 0)
		_pig_die(pig);
}

static void	_pig_move(t_object *pig, int move_x)
{
	static int	i = -1;
	double		dif_x;
	double		dif_y;
	int			move_y;

	move_y = 0;
	dif_x = (pig->pos[X] > player()->pos[X]) - (pig->pos[X] < player()->pos[X]);
	dif_y = (pig->pos[Y] > player()->pos[Y]) - (pig->pos[Y] < player()->pos[Y]);
	if (!pig->is_collision(pig, pig->pos[X] + (dif_x * pig->vel) + 0.5, \
	pig->pos[Y] + 0.5, 0) && ++move_x)
		pig->pos[X] += (dif_x * pig->vel);
	if (!pig->is_collision(pig, pig->pos[X] + 0.5, \
	pig->pos[Y] + (dif_y * pig->vel) + 0.5, 0) && ++move_y)
		pig->pos[Y] += (dif_y * pig->vel);
	if (move_y || move_x)
	{
		(engine())->sound->play(&(engine())->sound[SD_PIG_RUN]);
		pig->sprite = (canva())->sprite(PIG_W0 + i++);
		if (i > 3)
			i = 0;
	}
	else if (pig->sprite)
		pig->sprite = (canva())->sprite(PIG);
	if (i == 0)
		_player_near_pig(pig, 0);
}

int	ft_create_pig(t_object *pig)
{
	pig->avatar = (canva())->sprite(PIG);
	pig->sprite = (canva())->sprite(PIG);
	pig->life = 200;
	pig->collision = 1;
	pig->interation = 5;
	pig->dimension[X] = 1;
	pig->dimension[Y] = 1;
	pig->dimension[2] = 100;
	pig->vel = 0.25;
	pig->player_near = _player_near_pig;
	pig->is_atack = _is_atacked_pig;
	pig->is_move = _pig_move;
	(engine())->task.max_pig++;
	return (1);
}
