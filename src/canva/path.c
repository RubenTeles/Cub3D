/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:24:48 by rteles            #+#    #+#             */
/*   Updated: 2022/10/30 00:53:01 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

# define FOREST '1'
# define PIG 'p'
# define DOOR 'd'

char	*ft_path(char sprite)
{
	if (sprite == 'N' || sprite == 'S' || sprite == 'W' || sprite == 'E')
		return ("./sprite/wolf/hand0.xpm");
	if (sprite == FOREST)
		return ("./sprite/forest.xpm");	
	//printf("%c", sprite);
	if (sprite == PIG)
		return ("pig/s");
	if (sprite == DOOR)
		return ("door");
	return (0);
}

void	ft_print_floor(int larg, int alt, int pos_x, int pos_y)
{
	int		x;
	int		y;
	int		color;

	color = 0x000000FF;
	y = -1;
	while (++y <= alt)
	{
		x = -1;
		while (++x <= larg)
			my_mlx_pixel_put((canva())->data, x + pos_x, y + pos_y, color);
	}
}

void	ft_sprite(char sprite, int x, int y)
{
	t_data	data;
	t_img	imagem;
	int		rsz_x;
	int		rsz_y;

	rsz_x = (engine())->size[X] / (engine())->max[X];
	rsz_y = (engine())->size[Y] / (engine())->max[Y];
	imagem.relative_path = ft_path(sprite);
	imagem.img = mlx_xpm_file_to_image((engine())->ptr, imagem.relative_path, &data.larg, &data.alt);
	if (sprite != '1')
		ft_print_floor(rsz_x, rsz_y, x * rsz_x, y * rsz_y);
	if (!imagem.img)
	{
		if (sprite == '0')
			return ;
		printf("Erro: '%s' não existe!\n", imagem.relative_path);
		return ;
	}
	data.addr = mlx_get_data_addr(imagem.img, &data.bits_per_pixel, &data.line_length,
	&data.endian);
	if (sprite == 'N')
	{
		printf("Width: %i = %i\nHeigth: %i = %i\n", data.larg, data.alt, rsz_x, rsz_y);
		rsz_x = (engine())->size[X] / (engine())->max[X];
		rsz_y = (engine())->size[Y] / (engine())->max[Y];
		resize_image(&data, 75, 40, x * rsz_x + rsz_x/4, y * rsz_y + rsz_y/4);
	}
	else
		resize_image(&data, rsz_x, rsz_y, x * rsz_x, y * rsz_y);
	return ;
}
