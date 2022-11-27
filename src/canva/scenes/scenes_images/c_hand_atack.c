/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_hand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:12:20 by rteles            #+#    #+#             */
/*   Updated: 2022/11/27 16:13:23 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_scenes_images.h>

void	ft_animation_atack(t_data *data, double x1, double x2, double y)
{
	static int	a = 0;
	static int	loop = 0;

	if ((player())->sprite->title == ATACK_4)
		loop = 1;
	if ((player())->sprite->title == ATACK_1 && loop == 1)
	{
		loop = 0;
		if (a)
			a--;
		else
			a++;
	}
	if (!a)
		(canva())->resize(data, ft_aux((engine())->size[X] * 0.3, \
		(engine())->size[Y] * 0.4, (engine())->size[X] * x1, \
		(engine())->size[Y] * y));
	else
		(canva())->rvresize(data, ft_aux((engine())->size[X] * 0.3, \
		(engine())->size[Y] * 0.4, (engine())->size[X] * x2, \
		(engine())->size[Y] * y));
}
