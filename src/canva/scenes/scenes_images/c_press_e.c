/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_press_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:25:21 by rteles            #+#    #+#             */
/*   Updated: 2022/11/28 19:18:33 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

void	ft_press_e(t_scene_img *scene)
{
	(void)scene;
	(canva())->color(ft_aux((engine())->size[X] * 0.112, (engine())->size[Y] * \
	0.046, (engine())->size[X] * 0.021, (engine())->size[Y] * 0.261), 0X6b4324);
	(canva())->color(ft_aux((engine())->size[X] * 0.105, (engine())->size[Y] * \
	0.034, (engine())->size[X] * 0.024, (engine())->size[Y] * 0.267), 0X7BB905);
	(canva())->word("PRESS E", ft_aux((engine())->size[X] * 0.10, \
	(engine())->size[Y] * 0.03, (engine())->size[X] * 0.027, \
	(engine())->size[Y] * 0.266), 0);
}
