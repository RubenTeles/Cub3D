/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_background.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:23:46 by rteles            #+#    #+#             */
/*   Updated: 2022/11/03 17:07:01 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

void	ft_background(void)
{
	ft_print_color((engine())->size[X], (engine())->size[Y] / 2, 0,\
		0, (engine())->color[CEILLING]);
	ft_print_color((engine())->size[X], (engine())->size[Y] / 2, 0,\
		(engine())->size[Y] / 2, (engine())->color[FLOOR]);	
}

void	ft_hands(void)
{
	t_data	*data;

	data = (canva())->sprite('H');
	if (!data)
		return ;
	(canva())->resize(data, data->larg, data->alt,\
		(engine())->size[X] * 0.32, (engine())->size[Y] * 0.67);
}
