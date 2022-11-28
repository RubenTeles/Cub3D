/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable_cristal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:46:08 by rteles            #+#    #+#             */
/*   Updated: 2022/11/28 22:28:55 by rteles           ###   ########.fr       */
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

static void	_interation_cristal(t_object *cristal, int key)
{
	(void)key;
	(void)cristal;
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
	return (1);
}
