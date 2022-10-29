/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/10/29 20:43:54 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>

int	ft_start(t_all *all)
{
	t_data	data;
	t_data	img_data;
	t_img	imagem;
	int		x;
	int		y;

	y = -1;
	new_engine(all->map);
	if (!(engine())->ptr)
		return (1);
	mlx_put_image_to_window((engine())->ptr, (engine())->win, (canva())->data->img, 0, 0);
	mlx_key_hook((engine())->win, key_hook_mode1, 0); //teclas
	mlx_hook((engine())->win, 17, 0, end_game, (engine()));
	mlx_loop((engine())->ptr);
	//mlx_loop_hook((engine())->ptr, put_images, (engine()));
	return (0);
}
/*
x_red = 
y_red = 

largura atual % largura para aquele que quero
altura real % ""
x += 
y += 
 
*/