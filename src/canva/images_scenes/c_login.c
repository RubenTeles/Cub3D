/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_login.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 00:19:52 by rteles            #+#    #+#             */
/*   Updated: 2022/11/19 21:06:23 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

int	ft_login_metric(double move)
{
	static double	x = 0;

	if (x >= 0.37)
		return (0);
	x += move;
	if (x > 0.37)
		x = 0.37;
	ft_print_color((engine())->size[X] * 0.377, (engine())->size[Y] *\
		0.0515, (engine())->size[X] * 0.311, (engine())->size[Y] * 0.581, 0X6b4324);
	ft_print_color((engine())->size[X] * 0.37, (engine())->size[Y] *\
		0.039, (engine())->size[X] * 0.314, (engine())->size[Y] * 0.587, 0xe6be7e);
	ft_print_color((engine())->size[X] * x, (engine())->size[Y] *\
		0.039, (engine())->size[X] * 0.314, (engine())->size[Y] * 0.587, 0X467527);
	ft_put_word("LOADING", (engine())->size[X] * 0.25, (engine())->size[Y] *\
		0.04, (engine())->size[X] * 0.37, (engine())->size[Y] * 0.585);
	return (1);
}

int	ft_login_images(double move, int min, int max)
{
	(canva())->create_data(min, max);
	ft_login_metric(move);
	mlx_put_image_to_window((engine())->ptr, (engine())->win,\
	(canva())->data->img, 0, 0);
	if (max < (canva()->max))
		ft_login_images(move + 0.01, min + 20, max + 20);
	return (0);
}

int	ft_login_2(double move)
{
	t_data	*data;

	data = (canva())->sprite(WALK);
	if (!data)
		return (0);
	(canva())->resize(data, (engine())->size[X] * 0.4, (engine())->size[Y] * 0.8,\
		(engine())->size[X] * 0.3, (engine())->size[Y] * 0.22);
	ft_print_color((engine())->size[X] * 0.377, (engine())->size[Y] *\
		0.0445, (engine())->size[X] * 0.011, (engine())->size[Y] * 0.941, 0X6b4324);
	ft_print_color((engine())->size[X] * 0.37, (engine())->size[Y] *\
		0.032, (engine())->size[X] * 0.013, (engine())->size[Y] * 0.948, 0xe6be7e);
	ft_put_word("MADE BY RTELES AMARIA/M", (engine())->size[X] * 0.35, (engine())->size[Y] *\
		0.03, (engine())->size[X] * 0.022, (engine())->size[Y] * 0.949);
	ft_login_metric(move);
	return (ft_login_images(move + 0.01, 1, 20));
}


int	ft_login(double move)
{
	static double	x = 0;
	t_data			*data;

	if (x > 0)
		return (ft_login_metric(move));
	(canva())->create_data(N_WALL, AVATAR);
	data = (canva())->sprite(MENU);
	if (!data)
		return (0);
	(canva())->resize(data, (engine())->size[X], (engine())->size[Y],\
		0, 0);
	ft_print_color((engine())->size[X] * 0.867, (engine())->size[Y] * 0.224,\
		 (engine())->size[X] * 0.063, (engine())->size[Y] * 0.040, 0X6b4324);
	ft_print_color((engine())->size[X] * 0.85, (engine())->size[Y] * 0.2,\
		 (engine())->size[X] * 0.07, (engine())->size[Y] * 0.051, 0xe6be7e);
	ft_put_word("WOLF EAT PIGS", (engine())->size[X] * 0.8, (engine())->size[Y] *\
		0.2, (engine())->size[X] * 0.1, (engine())->size[Y] * 0.045);
	x++;
	return (ft_login_2(move));
}
