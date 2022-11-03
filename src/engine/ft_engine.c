/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/11/03 00:56:01 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>


int	ft_start(t_all *all)
{
	new_engine(all, 1344, 756);
	if (!(engine())->ptr)
		return (1);
	//create_images_menu(all->map);
	mlx_put_image_to_window((engine())->ptr, (engine())->win,\
		(canva())->data->img, 0, 0);
	mlx_key_hook((engine())->win, key_press_no_repeat, all->map); //teclas
	mlx_hook((engine())->win, 2, 1L<<0, key_press, 0);
	mlx_hook((engine())->win, 4, 1L<<2, key_mouse_press, 0);
	mlx_hook((engine())->win, 5, 1L<<3, key_mouse_out, 0);
	mlx_hook((engine())->win, 6, 1L<<6, key_mouse_move, 0);
	mlx_hook((engine())->win, 17, 0, end_game, (engine()));//Fechar
	mlx_loop((engine())->ptr);
	//mlx_loop_hook((engine())->ptr, put_images, (engine()));
	return (0);
}
/*
int	ft_game(t_all *all)
{
	
}*/