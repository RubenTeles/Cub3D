/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:42:41 by rteles            #+#    #+#             */
/*   Updated: 2022/12/05 21:42:54 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_sound.h>
#include <ft_scenes_images.h>
#include <ft_keys.h>

static void	_player_near_bush(t_object *bush, int key)
{
	(void)key;
	if (bush->is_near)
		(canva())->scene_img[S_PRESS_E].on = 1;
}

static void	_is_atacked_bush(t_object *bush, int damage)
{
	(engine())->sound->play(&(engine())->sound[SD_BUSH]);
	bush->life -= damage;
	if (bush->life <= 0)
	{
		bush->avatar = 0;
		bush->sprite = 0;
		bush->interation = 0;
		bush->collision = 0;
		bush->life = 0;
		bush->is_near = 0;
		ft_destroy_enemies(bush);
	}
}

static void	_interation_bush(t_object *bush, int key)
{
	if (key != KEY_E)
		return ;
	(engine())->sound->play(&(engine())->sound[SD_BUSH]);
	if ((bush->interation > 0) && (((player())->life < 1000) || \
	(player())->fadigue < 100))
	{
		bush->avatar = (canva())->sprite(BUSH);
		bush->sprite = (canva())->sprite(BUSH);
		bush->interation = 0;
		if ((player())->life + 100 <= 1000)
			(player())->life += 100;
		else if ((player())->life + 100 > 1000)
			(player())->life = 1000;
		if ((player())->fadigue + 20 <= 100)
			(player())->fadigue += 20;
		else if ((player())->fadigue + 20 > 100)
			(player())->fadigue = 100;
		(canva())->scene_img[S_PRESS_E].on = 0;
		bush->is_near = 0;
	}
}

int	ft_create_bush(t_object *bush)
{
	bush->avatar = (canva())->sprite(BUSH_AMORAS);
	bush->sprite = (canva())->sprite(BUSH_AMORAS);
	bush->collision = 1;
	bush->interation = 0.5;
	bush->interation = 0.5;
	bush->dimension[X] = 1.5;
	bush->dimension[Y] = 1.5;
	bush->dimension[2] = 100;
	bush->player_interation = _interation_bush;
	bush->player_near = _player_near_bush;
	bush->is_atack = _is_atacked_bush;
	return (1);
}

//bush->map[0] = '3';