/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_hand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:49:41 by rteles            #+#    #+#             */
/*   Updated: 2022/11/19 19:14:18 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

void	ft_hands(double move, int nice)
{
	t_data			*data;
	static int		a = 0;
	static double	x1 = 0.20;
	static double	x2 = 0.55;
	static double	y = 0.60;
	static int		count = 0;

	if (a == 1)
		move *= -1;
	x1 += move;
	x2 -= move;
	y += move;
	if (nice == 1)
		count = 1;
	if (count > 0)
	{
		count++;
		data = (canva())->sprite(NICE);
		if (!data)
			return ;
		(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
			0.4, (engine())->size[X] * 0.42, (engine())->size[Y] * 0.66);
		rev_resize_image(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
			0.4, (engine())->size[X] * 0.31, (engine())->size[Y] * 0.66);
		if (count == 15)
			count = 0;
		return ;
	}
	data = (canva())->sprite(HAND);
	if (!data)
		return ;
	(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
		0.4, (engine())->size[X] * x1, (engine())->size[Y] * y);
	rev_resize_image(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
		0.4, (engine())->size[X] * x2, (engine())->size[Y] * y);
	if (x1 > 0.21)//x1 > 0.24)
		a = 1;
	else if (x1 <= 0.20)
		a = 0;
}

void    ft_nice(double move)
{
    /*if (count > 35)
	{
		data = (canva())->sprite('n');
		if (!data)
			return ;
		(canva())->resize(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
			0.4, (engine())->size[X] * 0.42, (engine())->size[Y] * 0.66);
		rev_resize_image(data, (engine())->size[X] * 0.3, (engine())->size[Y] *\
			0.4, (engine())->size[X] * 0.31, (engine())->size[Y] * 0.66);
		if (count == 40)
			count = 0;
		return ;
	}*/
    (void)move;
    
    return ;
}