/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas_methods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:21:14 by rteles            #+#    #+#             */
/*   Updated: 2022/11/20 00:16:14 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

t_data	create_sprite(t_data new, int sprite)
{
	if (new.load == 1)
		return (new);
	new.title = sprite;
	new.img = mlx_xpm_file_to_image((engine())->ptr, new.path, &new.larg, \
	&new.alt);
	if (!new.img)
	{
		printf("Erro: Sprite '%c' com o Path: '%s' não existe!\n", \
		sprite, new.path);
		return (new);
	}
	new.addr = mlx_get_data_addr(new.img, &new.bits_per_pixel, \
	&new.line_length, &new.endian);
	new.load = 1;
	return (new);
}

t_data	*ft_sprite(int sprite)
{
	t_data	*data;

	data = &(canva())->data[sprite];
	if (!data)
	{
		if (sprite == '0' || sprite == ' ')
			return (0);
		printf("Erro: '%c' não existe!\n", sprite);
		return (0);
	}
	return (data);
}
