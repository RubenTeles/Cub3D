/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:59:28 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/22 19:15:14 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	ft_free_map_inf(t_map *map)
{
	list().free(map->map);
	free(map->no);
	free(map->so);
	free(map->we);
	free(map->ea);
	array().free(map->c);
	array().free(map->f);
	free(map);
}

char	**ft_lst_toarr(t_list *lst)
{
	char	**arr;
	char	*str;
	int		max_pos;
	int		i;

	i = -1;
	arr = NULL;
	while (++ i < list().len(lst))
	{
		str = list().get(lst, i);
		str = string().cpy_n(str, string().len(str) - 1);
		arr = array().add(arr, str);
	}
	i = 0;
	max_pos = 0;
	while (arr[++i])
		if (string().len(arr[max_pos]) < string().len(arr[i]))
			max_pos = i;
	i = -1;
	while (arr[++i])
		while (string().len(arr[i]) < string().len(arr[max_pos]))
			arr[i] = string().replace(arr[i], string().join(arr[i], " "));
	return (arr);
}
