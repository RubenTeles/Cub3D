/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:39:43 by rteles            #+#    #+#             */
/*   Updated: 2022/10/10 01:08:39 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str_util.h>

int	ft_str_s_str(char *s1, char *s2)
{
	size_t	i;
	size_t	a;

	i = -1;
	if (!s1 || !s2)
		return (0);
	while (s1[++i])
	{
		a = -1;
		while (s2[++a])
		{
			if (s1[i] == s2[a])
				break ;
		}
		if (s1[i] == s2[a])
			continue ;
		return (0);
	}
	return (1);
}

int	ft_isalnum(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
			continue ;
		else
			return (0);
	}
	return (1);
}
