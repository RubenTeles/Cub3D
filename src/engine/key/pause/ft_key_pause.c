/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_pause.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:40:59 by rteles            #+#    #+#             */
/*   Updated: 2022/11/29 20:00:15 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_keys.h>
#include <ft_sprites.h>
#include <ft_scenes.h>
#include <ft_scenes_images.h>
#include <ft_sound.h>

int	key_pause(void)
{
	if (((engine())->key[_KEY_P].on || (engine())->key[_KEY_ENTER].on) \
		&& ((engine())->pause == 1))
		(engine())->pause = 2;
	if ((!(engine())->key[_KEY_P].on || !(engine())->key[_KEY_ENTER].on) \
		&& ((engine())->pause == 2))
	{
		(engine())->pause = 0;
		(engine())->key[_KEY_P].on = 0;
		(engine())->key[_KEY_ENTER].on = 0;
		(canva())->scene = &(canva())->scene_show[SC_GAME];
		(canva())->scene->init();
		(engine())->start_time += (engine())->pause_time * 1000;
	}
	return (0);
}
