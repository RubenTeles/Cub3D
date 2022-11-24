/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:56:00 by rteles            #+#    #+#             */
/*   Updated: 2022/11/24 19:59:35 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

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
					if (map[y][x] == 'p')
						map[y][x] = '0';
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
