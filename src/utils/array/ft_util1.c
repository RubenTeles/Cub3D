/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:54:19 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/22 18:39:51 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arr_util.h>
#include <ft_string.h>

char	**ft_copy_arr(char **arr)
{
	char	**arr_c;
	int		i;

	if (!arr || !*arr)
		return (NULL);
	arr_c = malloc(sizeof(char *) * (ft_arrlen(arr) + 1));
	i = 0;
	while (arr && arr[i])
	{
		arr_c[i] = string().cpy(arr[i]);
		i++;
	}
	arr_c[i] = NULL;
	return (arr_c);
}

char	**ft_copy_n_arr(char **arr, int len)
{
	char	**arr_c;
	int		i;

	if (!arr || !*arr || len < 1)
		return (NULL);
	if (len > ft_arrlen(arr))
		arr_c = malloc(sizeof(char *) * (ft_arrlen(arr) + 1));
	else
		arr_c = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (arr && arr[i] && i < len)
	{
		arr_c[i] = string().cpy(arr[i]);
		i++;
	}
	arr_c[i] = NULL;
	return (arr_c);
}

char	**ft_arr_iter(char **arr, char *(*f)(const char *str))
{
	int		i;
	char	*mem;

	if (!arr || !*arr || !f)
		return (arr);
	i = 0;
	while (arr && arr[i])
	{
		mem = arr[i];
		arr[i] = f(arr[i]);
		if (arr[i] != mem)
			free(mem);
		i++;
	}
	return (arr);
}

char	**ft_arr_set(char **arr, char *str, int index)
{
	if (!arr || !*arr || !str || !*str)
		return (arr);
	if (index < 0 || ft_arrlen(arr) <= index)
		return (arr);
	free(arr[index]);
	arr[index] = str;
	return (arr);
}
