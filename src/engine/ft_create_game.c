/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:56:00 by rteles            #+#    #+#             */
/*   Updated: 2022/11/25 15:49:52 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

char	change_letter(char tittle)
{
	if (tittle == 'p')
		return ('0');
	if (tittle == 'c')
		return ('3');
	if (tittle == 'B')
		return ('0');
	return (tittle);
}

void	game_read_map(char **map)
{
	int			x;
	int			y;
	t_object	*obj;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != 'N' && map[y][x] != 'S' && map[y][x] != 'W' &&
				map[y][x] != 'E' && map[y][x] != '0' && map[y][x] != '3')
				{
					obj = ft_new_object(map[y][x], x, y);
					obj->map = &map[y][x];
					map[y][x] = change_letter(map[y][x]);
				}
			if (x > (engine())->max[X])
				(engine())->max[X] = x;
		}
	}
	(engine())->max[Y] = y;
}

void 	ft_create_game(void)
{
	static int  a = 0;

	if (a > 0)
		return ;
	game_read_map(all()->map);
	new_player();
	a++;
}
