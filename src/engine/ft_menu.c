/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:01:00 by rteles            #+#    #+#             */
/*   Updated: 2022/11/19 18:56:18 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_keys.h>

int menu_game(double time)
{
	static int	a = 0;
	static int	i = 0;

	printf("login\n");
	if (ft_login(0.0017))
		return (mlx_put_image_to_window((engine())->ptr, (engine())->win,\
			(canva())->data->img, 0, 0));
	(engine())->time += time;
	ft_initial_menu(0.01);
	ft_words_menu();
	ft_head_wolf(0);
	key_management();
	i++;
	if (a == 0)
	{
		//i = system("paplay src/music/pMLWWiBvWX8_48.ogg");
		a = 1;
	}
	(void)i;
	return (mlx_put_image_to_window((engine())->ptr, (engine())->win,\
		(canva())->data->img, 0, 0));
}
