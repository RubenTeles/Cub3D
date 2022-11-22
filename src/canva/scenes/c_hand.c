/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_hand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:49:41 by rteles            #+#    #+#             */
/*   Updated: 2022/11/22 10:02:21 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_scenes.h>

void	ft_animation_hand(t_scene *scene, t_data *data)
{
	static int		a = 0;
	static double	x1 = 0.20;
	static double	x2 = 0.55;
	static double	y = 0.60;

	if (a == 1 && a--)
		scene->animation *= -1;
	x1 += scene->animation;
	x2 -= scene->animation;
	y += scene->animation;
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
	if (x1 > 0.21 || x1 <= 0.20)
		a = 1;
}

void	ft_hands(t_scene *scene)
{
	t_data			*data;
	static int		count = 0;

	if (scene->option == 1 && ++count)
		(player())->sprite = (canva())->sprite(NICE);
	if (count == 15)
	{
		count = 0;
		scene->option = 0;
		(player())->sprite = (canva())->sprite(HAND);
	}
	data = (player())->sprite;
	if (!data)
		return ;
	ft_animation_hand(scene, data);
}
