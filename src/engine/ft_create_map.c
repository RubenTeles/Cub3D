/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:11:30 by rteles            #+#    #+#             */
/*   Updated: 2022/11/03 00:55:09 by rteles           ###   ########.fr       */
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

void	ft_print_map(char sprite, int x, int y)
{
	t_data	*data;

	data = (canva())->search(sprite);
	if (!data && sprite != ' ' && sprite != '0')
		data = (canva())->create(sprite);
	if (!data)
	{
		if (sprite == '0' || sprite == ' ')
			return ;
		printf("Erro: '%c' não existe!\n", sprite);
		return ;
	}
	if (data->title == 'M')
		(canva())->resize(data, (canva())->rsz[X], (canva())->rsz[Y], x, y);
	else if (data->title == 'N')
		(canva())->resize(data, (canva())->rsz[X] * 0.50, (canva())->rsz[Y] * 0.50,\
			x * (canva())->rsz[X] + ((canva())->rsz[X] * 0.25),\
			y * (canva())->rsz[Y] + ((canva())->rsz[Y] * 0.25));
	else
		(canva())->resize(data, (canva())->rsz[X], (canva())->rsz[Y], x * \
		(canva())->rsz[X], y * (canva())->rsz[Y]);	
}


void	create_images_map(char **map)
{
	int	x;
	int	y;

	(engine())->max[X] = -1;
	(engine())->max[Y] = -1;
	read_map(map);
	(canva())->rsz[X] = (engine())->size[X] * 0.85;
	(canva())->rsz[Y] = (engine())->size[Y] * 0.85;
    x = (engine())->size[X] - (engine())->size[X] * 0.94;
    y = (engine())->size[Y] - (engine())->size[Y] * 0.94;
	ft_print_map('M', x, y);
	(canva())->rsz[X] = (engine())->size[X] * 0.63 / (engine())->max[X];
	(canva())->rsz[Y] = (engine())->size[Y] * 0.80 / (engine())->max[X];
	y = -1;
	while (map[++y])
	{		
		x = -1;
		while (map[y][++x])
			ft_print_map(map[y][x], x + 2, y + 2);
	}
}
