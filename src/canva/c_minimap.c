/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:00:10 by rteles            #+#    #+#             */
/*   Updated: 2022/11/05 23:08:27 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

#define MINIMAP 'm'

void	ft_minimap(void)
{
	t_data	*data;

	data = (canva())->sprite(MINIMAP);
	if (!data)
		return ;
    (canva())->resize(data, (engine())->size[X] * 0.30, (engine())->size[Y] *\
		0.3, (engine())->size[X] * 0.70, (engine())->size[Y] * 0.00);
}
