/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable_cristal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:46:08 by rteles            #+#    #+#             */
/*   Updated: 2022/12/01 18:38:39 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_sound.h>
#include <ft_scenes_images.h>
#include <ft_keys.h>

static void	_player_near_cristal(t_object *cristal, int key)
{
	(void)key;
	(void)cristal;
}

static void	_cristal_die(t_object *cristal)
{
	cristal->avatar = 0;
	cristal->sprite = 0;
	cristal->interation = 0;
	cristal->collision = 0;
	cristal->life = 0;
	cristal->is_near = 0;
	(engine())->task.cristal++;
	ft_destroy_enemies(cristal);
}

static void	_interation_cristal(t_object *cristal, int key)
{
	static long long	time_start = 0;

	if (key != _BUTTON_LEFT)
		return ;
	(engine())->sound[SD_MINING].dif = time_diff(time_start, time_current());
	if (cristal->collision == 1 && ((engine())->sound[SD_MINING].dif > 700 \
		|| time_start == 0))
	{
		time_start = time_current();
		cristal->life -= 20;
		(engine())->sound->play(&(engine())->sound[SD_MINING]);
		if (cristal->life <= 0)
		{
			(engine())->sound->play(&(engine())->sound[SD_DIAMOND]);
			_cristal_die(cristal);
		}
	}
}

int	ft_create_cristal(t_object *cristal)
{
	cristal->avatar = (canva())->sprite(CRISTALS);
	cristal->sprite = (canva())->sprite(CRISTALS);
	cristal->collision = 1;
	cristal->interation = 0.5;
	cristal->dimension[X] = 2;
	cristal->dimension[Y] = 2;
	cristal->dimension[2] = 250;
	cristal->player_interation = _interation_cristal;
	cristal->player_near = _player_near_cristal;
	(engine())->task.max_cristal++;
	return (1);
}
