/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_menu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:48:44 by rteles            #+#    #+#             */
/*   Updated: 2022/11/29 14:42:50 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

void	ft_head_wolf_2(t_data *data)
{
	(canva())->resize(data, ft_aux((engine())->size[X] / data->larg * \
	(engine())->size[X] * 0.07, \
	(engine())->size[Y] / data->alt * (engine())->size[X] * 0.07, \
	(engine())->size[X] * 0.59, (engine())->size[Y] * 0.52));
}

void	ft_head_wolf(double move)
{
	t_data			*data;
	static double	animation = 0;

	animation += move;
	if (animation > 2)
		animation = 0;
	if (animation > 1)
		return ;
	data = (canva())->sprite(AVATAR);
	if (!data)
		return ;
	if ((engine())->menu == 1)
		(canva())->resize(data, ft_aux((engine())->size[X] / data->larg * \
		(engine())->size[X] * 0.07, \
		(engine())->size[Y] / data->alt * (engine())->size[X] * 0.07,
		(engine())->size[X] * 0.24, (engine())->size[Y] * 0.36));
	else if ((engine())->menu == 2)
		ft_head_wolf_2(data);
	else if ((engine())->menu == 3)
		(canva())->resize(data, ft_aux(\
		(engine())->size[X] / data->larg * (engine())->size[X] * 0.07, \
		(engine())->size[Y] / data->alt * (engine())->size[X] * 0.07, \
		(engine())->size[X] * 0.21, (engine())->size[Y] * 0.71));
}

void	ft_start_word(char *str, t_aux aux)
{
	int		i;
	int		len;
	t_data	*letter;

	len = (string()).len(str);
	i = -1;
	aux.larg = aux.larg / len;
	while (str[++i])
	{
		letter = ft_alphabet(str[i]);
		if (letter)
			(canva())->resize(letter, ft_aux(aux.larg, aux.alt, aux.x + \
			aux.larg * i, aux.y - (engine())->size[Y] * (0.01 * i)));
	}
}

void	ft_words_menu(void)
{
	ft_start_word("START", ft_aux((engine())->size[X] * 0.24, \
	(engine())->size[Y] * 0.1, (engine())->size[X] * 0.37, \
	(engine())->size[Y] * 0.36));
	(canva())->word("MAPS", ft_aux((engine())->size[X] * 0.24, \
	(engine())->size[Y] * 0.1, (engine())->size[X] * 0.36, \
	(engine())->size[Y] * 0.55), 0);
	(canva())->word("INSTRUCTIONS", ft_aux((engine())->size[X] * 0.29, \
	(engine())->size[Y] * 0.1, (engine())->size[X] * 0.34, \
	(engine())->size[Y] * 0.72), 0);
	(canva())->color(ft_aux((engine())->size[X] * 0.377, (engine())->size[Y] * \
	0.0445, (engine())->size[X] * 0.011, (engine())->size[Y] * 0.941), \
	0X6b4324);
	(canva())->color(ft_aux((engine())->size[X] * 0.37, (engine())->size[Y] * \
	0.032, (engine())->size[X] * 0.013, (engine())->size[Y] * 0.948), 0xe6be7e);
	(canva())->word("MADE BY RTELES AMARIA/M", ft_aux((engine())->size[X] * \
	0.35, (engine())->size[Y] * 0.03, (engine())->size[X] * 0.022, \
	(engine())->size[Y] * 0.949), 0);
}

void	ft_initial_menu(t_scene_img *scene)
{
	t_data	*data;
	double	animation;

	(void)scene;
	animation = 0;
	data = (canva())->sprite(MENU);
	if (!data)
		return ;
	(canva())->resize(data, ft_aux((engine())->size[X], (engine())->size[Y], \
		0, 0));
	data = (canva())->sprite(SIGN);
	if (!data)
		return ;
	(canva())->resize(data, ft_aux((engine())->size[X] * 0.4, \
	(engine())->size[Y] * 0.8, (engine())->size[X] * 0.3, \
	(engine())->size[Y] * 0.22));
	ft_words_menu();
	ft_head_wolf(animation);
}
