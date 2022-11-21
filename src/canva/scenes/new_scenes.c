/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_scenes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:58:02 by rteles            #+#    #+#             */
/*   Updated: 2022/11/21 19:35:52 by rteles           ###   ########.fr       */
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

void	scenes_path(void)
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

void	new_scenes(int len)
{
	int i;

	(canva())->scene = malloc(sizeof(t_scene) * len);
	scenes_path();
	i = -1;
	while (++i <= len)
		(canva())->scene[i].on = 0;
}
