/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:40:39 by rteles            #+#    #+#             */
/*   Updated: 2022/11/28 15:39:52 by amaria-m         ###   ########.fr       */
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
	exit(0);
	return (1);
}
