/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_background.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:23:46 by rteles            #+#    #+#             */
/*   Updated: 2022/11/30 19:21:46 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

int	put_clouds(t_data *img, int x, int pos_x)
{
	int	animation_x;

	animation_x = x + pos_x;
	if (img->title != CLOUD_1 && img->title != CLOUD_2 \
		&& img->title != CLOUD_3)
		return (animation_x);
	if (animation_x > (engine())->size[X])
		animation_x = animation_x - (engine())->size[X] - 1;
	return (animation_x);
}

void	ft_background_3(double x1, t_data *data)
{
	if (!data)
		return ;
	(canva())->resize(data, ft_aux((engine())->size[X] * 0.3, \
	(engine())->size[Y] * \
	0.2, (engine())->size[X] * (0.01 + x1), (engine())->size[Y] * -0.1));
	(canva())->resize(data, ft_aux((engine())->size[X] * 0.3, \
	(engine())->size[Y] * \
	0.2, (engine())->size[X] * (0.56 + x1), (engine())->size[Y] * 0.1));
	(canva())->resize(data, ft_aux((engine())->size[X] * 0.3, \
	(engine())->size[Y] * \
	0.2, (engine())->size[X] * (0.03 + x1), (engine())->size[Y] * 0.36));
	(canva())->resize(data, ft_aux((engine())->size[X] * 0.3, \
	(engine())->size[Y] * \
	0.2, (engine())->size[X] * (0.50 + x1), (engine())->size[Y] * 0.36));
	(canva())->color(ft_aux((engine())->size[X], \
	(engine())->size[Y] / 2, 0, \
		(engine())->size[Y] / 2), (engine())->color[FLOOR]);
}

void	ft_background_2(double x1, t_data *data)
{
	if (!data)
		return ;
	(canva())->resize(data, ft_aux((engine())->size[X] * 0.17, \
	(engine())->size[Y] * 0.15, (engine())->size[X] * (0.88 + x1), \
	(engine())->size[Y] * 0.30));
	(canva())->resize(data, ft_aux((engine())->size[X] * 0.17, \
	(engine())->size[Y] * \
		0.15, (engine())->size[X] * (0.395 + x1), (engine())->size[Y] * -0.02));
	ft_background_3(x1, (canva())->sprite(CLOUD_3));
	if ((player())->turn_times)
		(player())->turn_times = 0;
}

void	ft_background_1(t_data *data, double x1)
{
	(canva())->resize(data, ft_aux((engine())->size[X] * 0.17, \
	(engine())->size[Y] * \
		0.15, (engine())->size[X] * (0.80 + x1), (engine())->size[Y] * -0.08));
	(canva())->resize(data, ft_aux((engine())->size[X] * 0.17, \
	(engine())->size[Y] * \
	0.15, (engine())->size[X] * (0.05 + x1), (engine())->size[Y] * 0.15));
	(canva())->resize(data, ft_aux((engine())->size[X] * 0.19, \
	(engine())->size[Y] * \
		0.16, (engine())->size[X] * (0.33 + x1), (engine())->size[Y] * 0.25));
	ft_background_2(x1, (canva())->sprite(CLOUD_2));
	if ((all())->stop_weather != 3)
		ft_fog(canva()->data, (double)(engine())->time);
}

void	ft_background(t_scene_img *scene)
{
	t_data			*data;
	static double	x1 = 0;
	double			animation;

	animation = 0;
	if (scene)
		animation = scene->animation;
	x1 += animation + (player())->turn_times;
	if (x1 > 1)
		x1 = x1 - 1;
	if (x1 < 0)
		x1 = x1 + 1;
	(canva())->color(ft_aux((engine())->size[X], \
	(engine())->size[Y] / 2, 0, 0), (engine())->color[CEILLING]);
	data = (canva())->sprite(CLOUD_1);
	if (!data)
		return ;
	ft_background_1(data, x1);
}
