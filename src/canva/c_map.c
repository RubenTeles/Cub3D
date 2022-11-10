/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:11:30 by rteles            #+#    #+#             */
/*   Updated: 2022/11/10 20:23:43 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

void	ft_print_map(char sprite, double x, double y)
{
	t_data	*data;

	if (sprite == (player())->sprite->title)
		sprite = 'X';
	data = (canva())->sprite(sprite);
	if (!data)
		return ;
	if (data->title == 'M')
		(canva())->resize(data, (canva())->rsz[X], (canva())->rsz[Y], x, y);
	else if (data->title == 'X')
	{
		(canva())->resize(data, (canva())->rsz[X] * 0.50, (canva())->rsz[Y] * 0.50,\
			x * (canva())->rsz[X] + ((canva())->rsz[X] * 0.25),\
			y * (canva())->rsz[Y] + ((canva())->rsz[Y] * 0.25));
	}
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

	avatar++;
	if ((player())->move > 0)
	{
		avatar = 8;
		(player())->move = 0;
	}
	else if (avatar >= 16)
		avatar = 0;
	(canva())->rsz[X] = (engine())->size[X] * 0.85;
	(canva())->rsz[Y] = (engine())->size[Y] * 0.85;
    x = (engine())->size[X] - (engine())->size[X] * 0.94;
    y = (engine())->size[Y] - (engine())->size[Y] * 0.94;
	ft_print_map('M', x, y);
	(canva())->rsz[X] = (engine())->size[X] * 0.63 / (engine())->max[X];
	(canva())->rsz[Y] = (engine())->size[Y] * 0.80 / (engine())->max[X];
	ft_put_word("MAP", (engine())->size[X] * 0.15, (engine())->size[Y] *\
		0.05, (engine())->size[X] * 0.425, (engine())->size[Y] * 0.16);
	y = -1;
	while (map[++y])
	{		
		x = -1;
		while (map[y][++x])
		{
			title_image = map[y][x];
			if (title_image == '1')
				title_image = 'T';
			if ((title_image == 'N' || title_image == 'S' || title_image == 'W'\
				|| title_image == 'E'))
					continue ;
			ft_print_map(title_image, x + 2, y + 2.5);
		}
	}
	if (avatar >= 8)
		ft_print_map((player())->sprite->title, (player())->pos[X] + 2,\
			(player())->pos[Y] + 2.5);
}
