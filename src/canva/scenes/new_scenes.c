/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_scenes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:58:02 by rteles            #+#    #+#             */
/*   Updated: 2022/11/22 09:21:56 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_scenes.h>

/*
void	magnament_scenes(void)
{
	int	i;

	i = -1;
	while (++i <= len)
		(canva())->scene[i].on = 0;
}*/

void	reset_scenes(void)
{
	int	i;

	i = -1;
	while (++i < S_MAX_SCENES)
		(canva())->scene[i].on = 0;
}

void	scenes_show(void)
{
	(canva())->scene[S_LOGIN].show = ft_login;
	(canva())->scene[S_MENU].show = ft_initial_menu;
	(canva())->scene[S_BACKGROUND].show = ft_background;
	(canva())->scene[S_HAND].show = ft_hands;
	(canva())->scene[S_MAP].show = ft_map;
	(canva())->scene[S_MINI_MAP].show = ft_minimap;
	(canva())->scene[S_LIFE].show = ft_life;
	(canva())->scene[S_PAUSE].show = ft_pause;
	(canva())->scene[S_PRESS_E].show = ft_press_e;
}

void	scenes_animation(void)
{
	(canva())->scene[S_LOGIN].animation = 0;
	(canva())->scene[S_MENU].animation = 0;
	(canva())->scene[S_BACKGROUND].animation = 0.00017;
	(canva())->scene[S_HAND].animation = 0.0004;
	(canva())->scene[S_MAP].animation = 0;
	(canva())->scene[S_MINI_MAP].animation = 0;
	(canva())->scene[S_LIFE].animation = 0;
	(canva())->scene[S_PAUSE].animation = 0;
	(canva())->scene[S_PRESS_E].animation = 0;
	scenes_show();
}

void	new_scenes(int len)
{
	int i;

	(canva())->scene = malloc(sizeof(t_scene) * len);
	scenes_animation();
	i = -1;
	while (++i <= len)
		(canva())->scene[i].on = 0;
}
