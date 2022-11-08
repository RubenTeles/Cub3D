/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_menu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:48:44 by rteles            #+#    #+#             */
/*   Updated: 2022/11/07 18:44:41 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

#define MENU 'A'
#define SIGN 'U'
#define AVATAR 'X'

void	ft_initial_menu(double move)
{
	t_data			*data;
	//static double	x1 = 0;
	//static double	y1 = 0;
	(void)move;

	data = (canva())->sprite(MENU);
	if (!data)
		return ;
	(canva())->resize(data, (engine())->size[X], (engine())->size[Y],\
		0, 0);

	data = (canva())->sprite(SIGN);
	if (!data)
		return ;
	(canva())->resize(data, (engine())->size[X] * 0.4, (engine())->size[Y] * 0.8,\
		(engine())->size[X] * 0.3, (engine())->size[Y] * 0.22);
	
	data = (canva())->sprite(AVATAR);
	/*if (!data)
		return ;
	if ((engine())->size[X] / data->larg * (engine())->size[X] * x1 < (engine())->size[X])
	x1 += move;
	if ((engine())->size[X] / data->larg * (engine())->size[X] * move < 0)
		x1 = 0;
	(canva())->resize(data,\
		(engine())->size[X] / data->larg * (engine())->size[X] * 0.07,\
		(engine())->size[Y]/ data->alt * (engine())->size[X] * 0.07,\
		(engine())->size[X] * 0.36, (engine())->size[Y] * 0.37);*/
		//(engine())->size[X] / 2, (engine())->size[Y] / 2);
}
