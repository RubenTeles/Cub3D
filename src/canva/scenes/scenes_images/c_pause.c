/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_pause.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:10:06 by rteles            #+#    #+#             */
/*   Updated: 2022/12/01 01:15:57 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

void	ft_pause(t_scene_img *scene)
{
	(void)scene;
	(canva())->color(ft_aux((engine())->size[X] * 0.367, (engine())->size[Y] * \
	0.124, (engine())->size[X] * 0.315, (engine())->size[Y] * 0.340), 0X6b4324);
	(canva())->color(ft_aux((engine())->size[X] * 0.35, (engine())->size[Y] * \
	0.1, (engine())->size[X] * 0.322, (engine())->size[Y] * 0.351), 0xe6be7e);
	(canva())->word("PAUSE", ft_aux((engine())->size[X] * 0.3, \
	(engine())->size[Y] * 0.1, (engine())->size[X] * 0.347, \
	(engine())->size[Y] * 0.348), 0);
}
