/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_player_atack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:50:14 by rteles            #+#    #+#             */
/*   Updated: 2022/11/27 17:01:18 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_keys.h>
#include <ft_sprites.h>
#include <ft_scenes.h>
#include <ft_scenes_images.h>
#include <ft_sound.h>

//BUTTON LEFT 2
static int	key_atack_3(void)
{
	(player())->sprite = (canva())->sprite(HAND);
	(player())->atack = 0;
	return (0);
}

//BUTTON LEFT 1
static int	key_atack_2(void)
{
	static long long	time_start = 0;
	static int			animation = 0;

	if ((engine())->key[_BUTTON_LEFT].on && (player())->atack != 1)
	{
		(player())->atack = 2;
		(engine())->sound[SD_WOLF_DIE].dif = \
		time_diff(time_start, time_current());
		if ((engine())->sound[SD_WOLF_DIE].dif > 50 || time_start == 0)
		{
			time_start = time_current();
			if (animation == 4)
				animation = 0;
			(player())->sprite = (canva())->sprite(ATACK_1 + animation);
			animation += 1;
			(player())->obj_interation(_BUTTON_LEFT);
		}
	}
	else if ((engine())->key[_BUTTON_LEFT].on)
		(engine())->key[_BUTTON_LEFT].on = 0;
	if (!(engine())->key[_BUTTON_LEFT].on && (player())->atack == 2)
		animation = key_atack_3();
	return (0);
}
//(engine())->sound->play(&(engine())->sound[SD_WOLF_DIE]);

//BUTTON RIGHT 2
int	key_atack_1(void)
{
	if (!(engine())->key[_BUTTON_RIGHT].on && (player())->atack == 1)
	{
		(player())->sprite = (canva())->sprite(HAND);
		(engine())->sound->play(&(engine())->sound[SD_BREADING_OUT]);
		(player())->atack = 0;
	}
}

//BUTTON RIGHT 1
int	key_atack(void)
{
	static long long	time_start = 0;

	if ((engine())->key[_BUTTON_RIGHT].on && (player())->fadigue - 2 >= 0 && \
		(player())->atack <= 1)
	{
		if (!(player())->atack)
			(player())->atack = 1;
		(player())->sprite = 0;
		(engine())->sound[SD_BREADING_IN].dif = \
		time_diff(time_start, time_current());
		if ((engine())->sound[SD_BREADING_IN].dif > 750 || time_start == 0)
		{
			time_start = time_current();
			(engine())->sound->play(&(engine())->sound[SD_BREADING_IN]);
		}
		(player())->fadigue -= 2;
	}
	else if ((engine())->key[_BUTTON_RIGHT].on)
		(engine())->key[_BUTTON_RIGHT].on = 0;
	key_atack_1();
	key_atack_2();
	return (0);
}
