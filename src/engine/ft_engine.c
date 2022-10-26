/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/26 14:41:07 by rteles           ###   ########.fr       */
=======
/*   Updated: 2022/10/25 11:31:16 by rteles           ###   ########.fr       */
>>>>>>> 444768ab73c88a7e890c449fefe39d55ef2ff2fe
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
<<<<<<< HEAD

=======
/*
>>>>>>> 444768ab73c88a7e890c449fefe39d55ef2ff2fe
int	start(t_map *map)
{
	new_engine(map);
	if (!engine().ptr)
		return (1);
	//path_images(all);
	//verification_map(all, 0, 0, all->game);
	//put_menu(all);
	//mlx_key_hook(all->win, key_hook_mode1, all);
	//mlx_hook(all->win, 17, 0, end_game, all);
	//mlx_loop_hook(all->ptr, put_images, all);
	mlx_loop(engine().ptr);
	return (0);
}
