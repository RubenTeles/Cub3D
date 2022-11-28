/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:40:39 by rteles            #+#    #+#             */
/*   Updated: 2022/11/28 20:01:56 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>
#include <ft_engine.h>

int	end_game(void)
{
	mlx_clear_window((engine())->ptr, (engine())->win);
	array().free(all()->map);
	ft_free_map_inf(all()->file);
	(canva())->destroy();
	(engine())->key->destroy();
	(engine())->object->destroy();
	(engine())->sound->destroy();
	mlx_destroy_window((engine())->ptr, (engine())->win);
	free((engine())->ptr);
	exit(0);
	return (1);
}
