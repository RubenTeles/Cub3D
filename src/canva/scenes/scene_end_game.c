/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_end_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:11:19 by rteles            #+#    #+#             */
/*   Updated: 2022/11/29 20:32:04 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_scenes.h>
#include <ft_scenes_images.h>

static void	scene_end_game(void)
{
	(canva())->reset_scenes();
	(canva())->scene_img[S_TASKS].on = 1;
	(canva())->scene_img[S_END_GAME].on = 1;
}

void	create_scene_end_game(void)
{
	(canva())->scene_show[SC_END_GAME].init = scene_end_game;
}
