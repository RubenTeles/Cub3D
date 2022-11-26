/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable_cristal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:46:08 by rteles            #+#    #+#             */
/*   Updated: 2022/11/26 13:44:03 by rteles           ###   ########.fr       */
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
	if (cristal->collision == 1)
	{
		cristal->avatar = 0;
		cristal->sprite = 0;
		cristal->interation = 0;
		cristal->collision = 0;
		cristal->life = 0;
		cristal->is_near = 0;
		(canva())->scene_img[S_PRESS_E].on = 0;
		(engine())->sound->play(&(engine())->sound[SD_MINING]);

	}
}

int ft_create_cristal(t_object *cristal)
{
	cristal->avatar = (canva())->sprite(CRISTALS);
	cristal->sprite = (canva())->sprite(CRISTALS);
	cristal->pos[X] += 0.5;
	cristal->pos[Y] += 0.5;
	cristal->collision = 1;
	cristal->interation = 0.5;
	cristal->dimension[X] = 0;
	cristal->dimension[Y] = 0;
	cristal->dimension[2] = 0;
	cristal->player_interation = _interation_cristal;
	cristal->player_near = _player_near_cristal;
	//cristal->map[0] = '3';
	return (1);
}
