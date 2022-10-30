/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/10/30 19:09:41 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>

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

static void	colors_floor_ceilling(char **floor, char **ceilling)
{
	char	r;
	char	g;
	char	b;

	r = (string()).atoi(floor[0]);
	g = (string()).atoi(floor[1]);
	b = (string()).atoi(floor[2]);
	(engine())->color[FLOOR] = ft_trgb(0, r, g, b);
	r = (string()).atoi(ceilling[0]);
	g = (string()).atoi(ceilling[1]);
	b = (string()).atoi(ceilling[2]);
	(engine())->color[CEILLING] = ft_trgb(0, r, g, b);
}

void	new_engine(t_all *all, int larg, int alt)
{
	(engine())->ptr = mlx_init();
	if (!engine()->ptr)
		return ;
	(engine())->max[X] = -1;
	(engine())->max[Y] = -1;
	read_map(all->map);
	(engine())->size[X] = larg;
	(engine())->size[Y] = alt;
	(engine())->win = mlx_new_window((engine())->ptr, (engine())->size[X],
		(engine())->size[Y], "WOLF EAT PIG'S");
	colors_floor_ceilling(all->file->f, all->file->c);
	new_canva();
	create_images_map(all->map);
	(engine())->game = NULL;
}

t_engine	*engine(void)
{
	static t_engine	e;

	return (&e);
}
