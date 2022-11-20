/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpabeth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:52:20 by rteles            #+#    #+#             */
/*   Updated: 2022/11/19 21:17:25 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

/*t_data	*create_alphabet(char c)
{
	t_data	*letter;

	letter = malloc(sizeof(t_data));
	if (!letter)
		return (0);
	letter->title = c;
	letter->path = path_alphabet(c);
	letter->img = mlx_xpm_file_to_image((engine())->ptr, letter->path,\
		&letter->larg, &letter->alt);
	if (!letter->img)
	{
		printf("Erro: '%c' não existe!\n", c);
		free(letter);
		return (0);
	}
	letter->addr = mlx_get_data_addr(letter->img, &letter->bits_per_pixel,\
		&letter->line_length, &letter->endian);
	letter->next = NULL;
	if ((canva())->search((canva())->alphabet, c))
		(canva())->last((canva())->alphabet)->next = letter;
	else
		(canva())->alphabet = letter;
	return (letter);
}*/

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
			(canva())->resize(letter, larg, alt, pos_x + larg * i, pos_y);
	}
}
