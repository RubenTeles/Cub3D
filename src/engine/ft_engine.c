/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/10/26 22:05:34 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>

int	ft_start(t_map *map)
{
	t_data	img;
	int		x;
	int		y;

	new_engine(map);
	if (!(engine())->ptr)
		return (1);
	//path_images(all);
	//verification_map(all, 0, 0, all->game);
	//put_menu(all);
	//(engine())->canva = malloc(sizeof(t_canva));//create_image();
	//(engine())->canva->put_pixel = my_mlx_pixel_put;
	img.img = mlx_new_image((engine())->ptr, 1344, 756);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	y = -1;
	while (++y < 756)
	{
		x = -1;
		while (++x < 756)
		{
			if (x <= 50)
				my_mlx_pixel_put(&img, x, y, 0xFF000000);
			else if (x <= 100)
				my_mlx_pixel_put(&img, x, y, 0x0FF00000);
			else if (x <= 150)
				my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			else if (x <= 200)
				my_mlx_pixel_put(&img, x, y, 0x000FF000);
			else if (x <= 250)
				my_mlx_pixel_put(&img, x, y, 0x0000FF00);
			else if (x <= 300)
				my_mlx_pixel_put(&img, x, y, 0x00000FF0);
			else if (x <= 350)
				my_mlx_pixel_put(&img, x, y, 0x000000FF);
		}
	}
	mlx_put_image_to_window((engine())->ptr, (engine())->win, img.img, 0, 0);
	//mlx_loop((engine()->ptr));



	
	mlx_key_hook((engine())->win, key_hook_mode1, 0); //teclas
	mlx_hook((engine())->win, 17, 0, end_game, (engine()));
	//mlx_loop_hook((engine())->ptr, put_images, (engine()));
	mlx_loop((engine())->ptr);
	return (0);
}
