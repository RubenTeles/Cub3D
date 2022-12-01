/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:15:54 by rteles            #+#    #+#             */
/*   Updated: 2022/12/01 18:46:14 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

void	resize_image(t_data *img, t_aux aux)
{
	int		x;
	int		y;
	int		color;
	double	x_red;
	double	y_red;	

	x_red = 0;
	y_red = 0;
	y = -1;
	while (++y <= aux.alt)
	{
		x = -1;
		x_red = 0;
		while (++x <= aux.larg)
		{
			color = get_pixel_color(img, x_red, y_red);
			if (color > 0)
				my_mlx_pixel_put(&(canva())->data[CANVA], \
					put_clouds(img, x, aux.x), y + aux.y, color);
			x_red += img->larg / aux.larg;
		}
		y_red += img->alt / aux.alt;
	}
}

void	rev_resize_image(t_data *img, t_aux aux)
{
	int		x;
	int		y;
	int		color;
	double	x_red;
	double	y_red;	

	x_red = 0;
	y_red = 0;
	y = -1;
	while (++y <= aux.alt)
	{
		x = aux.larg;
		x_red = 0;
		while (--x >= 0)
		{
			color = get_pixel_color(img, x_red, y_red);
			if (color > 0)
				my_mlx_pixel_put(&(canva())->data[CANVA], \
					x + aux.x, y + aux.y, color);
			x_red += img->larg / aux.larg;
		}
		y_red += img->alt / aux.alt;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (color == 0 || x > (canva())->data[CANVA].larg || \
		y > (canva())->data[CANVA].alt || x < 0 || y < 0)
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
