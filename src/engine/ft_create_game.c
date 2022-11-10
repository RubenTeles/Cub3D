/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:56:00 by rteles            #+#    #+#             */
/*   Updated: 2022/11/10 19:25:53 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

void	game_read_map(char **map)
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

void 	ft_create_game(void)
{
	static int  a = 0;

	if (a > 0)
		return ;
	new_player();
	game_read_map(all()->map);
	a++;
}
