/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:41:00 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/23 18:18:07 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>
#include <ft_raycaster.h>

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

float	ft_convert_time(double time, int n)
{
	static float	time_convert_n;	
	float			t;
	float			t2;

	t = (float)(((int)(time - 1) % n) + 1);
	t2 = n - t;
	if (t == n)
		time_convert_n = t;
	if (t < time_convert_n)
	{
		return (t2);
	}
	if (time_convert_n == t)
		time_convert_n = 0;
	return (t);
}
