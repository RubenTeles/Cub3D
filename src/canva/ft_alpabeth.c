/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpabeth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:52:20 by rteles            #+#    #+#             */
/*   Updated: 2022/12/01 18:46:19 by rteles           ###   ########.fr       */
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

void	ft_put_word(char *str, t_aux aux, int option)
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
			(canva())->resize(letter, ft_aux(aux.larg, aux.alt, \
			aux.x + aux.larg * i, aux.y));
	}
	if (option == 1)
		free(str);
}
