/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/10/29 00:21:04 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>

int	ft_start(t_map *map)
{
	t_data	data;
	t_data	data_2;
	t_img	imagem;
	int		x;
	int		y;
	int		color;

	new_engine(map);
	if (!(engine())->ptr)
		return (1);
	//path_images(all);
	//verification_map(all, 0, 0, all->game);
	//put_menu(all);
	//(engine())->canva = malloc(sizeof(t_canva)create_image();
	//(engine())->canva->put_pixel = my_mlx_pixel_put;
	imagem.relative_path = "./sprite/forest.xpm";
	imagem.img = mlx_xpm_file_to_image((engine())->ptr, imagem.relative_path, &imagem.img_width, &imagem.img_height);

	//printf("%i \n%i\n", imagem.img_width, imagem.img_height);
	data.img = mlx_new_image((engine())->ptr, imagem.img_width, imagem.img_height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
	&data.endian);

	data_2.addr = mlx_get_data_addr(imagem.img, &data_2.bits_per_pixel, &data_2.line_length,
	&data_2.endian);
	printf("Width: %i\nHeigth: %i\n", imagem.img_width, imagem.img_height);
	y = -1;
	while (++y < imagem.img_height)
	{
		x = -1;
		while (++x < imagem.img_width)
			my_mlx_pixel_put(&data, x, y, get_pixel_color(&data_2, x, y));
	}
	mlx_put_image_to_window((engine())->ptr, (engine())->win, data.img, 0, 0);
	mlx_key_hook((engine())->win, key_hook_mode1, 0); //teclas
	mlx_hook((engine())->win, 17, 0, end_game, (engine()));
	//mlx_loop_hook((engine())->ptr, put_images, (engine()));
	mlx_loop((engine())->ptr);
	return (0);
}
