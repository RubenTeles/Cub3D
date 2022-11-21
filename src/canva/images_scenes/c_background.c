/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_background.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:23:46 by rteles            #+#    #+#             */
/*   Updated: 2022/11/21 15:33:04 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

int	put_clouds(t_data *img, int x, int pos_x)
{
	int	animation_x;

	animation_x = x + pos_x;
	if (img->title != CLOUD_1 && img->title != CLOUD_2\
		&& img->title != CLOUD_3)
		return (animation_x);
	if (animation_x > (engine())->size[X])
		animation_x = animation_x - (engine())->size[X] - 1;
	return (animation_x);
}

void	ft_background(double move)
{
	t_data			*data;
	static double	x1 = 0;

	x1 += move + (player())->turn_times;
	if (x1 > 1)
		x1 = x1 - 1;
	if (x1 < 0)
		x1 = x1 + 1;
	ft_print_color((engine())->size[X], (engine())->size[Y] / 2, 0,\
		0, (engine())->color[CEILLING]);
	data = (canva())->sprite(CLOUD_1);
	if (!data)
		return ;
	(canva())->resize(data, (engine())->size[X] * 0.17, (engine())->size[Y] *\
		0.15, (engine())->size[X] * (0.80 + x1), (engine())->size[Y] * -0.08);
	(canva())->resize(data, (engine())->size[X] * 0.17, (engine())->size[Y] *\
		0.15, (engine())->size[X] * (0.05 + x1), (engine())->size[Y] * 0.15);
	(canva())->resize(data, (engine())->size[X] * 0.19, (engine())->size[Y] *\
		0.16, (engine())->size[X] * (0.33 + x1), (engine())->size[Y] * 0.25);
	data = (canva())->sprite(CLOUD_2);
	if (!data)
		return ;
	(canva())->resize(data, (engine())->size[X] * 0.17, (engine())->size[Y] *\
		0.15, (engine())->size[X] * (0.88 + x1), (engine())->size[Y] * 0.30);
	(canva())->resize(data, (engine())->size[X] * 0.17, (engine())->size[Y] *\
		0.15, (engine())->size[X] * (0.395 + x1), (engine())->size[Y] * -0.02);
	data = (canva())->sprite(CLOUD_3);
	if (!data)
		return ;
	(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
		0.2, (engine())->size[X] * (0.01 + x1), (engine())->size[Y] * -0.1);
	(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
		0.2, (engine())->size[X] * (0.56 + x1), (engine())->size[Y] * 0.1);
	(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
		0.2, (engine())->size[X] * (0.03 + x1), (engine())->size[Y] * 0.36);
	(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
		0.2, (engine())->size[X] * (0.50 + x1), (engine())->size[Y] * 0.36);
	ft_print_color((engine())->size[X], (engine())->size[Y] / 2, 0,\
		(engine())->size[Y] / 2, (engine())->color[FLOOR]);
	if ((player())->turn_times)
		(player())->turn_times = 0;
	ft_fog(canva()->data);
}
