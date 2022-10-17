/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:55:20 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/30 20:28:16 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str_util.h>

static int	___split_util(const char **str, char *div)
{
	int	j;
	int	i;

	while (ft_contains(*str, div) == 1)
		*str += ft_len(div);
	if (!*str || !div || !**str || !*div)
		return (0);
	i = 1;
	j = 0;
	while ((*str)[j] && i++)
	{
		while ((*str)[j] && ft_contains((*str) + j, div) != 1)
			j++;
		while ((*str)[j] && ft_contains((*str) + j, div) == 1)
			j += ft_len(div);
	}
	return (i);
}

char	**ft_split(const char *str, char *div)
{
	char	**arr;
	int		j;
	int		i;
	char	buf[60000];

	i = ___split_util(&str, div);
	if (!i)
		return (NULL);
	arr = malloc(sizeof(char *) * i);
	if (!arr)
		return (NULL);
	i = 0;
	while (*str)
	{
		j = 0;
		while (*str && ft_contains(str, div) != 1)
			buf[j++] = *str++;
		buf[j] = 0;
		arr[i++] = ft_copy(buf);
		while (*str && ft_contains(str, div) == 1)
			str += ft_len(div);
	}
	arr[i] = NULL;
	return (arr);
}

int	ft_atoi(const char *str)
{
	int	number;
	int	sign;

	sign = 1;
	number = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		number = (number * 10) + (*str - 48);
		str++;
	}
	return (number * sign);
}

char	*ft_trim(const char *str)
{
	int	size;

	if (!str)
		return (NULL);
	while (str && *str && ft_is_space(*str))
		str++;
	size = ft_len(str) - 1;
	while (size > 0 && str[size] && ft_is_space(str[size]))
		size--;
	return (ft_copy_n(str, size + 1));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	index;

	if (!s)
		return (NULL);
	if (!len || ft_len(s) < (int)start)
		return (NULL);
	if (ft_len(s) - start > len)
		ptr = (char *)malloc((len + 1) * sizeof(char));
	else
		ptr = (char *)malloc((ft_len(s) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	index = 0;
	while (index < len && s[start + index])
	{
		ptr[index] = s[start + index];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
