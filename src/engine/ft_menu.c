/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:01:00 by rteles            #+#    #+#             */
/*   Updated: 2022/11/20 02:11:14 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_keys.h>

int menu_game(double time)
{
	static int	a = 0;

	if (ft_login(0.0017))
		return (mlx_put_image_to_window((engine())->ptr, (engine())->win,\
			(canva())->data->img, 0, 0));
	(engine())->time += time;
	ft_initial_menu(0.01);
	ft_words_menu();
	ft_head_wolf(0);
	key_management();
	if (a == 0 && ++a)
		(engine())->sound("paplay src/music/pMLWWiBvWX8_48.ogg");
	return (mlx_put_image_to_window((engine())->ptr, (engine())->win,\
		(canva())->data->img, 0, 0));
}
