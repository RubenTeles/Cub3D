/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_scenes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:04:27 by rteles            #+#    #+#             */
/*   Updated: 2022/11/22 13:03:10 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_scenes.h>
#include <ft_scenes_images.h>

void scene_login(void)
{
	(canva())->scene_show[SC_LOGIN].complete = 0;
	(canva())->scene_img[S_LOGIN].on = 1;
}

void scene_menu(void)
{
	(canva())->scene_show[SC_MENU].complete = 0;
	(canva())->reset_scenes();
	(canva())->scene_img[S_MENU].on = 1;
}

void scene_game(void)
{
	(canva())->scene_show[SC_GAME].complete = 0;
	(canva())->reset_scenes();
	(canva())->scene_img[S_BACKGROUND].on = 1;
	(canva())->scene_img[S_RAYCAST].on = 1;
	(canva())->scene_img[S_HAND].on = 1;
	(canva())->scene_img[S_LIFE].on = 1;
	(canva())->scene_img[S_MINI_MAP].on = 1;
}

void scene_pause(void)
{
	(canva())->scene_show[SC_PAUSE].complete = 0;
	(canva())->scene_img[S_PAUSE].on = 1;
}

void	new_scenes(void)
{
	int	i;

	i = -1;
	new_scenes_img();
	(canva())->scene_show = malloc(sizeof(t_scene) * SC_MAX_SCENES);
	(canva())->scene_show[SC_LOGIN].init = scene_login;
	(canva())->scene_show[SC_MENU].init = scene_menu;
	(canva())->scene_show[SC_GAME].init = scene_game;
	(canva())->scene_show[SC_PAUSE].init = scene_pause;
	while (++i < SC_MAX_SCENES)
	{
		(canva())->scene_show[i].complete = 0;
		if (i + 1 < SC_MAX_SCENES)
			(canva())->scene_show[i].next = &(canva())->scene_show[i + 1];
		else
			(canva())->scene_show[i].next = &(canva())->scene_show[i - 1];
	}
	key_management();
	init_management_scenes();
}
