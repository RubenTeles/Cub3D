/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_end_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 01:15:47 by rteles            #+#    #+#             */
/*   Updated: 2022/12/05 19:16:42 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

void	ft_you_die(t_scene_img *scene)
{
	(void)scene;
	(canva())->color(ft_aux((engine())->size[X] * 0.367, (engine())->size[Y] * \
	0.334, (engine())->size[X] * 0.315, (engine())->size[Y] * 0.340), 0X6b4324);
	(canva())->color(ft_aux((engine())->size[X] * 0.35, (engine())->size[Y] * \
	0.31, (engine())->size[X] * 0.322, (engine())->size[Y] * 0.351), 0xe6be7e);
	(canva())->word("YOU ARE DEAD", ft_aux((engine())->size[X] * 0.3, \
	(engine())->size[Y] * 0.1, (engine())->size[X] * 0.347, \
	(engine())->size[Y] * 0.358), 0);
	(canva())->word("TO CONTINUE", ft_aux((engine())->size[X] * 0.20, \
	(engine())->size[Y] * 0.08, (engine())->size[X] * 0.387, \
	(engine())->size[Y] * 0.508), 0);
	(canva())->word("PRESS ENTER", ft_aux((engine())->size[X] * 0.15, \
	(engine())->size[Y] * 0.05, (engine())->size[X] * 0.417, \
	(engine())->size[Y] * 0.608), 0);
}

void	ft_end_game(t_scene_img *scene)
{
	t_data	*data;

	(canva())->color(ft_aux((engine())->size[X] * 0.367, (engine())->size[Y] * \
	0.334, (engine())->size[X] * 0.315, (engine())->size[Y] * 0.340), 0X6b4324);
	(canva())->color(ft_aux((engine())->size[X] * 0.35, (engine())->size[Y] * \
	0.31, (engine())->size[X] * 0.322, (engine())->size[Y] * 0.351), 0xe6be7e);
	if (scene && scene->option == 1)
		(canva())->word("YOU WIN!", ft_aux((engine())->size[X] * 0.3, \
	(engine())->size[Y] * 0.1, (engine())->size[X] * 0.347, \
	(engine())->size[Y] * 0.348), 0);
	else
		(canva())->word("YOU LOSE", ft_aux((engine())->size[X] * 0.3, \
	(engine())->size[Y] * 0.1, (engine())->size[X] * 0.347, \
	(engine())->size[Y] * 0.358), 0);
	(canva())->word("PRESS ESC", ft_aux((engine())->size[X] * 0.15, \
	(engine())->size[Y] * 0.05, (engine())->size[X] * 0.417, \
	(engine())->size[Y] * 0.608), 0);
	if (scene && scene->option == 1)
		data = (canva())->sprite(AVATAR);
	else
		data = (canva())->sprite(AVATAR_2);
	(canva())->resize(data, ft_aux((engine())->size[X] * 0.068, \
	(engine())->size[Y] * 0.08, (engine())->size[X] * 0.454, \
	(engine())->size[Y] * 0.487));
}
