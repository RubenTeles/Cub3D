/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:56:00 by rteles            #+#    #+#             */
/*   Updated: 2022/11/29 17:05:56 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

int	is_enimie_or_is_floor(char c, int option)
{
	if (option == 1)
	{
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0' || \
			c == '3' || c == '2')
			return (0);
		else
			return (1);
	}
	else
	{	
		if (c == '0' || c == '2' || c == '3')
			return (1);
		if (c == 'p' || c == 'c' || c == 'B' || c == 'b')
			return (2);
	}
	return (0);
}

char	change_letter(char tittle, char **map, int y, int x)
{
	if (is_enimie_or_is_floor(tittle, 0) != 2)
		return (tittle);
	if (is_enimie_or_is_floor(map[y - 1][x], 0) == 1)
		return (map[y - 1][x]);
	if (is_enimie_or_is_floor(map[y - 1][x + 1], 0) == 1)
		return (map[y - 1][x + 1]);
	if (is_enimie_or_is_floor(map[y - 1][x - 1], 0) == 1)
		return (map[y - 1][x - 1]);
	if (is_enimie_or_is_floor(map[y][x + 1], 0) == 1)
		return (map[y][x + 1]);
	if (is_enimie_or_is_floor(map[y][x - 1], 0) == 1)
		return (map[y][x - 1]);
	if (is_enimie_or_is_floor(map[y + 1][x], 0) == 1)
		return (map[y + 1][x]);
	if (is_enimie_or_is_floor(map[y + 1][x + 1], 0) == 1)
		return (map[y + 1][x + 1]);
	if (is_enimie_or_is_floor(map[y + 1][x - 1], 0) == 1)
		return (map[y + 1][x - 1]);
	return ('0');
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
			if (is_enimie_or_is_floor(map[y][x], 1))
			{
				obj = ft_new_object(map[y][x], x, y);
				obj->map = &map[y][x];
				map[y][x] = change_letter(map[y][x], map, y, x);
			}
			if (x > (engine())->max[X])
				(engine())->max[X] = x;
		}
	}
	(engine())->max[Y] = y;
}

void	ft_create_game(void)
{
	static int	a = 0;

	if (a > 0)
		return ;
	game_read_map(all()->map);
	new_player();
	a++;
}
