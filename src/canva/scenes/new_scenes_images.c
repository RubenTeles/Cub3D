/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_scenes_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:58:02 by rteles            #+#    #+#             */
/*   Updated: 2022/11/22 13:03:36 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_scenes.h>
#include <ft_scenes_images.h>

void	scenes_show(void)
{
	(canva())->scene_img[S_LOGIN].show = ft_login;
	(canva())->scene_img[S_MENU].show = ft_initial_menu;
	(canva())->scene_img[S_BACKGROUND].show = ft_background;
	(canva())->scene_img[S_RAYCAST].show = ft_raycasting;
	(canva())->scene_img[S_HAND].show = ft_hands;
	(canva())->scene_img[S_MAP].show = ft_map;
	(canva())->scene_img[S_MINI_MAP].show = ft_minimap;
	(canva())->scene_img[S_LIFE].show = ft_life;
	(canva())->scene_img[S_PAUSE].show = ft_pause;
	(canva())->scene_img[S_PRESS_E].show = ft_press_e;
}

void	scenes_animation(void)
{
	(canva())->scene_img[S_LOGIN].animation = 0;
	(canva())->scene_img[S_MENU].animation = 0;
	(canva())->scene_img[S_BACKGROUND].animation = 0.00017;
	(canva())->scene_img[S_HAND].animation = 0.0004;
	(canva())->scene_img[S_MAP].animation = 0;
	(canva())->scene_img[S_MINI_MAP].animation = 0;
	(canva())->scene_img[S_LIFE].animation = 0;
	(canva())->scene_img[S_PAUSE].animation = 0;
	(canva())->scene_img[S_PRESS_E].animation = 0;
}

void	new_scenes_img(void)
{
	int i;

	(canva())->scene_img = malloc(sizeof(t_scene_img) * S_MAX_SCENES_IMG);
	scenes_animation();
	scenes_show();
	i = -1;
	while (++i <= S_MAX_SCENES_IMG)
		(canva())->scene_img[i].on = 0;
}
