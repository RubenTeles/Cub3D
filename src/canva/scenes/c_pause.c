/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_pause.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:10:06 by rteles            #+#    #+#             */
/*   Updated: 2022/11/21 19:18:11 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>

void	ft_pause(double move, int option)
{
	(void)move;
	(void)option;
	ft_print_color((engine())->size[X] * 0.367, (engine())->size[Y] * 0.124,\
		 (engine())->size[X] * 0.315, (engine())->size[Y] * 0.340, 0X6b4324);
	ft_print_color((engine())->size[X] * 0.35, (engine())->size[Y] * 0.1,\
		 (engine())->size[X] * 0.322, (engine())->size[Y] * 0.351, 0xe6be7e);
	ft_put_word("PAUSE", (engine())->size[X] * 0.3, (engine())->size[Y] *\
		0.1, (engine())->size[X] * 0.347, (engine())->size[Y] * 0.348);
}
