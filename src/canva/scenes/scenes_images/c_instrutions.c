/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_instrutions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:14:48 by rteles            #+#    #+#             */
/*   Updated: 2022/12/01 01:51:22 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

static void	ft_instrutions_words_2(void)
{
	(canva())->word("CLOSE GAME", ft_aux((engine())->size[X] * 0.23, \
	(engine())->size[Y] * 0.035, (engine())->size[X] * 0.68, \
	(engine())->size[Y] * 0.15), 0);
	(canva())->word("PAUSE", ft_aux((engine())->size[X] * 0.16, \
	(engine())->size[Y] * 0.035, (engine())->size[X] * 0.66, \
	(engine())->size[Y] * 0.28), 0);
	(canva())->word("TASKS", ft_aux((engine())->size[X] * 0.16, \
	(engine())->size[Y] * 0.035, (engine())->size[X] * 0.68, \
	(engine())->size[Y] * 0.43), 0);
	(canva())->word("MAP", ft_aux((engine())->size[X] * 0.10, \
	(engine())->size[Y] * 0.035, (engine())->size[X] * 0.66, \
	(engine())->size[Y] * 0.565), 0);
	(canva())->word("BREATH", ft_aux((engine())->size[X] * 0.18, \
	(engine())->size[Y] * 0.035, (engine())->size[X] * 0.7, \
	(engine())->size[Y] * 0.72), 0);
	(canva())->word("ATTACK", ft_aux((engine())->size[X] * 0.20, \
	(engine())->size[Y] * 0.035, (engine())->size[X] * 0.7, \
	(engine())->size[Y] * 0.76), 0);
}

static void	ft_instrutions_words(void)
{
	(canva())->word("MOVE", ft_aux((engine())->size[X] * 0.14, \
	(engine())->size[Y] * 0.035, (engine())->size[X] * 0.35, \
	(engine())->size[Y] * 0.16), 0);
	(canva())->word("RUN", ft_aux((engine())->size[X] * 0.10, \
	(engine())->size[Y] * 0.035, (engine())->size[X] * 0.33, \
	(engine())->size[Y] * 0.335), 0);
	(canva())->word("INTEREACT", ft_aux((engine())->size[X] * 0.28, \
	(engine())->size[Y] * 0.035, (engine())->size[X] * 0.245, \
	(engine())->size[Y] * 0.445), 0);
	(canva())->word("CHANGE THE", ft_aux((engine())->size[X] * 0.28, \
	(engine())->size[Y] * 0.035, (engine())->size[X] * 0.26, \
	(engine())->size[Y] * 0.54), 0);
	(canva())->word("WEATHER", ft_aux((engine())->size[X] * 0.20, \
	(engine())->size[Y] * 0.035, (engine())->size[X] * 0.265, \
	(engine())->size[Y] * 0.59), 0);
	(canva())->word("CLOSE", ft_aux((engine())->size[X] * 0.18, \
	(engine())->size[Y] * 0.035, (engine())->size[X] * 0.28, \
	(engine())->size[Y] * 0.72), 0);
	(canva())->word("ATTACK", ft_aux((engine())->size[X] * 0.20, \
	(engine())->size[Y] * 0.035, (engine())->size[X] * 0.28, \
	(engine())->size[Y] * 0.76), 0);
	ft_instrutions_words_2();
}

void	ft_instrutions(t_scene_img *scene)
{
	t_data	*data;

	(void)scene;
	(canva())->color(ft_aux((engine())->size[X] * 0.867, (engine())->size[Y] * \
	0.874, (engine())->size[X] * 0.063, (engine())->size[Y] * 0.040), 0X6b4324);
	(canva())->color(ft_aux((engine())->size[X] * 0.85, (engine())->size[Y] * \
	0.85, (engine())->size[X] * 0.07, (engine())->size[Y] * 0.051), 0xe6be7e);
	data = (canva())->sprite(INSTRUTIONS);
	if (!data)
		return ;
	(canva())->resize(data, ft_aux((engine())->size[X] * 0.8, \
	(engine())->size[Y] * 0.8, (engine())->size[X] * 0.1, \
	(engine())->size[Y] * 0.1));
	ft_instrutions_words();
}
