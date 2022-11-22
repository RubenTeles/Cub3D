/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:41:00 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/22 17:40:23 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

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
