/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpabeth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:52:20 by rteles            #+#    #+#             */
/*   Updated: 2022/11/27 12:28:41 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

t_data	*ft_alphabet(char c)
{
	t_data	*data;
	int		letter;

	letter = c;
	if (!((letter >= 47 && letter <= 57) || (letter >= 65 && letter <= 90)))
		return (0);
	(canva())->create_data(letter, letter);
	data = &(canva())->data[letter];
	if (!data)
	{
		if (c == ' ')
			return (0);
		printf("Erro: '%c' não existe!\n", c);
		return (0);
	}
	return (data);
}

void	ft_put_word(char *str, double larg, double alt, int pos_x, int pos_y)
{
	int		i;
	int		len;
	t_data	*letter;

	len = (string()).len(str);
	i = -1;
	larg = larg / len;
	while (str[++i])
	{
		letter = ft_alphabet(str[i]);
		if (letter)
			(canva())->resize(letter, larg, alt, pos_x + larg * i, pos_y);
	}
}
