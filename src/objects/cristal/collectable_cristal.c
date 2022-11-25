/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable_cristal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:46:08 by rteles            #+#    #+#             */
/*   Updated: 2022/11/25 16:01:59 by rteles           ###   ########.fr       */
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
	if (cristal->is_near)
		(canva())->scene_img[S_PRESS_E].on = 1;
}

static void	_interation_cristal(t_object *cristal, int key)
{
	if (key != KEY_E)
		return ;
	//(engine())->sound->play(&(engine())->sound[SD_cristal]);
	if (cristal->collision == 1)
	{
		cristal->avatar = 0;
		cristal->sprite = 0;
		cristal->interation = 0;
		cristal->collision = 0;
		cristal->life = 0;
		(canva())->scene_img[S_PRESS_E].on = 0;
		(engine())->sound->play(&(engine())->sound[SD_MINING]);
	}
}

int ft_create_cristal(t_object *cristal)
{
	cristal->avatar = (canva())->sprite(CRISTALS);
	cristal->sprite = (canva())->sprite(CRISTALS);
	cristal->collision = 1;
	cristal->interation = 0.5;
	cristal->player_interation = _interation_cristal;
	cristal->player_near = _player_near_cristal;
	//cristal->map[0] = '3';
	return (1);
}
