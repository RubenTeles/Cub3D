/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_menu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:48:44 by rteles            #+#    #+#             */
/*   Updated: 2022/11/08 19:06:55 by rteles           ###   ########.fr       */
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
	/*data = (canva())->sprite(AVATAR);
	if (!data)
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
void	ft_start_word(char *str, double larg, double alt, int pos_x, int pos_y)
{
	int	i;
	int	len;
	t_data	*letter;
	
	len = (string()).len(str);
	i = -1;
	larg = larg / len;
	while (str[++i])
	{
		letter = ft_alphabet(str[i]);
		if (letter)
			(canva())->resize(letter, larg, alt, pos_x + larg * i, pos_y -\
				(engine())->size[Y] * (0.01 * i));
	}
}

void	ft_words_menu(void)
{
	ft_start_word("START", (engine())->size[X] * 0.24, (engine())->size[Y] *\
		0.1, (engine())->size[X] * 0.37, (engine())->size[Y] * 0.36);
	ft_put_word("MAPS", (engine())->size[X] * 0.24, (engine())->size[Y] *\
		0.1, (engine())->size[X] * 0.36, (engine())->size[Y] * 0.55);
	ft_put_word("INSTRUCTIONS", (engine())->size[X] * 0.29, (engine())->size[Y] *\
		0.1, (engine())->size[X] * 0.34, (engine())->size[Y] * 0.72);
	ft_put_word("E", (engine())->size[X] * 0.05, (engine())->size[Y] *\
		0.05, (engine())->size[X] * 0.44, (engine())->size[Y] * 0.01);
	ft_put_word("A", (engine())->size[X] * 0.05, (engine())->size[Y] *\
		0.05, (engine())->size[X] * 0.48, (engine())->size[Y] * 0.01);
	ft_put_word("T", (engine())->size[X] * 0.055, (engine())->size[Y] *\
		0.055, (engine())->size[X] * 0.52, (engine())->size[Y] * 0.01);
	ft_put_word("WOLF    PIGS", (engine())->size[X] * 0.60, (engine())->size[Y] *\
		0.1, (engine())->size[X] * 0.22, (engine())->size[Y] * 0.02);
	ft_print_color((engine())->size[X] * 0.377, (engine())->size[Y] *\
		0.0445, (engine())->size[X] * 0.011, (engine())->size[Y] * 0.941, 0X6b4324);
	ft_print_color((engine())->size[X] * 0.37, (engine())->size[Y] *\
		0.032, (engine())->size[X] * 0.013, (engine())->size[Y] * 0.948, 0X467527);
	ft_put_word("MADE BY RTELES AMARIA/M", (engine())->size[X] * 0.35, (engine())->size[Y] *\
		0.03, (engine())->size[X] * 0.022, (engine())->size[Y] * 0.949);
}
