/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:18:02 by rteles            #+#    #+#             */
/*   Updated: 2022/09/29 23:38:05 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str_util.h>

char	*replace_str(char *str1, char *str2)
{
	free(str1);
	return (ft_copy(str2));
}

int	index_char(char *str, char c)
{
	int	i;

	i = -1;
	if (!str || !c)
		return (-1);
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*split_two_str(char *str, char c, int option)
{
	int	index;
	int	len;

	if (!str || !c)
		return (0);
	index = index_char(str, c);
	if (index == -1 && option == 0)
		return (ft_copy(str));
	else if (index == -1 && option == 1)
		return (0);
	len = (ft_len(str));
	if (option == 0)
		return (ft_substr(str, 0, index));
	return (ft_substr(str, index + 1, len - (index + 1)));
}

int	ft_atoi(char *str)
{
	int			i;
	int			s;
	long long	n;

	i = 0;
	s = 1;
	n = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		if (n * s > 2147483647)
			return (-1);
		else if (n * s < -2147483648)
			return (0);
		i++;
	}
	return (n * s);
}

char	*ft_string_in_two_char(char *str, char c1, char c2)
{
	int	i;
	int	start;
	int	end;

	i = -1;
	start = -1;
	end = -1;
	while (str[++i])
	{
		if (start < 0 && str[i] == c1)
			start = i;
		else if (end < 0 && str[i] == c2)
			end = i;
	}
	if (start < 0)
		return (0);
	if (end > -1)
		return (ft_substr(str, start, end - (start)));
	return (ft_substr(str, start, ft_len(str) - (start)));
}
