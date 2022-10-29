/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/10/29 23:33:18 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

static void	read_map(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{		
		x = (string()).len(map[y]);
		if (x > (engine())->max[X])
			(engine())->max[X] = x;
	}
	(engine())->max[Y] = y;
}

static void	create_images_map(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{		
		x = -1;
		while (map[y][++x])
			(canva())->sprite(map[y][x], x, y);
	}
	(engine())->max[Y] = y;
}

void	new_engine(char **map)
{
	(engine())->ptr = mlx_init();
	if (!engine()->ptr)
		return ;
	(engine())->max[X] = -1;
	(engine())->max[Y] = -1;
	read_map(map);
	(engine())->size[X] = 1344;
	(engine())->size[Y] = 756;
	(engine())->win = mlx_new_window((engine())->ptr, (engine())->size[X],
		(engine())->size[Y], "WOLF EAT PIG'S");
	new_canva();
	//(canva())->sprite('N', 0, 0);
	create_images_map(map);
	(engine())->game = NULL;
}

t_engine	*engine(void)
{
	static t_engine	e;

	return (&e);
}
