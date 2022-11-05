/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_background.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:23:46 by rteles            #+#    #+#             */
/*   Updated: 2022/11/05 17:01:36 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

#define CLOUD_1 'I'
#define CLOUD_2 'J'
#define CLOUD_3 'K'

/*
void	put_clouds(t_data *img, double larg, double alt, int pos_x, int pos_y)
{
	int		x;
	int		y;
	int		color;
	double	x_red;
	double	y_red;
	int		animation_x;

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
			animation_x = x + pos_x;
			if (animation_x > (engine())->size[X])
				animation_x = animation_x - (engine())->size[X] - 1;
			if (color > 0)
				my_mlx_pixel_put((canva())->data, animation_x, y + pos_y, color);
			x_red += img->larg / larg;
		}
		y_red += img->alt / alt;
	}
}*/


int	put_clouds(t_data *img, int x, int pos_x)
{
	int	animation_x;

	animation_x = x + pos_x;
	if (img->title != CLOUD_1 && img->title != CLOUD_2\
		&& img->title != CLOUD_3)
		return (animation_x);
	if (animation_x > (engine())->size[X])
		animation_x = animation_x - (engine())->size[X] - 1;
	return (animation_x);
}

void	ft_background(double move)
{
	t_data			*data;
	static double	x1 = 0;

	x1 += move;
	if (x1 > 1)
		x1 = x1 - 1;
	ft_print_color((engine())->size[X], (engine())->size[Y] / 2, 0,\
		0, (engine())->color[CEILLING]);
	data = (canva())->sprite(CLOUD_1);
	if (!data)
		return ;
	(canva())->resize(data, (engine())->size[X] * 0.17, (engine())->size[Y] *\
		0.15, (engine())->size[X] * (0.80 + x1), (engine())->size[Y] * -0.08);
	(canva())->resize(data, (engine())->size[X] * 0.17, (engine())->size[Y] *\
		0.15, (engine())->size[X] * (0.05 + x1), (engine())->size[Y] * 0.15);
	(canva())->resize(data, (engine())->size[X] * 0.19, (engine())->size[Y] *\
		0.16, (engine())->size[X] * (0.33 + x1), (engine())->size[Y] * 0.25);
	data = (canva())->sprite(CLOUD_2);
	if (!data)
		return ;
	(canva())->resize(data, (engine())->size[X] * 0.17, (engine())->size[Y] *\
		0.15, (engine())->size[X] * (0.88 + x1), (engine())->size[Y] * 0.30);
	(canva())->resize(data, (engine())->size[X] * 0.17, (engine())->size[Y] *\
		0.15, (engine())->size[X] * (0.395 + x1), (engine())->size[Y] * -0.02);
	data = (canva())->sprite(CLOUD_3);
	if (!data)
		return ;
	(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
		0.2, (engine())->size[X] * (0.01 + x1), (engine())->size[Y] * -0.1);
	(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
		0.2, (engine())->size[X] * (0.56 + x1), (engine())->size[Y] * 0.1);
	(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
		0.2, (engine())->size[X] * (0.03 + x1), (engine())->size[Y] * 0.36);
	(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
		0.2, (engine())->size[X] * (0.50 + x1), (engine())->size[Y] * 0.36);
	ft_print_color((engine())->size[X], (engine())->size[Y] / 2, 0,\
		(engine())->size[Y] / 2, (engine())->color[FLOOR]);
}

void	ft_hands(double move)
{
	t_data			*data;
	static int		a = 0;
	static double	x1 = 0.20;
	static double	x2 = 0.55;
	static double	y = 0.60;
	static int		count = 0;

	if (a == 1)
		move *= -1;
	x1 += move;
	x2 -= move;
	y += move;
	count++;
	/*if (count > 35)
	{
		data = (canva())->sprite('n');
		if (!data)
			return ;
		(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
			0.4, (engine())->size[X] * 0.42, (engine())->size[Y] * 0.66);
		rev_resize_image(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
			0.4, (engine())->size[X] * 0.31, (engine())->size[Y] * 0.66);
		if (count == 40)
			count = 0;
		return ;
	}*/
	data = (canva())->sprite('H');
	if (!data)
		return ;
	(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
		0.4, (engine())->size[X] * x1, (engine())->size[Y] * y);
	rev_resize_image(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
		0.4, (engine())->size[X] * x2, (engine())->size[Y] * y);
	if (x1 > 0.21)//x1 > 0.24)
		a = 1;
	else if (x1 <= 0.20)
		a = 0;
}
