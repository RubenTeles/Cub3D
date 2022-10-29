/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:24:48 by rteles            #+#    #+#             */
/*   Updated: 2022/10/29 20:34:50 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

# define FOREST '1'
# define PIG 'p'
# define DOOR 'd'

char	*ft_path(char sprite)
{
	sprite = FOREST;
	if (sprite == 'N' || sprite == 'S' || sprite == 'W' || sprite == 'E')
		return ("wolf/hand");
	if (sprite == FOREST)
		return ("./sprite/forest.xpm");
	if (sprite == PIG)
		return ("pig/s");
	if (sprite == DOOR)
		return ("door");
}

void	ft_sprite(char sprite)
{
	t_data	data;
	t_img	imagem;

	imagem.relative_path = ft_path(sprite);
	imagem.img = mlx_xpm_file_to_image((engine())->ptr, imagem.relative_path, &data.larg, &data.alt);
	if (!imagem.img)
	{
		printf("Erro: '%s' não existe!\n", imagem.relative_path);
		return ;
	}
	data.addr = mlx_get_data_addr(imagem.img, &data.bits_per_pixel, &data.line_length,
	&data.endian);
	printf("Width: %i\nHeigth: %i\n", data.larg, data.alt);
	resize_image(&data, 307, 162);
	return ;
}
