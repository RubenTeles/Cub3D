/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:55:07 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/30 20:26:58 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str_util.h>

int	ft_compare(const char *str1, const char *str2)
{
	int	i;

	if (!str1 || !str2)
		return (0);
	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] == str2[i]);
}

int	ft_compare_n(const char *str1, const char *str2, int n)
{
	int	i;

	if (!str1 || !str2)
		return (0);
	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
	{
		i++;
		if (i == n)
			return (1);
	}
	return (0);
}

int	ft_is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == ' ');
}

char	*ft_join(const char *str1, const char *str2)
{
	char	*str;
	int		i;

	str = malloc(ft_len((char *) str1) \
	+ ft_len((char *) str2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (str1 && *str1)
		str[i++] = *str1++;
	while (str2 && *str2)
		str[i++] = *str2++;
	str[i] = 0;
	return (str);
}

char	*ft_replace(const char *str1, const char *str2, const char *hey)
{
	int		i;
	char	*r;
	char	*temp;

	i = ft_contains(str1, hey);
	r = NULL;
	if (!i)
		return ((char *) str1);
	i--;
	r = ft_copy_n(str1, i);
	str1 += (i + ft_len(hey));
	temp = r;
	r = ft_join(r, str2);
	free(temp);
	temp = r;
	r = ft_join(r, str1);
	free(temp);
	return (r);
}
