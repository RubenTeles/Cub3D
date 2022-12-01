/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:41:43 by rteles            #+#    #+#             */
/*   Updated: 2022/12/01 17:08:09 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_keys.h>
#include <ft_sprites.h>
#include <ft_scenes.h>
#include <ft_scenes_images.h>
#include <ft_sound.h>

//INSTRUTIONS
int	key_menu_4(void)
{
	static long long	time_start = 0;
	long long			dif;

	if (time_start == 0)
		time_start = time_current();
	dif = time_diff(time_start, time_current());
	if ((dif > 300 || time_start == 0) && (engine())->key[_KEY_ENTER].on)
	{
		time_start = time_current();
		(engine())->sound->play(&(engine())->sound[SD_KEYS]);
		(canva())->scene_img[S_INSTRUTIONS].on = 0;
		(engine())->menu = 3;
	}
	return (1);
}

//Button 3
int	key_menu_3(void)
{
	if ((engine())->key[_KEY_W].on)
	{
		(engine())->sound->play(&(engine())->sound[SD_KEYS]);
		(engine())->menu = 2;
	}
	if ((engine())->key[_KEY_S].on)
	{
		(engine())->sound->play(&(engine())->sound[SD_KEYS]);
		(engine())->menu = 1;
	}
	if ((engine())->key[_KEY_ENTER].on)
	{
		(engine())->sound->play(&(engine())->sound[SD_KEYS]);
		(canva())->scene_img[S_INSTRUTIONS].on = 1;
		(engine())->menu = 5;
	}
	return (1);
}
/*if ((engine())->key[_KEY_ENTER].on)
	(engine())->menu = 5;*/

//Button 2
int	key_menu_2(void)
{
	if ((engine())->key[_KEY_W].on)
	{
		(engine())->sound->play(&(engine())->sound[SD_KEYS]);
		(engine())->menu = 1;
	}
	if ((engine())->key[_KEY_S].on)
	{
		(engine())->sound->play(&(engine())->sound[SD_KEYS]);
		(engine())->menu = 3;
	}
	if ((engine())->key[_KEY_ENTER].on)
		(engine())->sound->play(&(engine())->sound[SD_DENNY]);
	return (1);
}
/*(engine())->menu = 4;*/

//Button 1
int	key_menu_1(void)
{
	if ((engine())->key[_KEY_W].on)
	{
		(engine())->sound->play(&(engine())->sound[SD_KEYS]);
		(engine())->menu = 3;
	}
	else if ((engine())->key[_KEY_S].on)
	{
		(engine())->sound->play(&(engine())->sound[SD_KEYS]);
		(engine())->menu = 2;
	}
	else if ((engine())->key[_KEY_ENTER].on)
	{
		(engine())->sound->play(&(engine())->sound[SD_WOLF]);
		(canva())->scene->complete = 1;
		(engine())->menu = 0;
		(engine())->start_time = time_current();
		(engine())->time = 0;
	}
	return (1);
}

//Button 1
int	key_menu(void)
{
	static long long	time_start = 0;
	long long			dif;

	dif = time_diff(time_start, time_current());
	if (dif > 100 || time_start == 0)
	{
		time_start = time_current();
		if ((engine())->menu == 1)
			return (key_menu_1());
		else if ((engine())->menu == 2)
			return (key_menu_2());
		else if ((engine())->menu == 3)
			return (key_menu_3());
		else if ((engine())->menu == 5)
			return (key_menu_4());
	}
	return (0);
}
