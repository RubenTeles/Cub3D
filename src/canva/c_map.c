/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:11:30 by rteles            #+#    #+#             */
/*   Updated: 2022/11/04 00:59:34 by rteles           ###   ########.fr       */
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

	data = (canva())->sprite(sprite);
	if (!data)
		return ;
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
	int				x;
	int				y;
	char			title_image;
	static int		avatar = 0;

	if (avatar == 0)
		avatar = 1;
	else
		avatar = 0;
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
		{
			title_image = map[y][x];
			(void)avatar;
			if ((title_image == 'N' || title_image == 'S' || title_image == 'W'\
				|| title_image == 'E') && avatar == 0)
					continue ;
			ft_print_map(title_image, x + 2, y + 2);
		}
	}
}
