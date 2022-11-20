/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:15:54 by rteles            #+#    #+#             */
/*   Updated: 2022/11/19 17:30:24 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

void	resize_image(t_data *img, double larg, double alt, int pos_x, int pos_y)
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
				my_mlx_pixel_put(&(canva())->data[CANVA], put_clouds(img, x, pos_x),\
					y + pos_y, color);
			x_red += img->larg / larg;
		}
		y_red += img->alt / alt;
	}
}

void	rev_resize_image(t_data *img, double larg, double alt, int pos_x, int pos_y)
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
		x = larg;
		x_red = 0;
		while (--x >= 0)
		{
			color = get_pixel_color(img, x_red, y_red);
			if (color > 0)
				my_mlx_pixel_put(&(canva())->data[CANVA], x + pos_x, y + pos_y, color);
			x_red += img->larg / larg;
		}
		y_red += img->alt / alt;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (color == 0 || x > (canva())->data[CANVA].larg || y > (canva())->data[CANVA].alt ||
			x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
