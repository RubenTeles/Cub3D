/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:21:56 by rteles            #+#    #+#             */
/*   Updated: 2022/10/29 23:34:54 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

void	resize_image(t_data *img, int larg, int alt, int pos_x, int pos_y)
{
	int		x;
	int		y;
	int		color;
	double	x_red;
	double	y_red;	

	x_red = 0;
	y_red = 0;
	y = -1;
	while (++y <= alt)
	{
		x = -1;
		x_red = 0;
		while (++x <= larg)
		{
			color = get_pixel_color(img, x_red, y_red);
			if (color > 0)
				my_mlx_pixel_put((canva())->data, x + pos_x, y + pos_y, color);
			x_red += img->larg / larg;
		}
		y_red += img->alt / alt; 
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (color == 0 || x > (canva())->data->larg || y > (canva())->data->alt)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_pixel_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

static void	__destroy(void)
{
	free((canva())->data);
}

void	new_canva(void)
{
	(canva())->data = malloc(sizeof(t_data));
	(canva())->data->img = mlx_new_image((engine())->ptr, (engine())->size[X], (engine())->size[X]);
	(canva())->data->larg = (engine())->size[X];
	(canva())->data->alt = (engine())->size[X];
	(canva())->data->addr = mlx_get_data_addr((canva())->data->img, &(canva())->data->bits_per_pixel,
	&(canva())->data->line_length, &(canva())->data->endian);
	(canva())->sprite = ft_sprite;
	(canva())->getPxColor = get_pixel_color;
	(canva())->put_pixel = my_mlx_pixel_put;
	(canva())->resize = resize_image;
	(canva())->destroy = __destroy;
}

t_canva	*canva(void)
{
	static t_canva c;
	
	return (&c);
}
