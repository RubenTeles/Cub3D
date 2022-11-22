/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linear_gradient.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:37:10 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/22 17:37:52 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_raycaster.h>

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
