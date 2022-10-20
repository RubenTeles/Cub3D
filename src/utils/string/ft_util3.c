/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:41:10 by rteles            #+#    #+#             */
/*   Updated: 2022/10/10 01:29:43 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str_util.h>

static int	ft_power(int n)
{
	int	p;

	p = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		p++;
	}
	return (p);
}

static char	*ft_mkitoax(int n, int i, int h)
{
	char	*str;

	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[i] = '\0';
	i--;
	if (h == 2)
	{
		str[i] = '8';
		h--;
		i--;
	}
	while (0 + h <= i)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (h == 1)
		str[i] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	if (n < 0)
	{
		n *= -1;
		if (n == -2147483648)
			return (ft_mkitoax(214748364, 11, 2));
		return (ft_mkitoax(n, ft_power(n) + 1, 1));
	}
	else
		return (ft_mkitoax(n, ft_power(n), 0));
}

char	*ft_strrchr(const char *string, int c)
{
	int		i;
	char	*rstr;

	i = 0;
	while (string[i])
		i++;
	rstr = (char *)string;
	while (i >= 0)
	{
		if (rstr[i] == (unsigned char)c)
			return (&rstr[i]);
		i--;
	}
	return (0);
}

char	*ft_strchr(const char *string, int c)
{
	int		i;
	char	*rtstr;

	i = 0;
	rtstr = (char *)string;
	while (rtstr[i])
	{
		if (rtstr[i] == (unsigned char)c)
			return (&rtstr[i]);
		i++;
	}
	if (rtstr[i] == c)
		return (&rtstr[i]);
	return (0);
}
