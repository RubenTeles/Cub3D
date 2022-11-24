/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:58:17 by rteles            #+#    #+#             */
/*   Updated: 2022/11/24 11:11:39 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_sound.h>
#include <ft_scenes_images.h>
#include <ft_keys.h>

static void	_player_near_door(t_object *door, int key)
{
	(void)key;
	if (door->is_near)
		(canva())->scene_img[S_PRESS_E].on = 1;
}

static void	_interation_door(t_object *door, int key)
{
	if (key == KEY_E && door->collision == 1)
	{
		door->avatar = (canva())->sprite(DOOR_OPEN);
		door->sprite = (canva())->sprite(DOOR_OPEN);
		door->collision = 0;
		(engine())->sound->play(&(engine())->sound[SD_DOOR]);
	}
	else if (key == KEY_E && door->collision == 0)
	{
		door->avatar = (canva())->sprite(DOOR);
		door->sprite = (canva())->sprite(DOOR);
		door->collision = 1;
		(engine())->sound->play(&(engine())->sound[SD_DOOR]);
	}
}

int ft_create_door(t_object *door)
{
	door->avatar = (canva())->sprite(DOOR);
	door->sprite = (canva())->sprite(DOOR);
	door->collision = 1;
	door->interation = 0.5;
	door->player_interation = _interation_door;
	door->player_near = _player_near_door;
	return (1);
}
