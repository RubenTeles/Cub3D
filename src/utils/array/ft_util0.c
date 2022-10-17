/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:54:12 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/30 20:21:31 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr_util.h>
#include <ft_string.h>

int	ft_arrlen(char **arr)
{
	int	i;

	if (!arr || !*arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**ft_create_arr(int len, ...)
{
	char	**arr;
	int		index;
	char	*str;
	va_list	ap;

	if (!len)
		return (NULL);
	va_start(ap, len);
	arr = malloc(sizeof(char *) * (len + 1));
	index = 0;
	while (index < len)
	{
		str = va_arg(ap, char *);
		if (str && *str)
			arr[index++] = string().cpy(str);
		else
			break ;
	}
	arr[index] = NULL;
	va_end(ap);
	return (arr);
}

char	**ft_add_arr(char **arr, char *str)
{
	char	**arr_c;
	int		i;

	if (!arr && !str)
		return (NULL);
	if (!str || !*str)
		return (arr);
	if (!arr)
		arr_c = malloc(sizeof(char *) * 2);
	else
		arr_c = malloc(sizeof(char *) * (ft_arrlen(arr) + 2));
	i = 0;
	while (arr && arr[i])
	{
		arr_c[i] = arr[i];
		i++;
	}
	arr_c[i++] = string().cpy(str);
	arr_c[i] = NULL;
	if (arr)
		free(arr);
	return (arr_c);
}

char	**ft_rmv_arr(char **arr, int index)
{
	int		i;
	int		j;
	char	**arr_c;

	if (!arr || !*arr || index < 0)
		return (arr);
	if (ft_arrlen(arr) <= 1 && index == 0)
		return (ft_free_arr(arr));
	if (ft_arrlen(arr) <= index)
		return (arr);
	arr_c = malloc(sizeof(char *) * ft_arrlen(arr));
	i = -1;
	j = 0;
	while (arr && arr[++i])
		if (i != index)
			arr_c[j++] = string().cpy(arr[i]);
	arr_c[j] = NULL;
	ft_free_arr(arr);
	return (arr_c);
}
