/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/10/29 20:45:18 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

void	read_map(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{		
		x = -1;
		while (map[y][++x])
		{
			printf("%c", map[y][x]);
		}
		if (x > (engine())->max[X])
			(engine())->max[X] = x;
		printf("\n");
	}
	(engine())->max[Y] = y;
}

void	new_engine(char **map)
{
	(engine())->ptr = mlx_init();
	if (!engine()->ptr)
		return ;
	(engine())->size[X] = 1344;
	(engine())->size[Y] = 756;
	(engine())->win = mlx_new_window((engine())->ptr, (engine())->size[X],
		(engine())->size[Y], "WOLF EAT PIG'S");
	(engine())->max[X] = -1;
	(engine())->max[Y] = -1;
	new_canva();
	read_map(map);
	(engine())->game = NULL;
}

t_engine	*engine(void)
{
	static t_engine	e;

	return (&e);
}
