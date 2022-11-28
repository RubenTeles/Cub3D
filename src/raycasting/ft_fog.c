/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fog.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:39:42 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/28 10:23:01 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_raycaster.h>
#include <ft_engine.h>

double	ft_dist_pts(double x1, double y1, double x2, double y2)
{
	double	dif1;
	double	dif2;

	dif1 = pow(y2 - y1, 2);
	dif2 = pow(x2 - x1, 2);
	dif1 = dif1 + dif2;
	dif2 = sqrt(dif1);
	return (dif2);
}

int	ft_fog(t_data *data, double time)
{
	int		x;
	int		y;
	int		color;
	int		arr[2];
	float	t;

	y = -1;
	t = ft_convert_time(time / 2, 100);
	while (++y < data->alt)
	{
		x = -1;
		while (++x < data->larg)
		{
			color = canva()->getPxColor(data, x, y);
			if (all()->stop_weather == 1)
				arr[0] = 11251376;
			else if (all()->stop_weather == 2)
				arr[0] = 1;
			else
				arr[0] = all()->fog_color;
			arr[1] = color;
			if (((engine())->time >= 200.0 && (engine())->time < 600.0))
				t = 100.0F;
			if ((engine())->time > 800.0 || all()->stop_weather > 0)
				t = 0.0F;
			if (y < (data->alt / 2))
				color = ft_linear_gradient(arr, t);
			(canva())->color(ft_aux(0, 0, x, y), color);
		}
	}
	return (0);
}
