/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:21:56 by rteles            #+#    #+#             */
/*   Updated: 2022/11/21 19:22:45 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

static void	__destroy(void)
{
	free((canva())->data);
}

void create_datas(int min, int max)
{
	while (min <= max && min < (canva())->max)
	{
		if (!(canva())->data[min].load && (canva())->data[min].path)
			(canva())->data[min] = (canva())->create_sprite((canva())->data[min], min);
		min++;
	}
}

static void canva_reset_data(void)
{
	int	i;

	(canva())->data[CANVA].load = 1;
	(canva())->data[CANVA].title = 'Z';
	(canva())->data[CANVA].path = NULL;
	(canva())->data[CANVA].img = mlx_new_image((engine())->ptr, (engine())->size[X], \
	(engine())->size[X]);
	(canva())->data[CANVA].larg = (engine())->size[X];
	(canva())->data[CANVA].alt = (engine())->size[Y];
	(canva())->data[CANVA].addr = mlx_get_data_addr((canva())->data[CANVA].img, \
	&(canva())->data[CANVA].bits_per_pixel, &(canva())->data[CANVA].line_length, \
	&(canva())->data[CANVA].endian);
	ft_path_start();
	i = 0;
	while (++i <= (canva())->max)
		(canva())->data[i].load = 0;
}

void	new_canva(void)
{
	(canva())->max = 97;
	(canva())->data = malloc(sizeof(t_data) * (canva())->max);
	(canva())->rsz[X] = 0;
	(canva())->rsz[Y] = 0;
	(canva())->alphabet = ft_alphabet;
	(canva())->sprite = ft_sprite;
	(canva())->getPxColor = get_pixel_color;
	(canva())->put_pixel = my_mlx_pixel_put;
	(canva())->resize = resize_image;
	(canva())->create_data = create_datas;
	(canva())->create_sprite = create_sprite;
	(canva())->destroy = __destroy;
	canva_reset_data();
	new_scenes(9);
}

t_canva	*canva(void)
{
	static t_canva	c;

	return (&c);
}
