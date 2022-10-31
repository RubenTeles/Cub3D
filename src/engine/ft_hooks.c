/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:40:39 by rteles            #+#    #+#             */
/*   Updated: 2022/10/29 20:43:05 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>
#include <ft_engine.h>

int	end_game(void)
{
	//int	y;

	mlx_clear_window((engine())->ptr, (engine())->win);
	(canva())->destroy();
	//y = -1;
	//while ((engine())->game[++y])
	//	free((engine())->game[y]);
	//free((engine())->game);
	//mlx_destroy_window((engine())->ptr, (engine())->win);
	//(engine())->argc_corrent += 1;
	//if ((engine())->t.lives > 0 && ((engine())->argc_corrent <= (engine())->argc_max))
	//{
	//	ft_loop_game((engine()), (engine())->argc_corrent, all->argv);
	//	return (0);
	//}
	exit(0);
	return (1);
}
