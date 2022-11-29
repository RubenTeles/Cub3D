/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes_managment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:02:04 by rteles            #+#    #+#             */
/*   Updated: 2022/11/29 19:47:22 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_scenes.h>
#include <ft_scenes_images.h>

void	magnament_scenes_images(void)
{
	int			i;
	t_scene_img	*scene;

	scene = 0;
	i = -1;
	while (++i < S_MAX_SCENES_IMG)
	{
		if (!(canva())->scene_img[i].on)
			continue ;
		if ((engine())->pause == 0)
			scene = &(canva())->scene_img[i];
		(canva())->scene_img[i].show(scene);
	}
}

void	reset_scenes(void)
{
	int	i;

	i = -1;
	while (++i < S_MAX_SCENES_IMG)
		(canva())->scene_img[i].on = 0;
}

void	magnament_scenes(void)
{
	if ((canva())->scene->complete == 1)
	{
		(canva())->scene = (canva())->scene->next;
		(canva())->scene->init();
	}
	if ((canva())->scene->key)
		(canva())->scene->key();
	magnament_scenes_images();
}

void	init_management_scenes(void)
{
	reset_scenes();
	(canva())->reset_scenes = reset_scenes;
	(canva())->show_scenes = magnament_scenes;
}
