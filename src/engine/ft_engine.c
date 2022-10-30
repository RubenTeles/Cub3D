/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/10/30 19:09:32 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>

int	ft_start(t_all *all)
{
	new_engine(all, 1344, 756);
	if (!(engine())->ptr)
		return (1);
	mlx_put_image_to_window((engine())->ptr, (engine())->win, (canva())->data->img, 0, 0);
	mlx_key_hook((engine())->win, key_hook_mode1, 0); //teclas
	mlx_hook((engine())->win, 17, 0, end_game, (engine()));
	mlx_loop((engine())->ptr);
	//mlx_loop_hook((engine())->ptr, put_images, (engine()));
	return (0);
}
