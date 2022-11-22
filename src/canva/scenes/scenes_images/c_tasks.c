/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_tasks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:27:32 by rteles            #+#    #+#             */
/*   Updated: 2022/11/22 18:43:30 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

void	ft_tasks(t_scene_img *scene)
{
	(void)scene;
	ft_print_color((engine())->size[X] * 0.212, (engine())->size[Y] * 0.456,\
		(engine())->size[X] * 0.021, (engine())->size[Y] * 0.351, 0X6b4324);
	ft_print_color((engine())->size[X] * 0.205, (engine())->size[Y] * 0.444,\
		(engine())->size[X] * 0.024, (engine())->size[Y] * 0.357, 0xe6be7e);
	ft_put_word("TASKS", (engine())->size[X] * 0.10, (engine())->size[Y] *\
		0.03, (engine())->size[X] * 0.077, (engine())->size[Y] * 0.376);
	ft_put_word("PIGS", (engine())->size[X] * 0.08, (engine())->size[Y] *\
		0.02, (engine())->size[X] * 0.030, (engine())->size[Y] * 0.456);
	ft_put_word("0", (engine())->size[X] * 0.02, (engine())->size[Y] *\
		0.02, (engine())->size[X] * 0.130, (engine())->size[Y] * 0.456);
	ft_put_word("/", (engine())->size[X] * 0.02, (engine())->size[Y] *\
		0.02, (engine())->size[X] * 0.150, (engine())->size[Y] * 0.456);
	ft_put_word("0", (engine())->size[X] * 0.02, (engine())->size[Y] *\
		0.02, (engine())->size[X] * 0.170, (engine())->size[Y] * 0.456);
}
