/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_hand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:49:41 by rteles            #+#    #+#             */
/*   Updated: 2022/11/22 16:04:54 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_scenes_images.h>

void	ft_animation_hand(double animation, t_data *data)
{
	static int		a = 0;
	static double	x1 = 0.20;
	static double	x2 = 0.55;
	static double	y = 0.60;

	if (a == 1)
		animation *= -1;
	x1 += animation;
	x2 -= animation;
	y += animation;
	if (data->title == HAND)
	{
		(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
			0.4, (engine())->size[X] * x1, (engine())->size[Y] * y);
		rev_resize_image(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
			0.4, (engine())->size[X] * x2, (engine())->size[Y] * y);
	}
	else if (data->title == NICE)
	{
		(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
			0.4, (engine())->size[X] * 0.42, (engine())->size[Y] * (0.06 + y));//0.66 + y));
		rev_resize_image(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
			0.4, (engine())->size[X] * 0.31, (engine())->size[Y] * (0.06 + y));
	}
	if (x1 > 0.21)
		a = 1;
	else if (x1 <= 0.20)
		a = 0;
}

void	ft_hands(t_scene_img *scene)
{
	static int		count = 0;
	static int		option = 0;
	t_data			*data;
	double			animation;

	animation = 0;
	if (scene)
	{
		option = scene->option;
		animation = scene->animation;
	}
	if (option >= 1 && !(engine())->pause && ++count)
	{
		if (option == 1)
			count = 1;
		if (++option && scene)
			scene->option = 2;
		(player())->sprite = (canva())->sprite(NICE);
	}
	if (count == 15)
	{
		count = 0;
		if (scene)
			scene->option = 0;
		option = 0;
		(player())->sprite = (canva())->sprite(HAND);
	}
	data = (player())->sprite;
	if (!data)
		return ;
	ft_animation_hand(animation, data);
}
