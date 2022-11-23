/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:40:39 by rteles            #+#    #+#             */
/*   Updated: 2022/11/23 11:01:18 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>
#include <ft_engine.h>

int	end_game(void)
{
	mlx_clear_window((engine())->ptr, (engine())->win);
	(canva())->destroy();
	(engine())->key->destroy();
	(engine())->object->destroy();
	(engine())->sound->destroy();
	mlx_destroy_window((engine())->ptr, (engine())->win);
	exit(0);
	return (1);
}
