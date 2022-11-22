/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:01:00 by rteles            #+#    #+#             */
/*   Updated: 2022/11/22 09:13:36 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_keys.h>
#include <ft_scenes.h>

int menu_game(double time)
{
	static int	a = 0;

	/*if ((canva())->scene[S_LOGIN].show(0.0017, 0))
		return (mlx_put_image_to_window((engine())->ptr, (engine())->win,\
			(canva())->data->img, 0, 0));*/
	(engine())->time += time;
	(canva())->scene[S_MENU].show(0);
	ft_words_menu();
	ft_head_wolf(0);
	key_management();
	if (a == 0 && ++a)
		++a;
	return (mlx_put_image_to_window((engine())->ptr, (engine())->win,\
		(canva())->data->img, 0, 0));
}
