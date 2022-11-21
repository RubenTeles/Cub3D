/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:41:00 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/21 16:20:48 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

float	ft_get_red(int i)
{
	return ((float)((i >> 16) & 0xFF));
}

float	ft_get_green(int i)
{
	return ((float)((i >> 8) & 0xFF));
}

float	ft_get_blue(int i)
{
	return ((float)(i & 0xFF));
}

int	get_light(float start, float end, float percent)
{
	return ((1.0 - (percent / 100.0)) * start + (percent / 100.0) * end);
}

int	ft_linear_gradient(int colors[2], float percent)
{
	int	red;
	int	green;
	int	blue;
	int	num;

	if (colors[0] == colors[1])
		return (colors[0]);
	num = ft_get_red(colors[1]);
	red = get_light(ft_get_red(colors[0]), num, percent);
	num = ft_get_green(colors[1]);
	green = get_light(ft_get_green(colors[0]), num, percent);
	num = ft_get_blue(colors[1]);
	blue = get_light(ft_get_blue(colors[0]), num, percent);
	return ((red << 16) | (green << 8) | blue);
}

int	ft_texture_num(int map_x, int map_y, int side, t_view view)
{
	int	texnum;

	texnum = all()->map[map_y][map_x] - 49;
	if (texnum == 0)
	{
		if (side == 1 && map_y > view.pos_y)
			return (1);
		if (side == 0 && map_x > view.pos_x)
			return (3);
		if (side == 0 && map_x < view.pos_x)
			return (2);
		if (side == 0 && view.dir_x == 0 && map_x > view.pos_x)
			return (3);
		if (side == 0 && view.dir_x == 0)
			return (2);
	}
	return (texnum + 3);
}

double	ft_dist_pts(double x1, double y1, double x2, double y2)
{
	double dif1;
	double dif2;

	dif1 = pow(y2 - y1, 2);
	dif2 = pow(x2 - x1, 2);
	dif1 = dif1 + dif2;
	dif2 = sqrt(dif1);
	return (dif2);
}

int	ft_fog(t_data *data)
{
	int	x;
	int	y;
	int	color;
	int	arr[2];
	// int	dist;
	// int	big_dist;

	y = -1;
	// big_dist = (int)ft_dist_pts(data->larg / 2, data->alt / 2, data->larg / 2, data->alt);
	while (++y < data->alt)
	{
		// dist = ft_dist_pts(data->larg / 2, y, data->larg / 2, data->alt);
		x = -1;
		while (++x < data->larg)
		{
			color = canva()->getPxColor(data, x, y);
			arr[0] = 11251376;
			arr[1] = color;
			// if (y > ((data->alt) * 2 / 3) && y + 585 >= x && (x + y) >= data->alt)
			// 	color = ft_linear_gradient(arr, 40.0);
			if (y < (data->alt / 2))
				color = ft_linear_gradient(arr, 0);
			ft_print_color(0, 0, x, y, color);
		}
	}
	return (0);
}
