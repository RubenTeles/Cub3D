/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:00:10 by rteles            #+#    #+#             */
/*   Updated: 2022/11/08 19:27:26 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>

#define MINIMAP 'm'

void	ft_minimap(char	**map)
{
	t_data	*data;

	data = (canva())->sprite(MINIMAP);
	if (!data)
		return ;
	ft_print_color((engine())->size[X] * 0.221, (engine())->size[Y] * 0.174,\
		 (engine())->size[X] * 0.741, (engine())->size[Y] * 0.086, 0xe6be7e);
	(canva())->resize(data, (engine())->size[X] * 0.30, (engine())->size[Y] *\
		0.35, (engine())->size[X] * 0.70, (engine())->size[Y] * 0.00);
	/*							Word MiniMAP*/
	ft_put_word("MINI MAP", (engine())->size[X] * 0.15, (engine())->size[Y] *\
		0.04, (engine())->size[X] * 0.775, (engine())->size[Y] * 0.26);
	(void)map;
	/*
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			title_image = map[y][x];
			if (title_image == '1')
				title_image = 'T';
			if ((title_image == 'N' || title_image == 'S' || title_image == 'W'\
				|| title_image == 'E') && avatar == 0)
					continue ;
			ft_print_map(title_image, x + 2, y + 2);
		}
	}*/
}
