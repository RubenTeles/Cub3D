/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:59:28 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/25 11:31:25 by amaria-m         ###   ########.fr       */
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

int	ft_free_all(t_all all)
{
	ft_free_map_inf(all.file);
	array().free(all.pieces->board);
	list().free(all.pieces->pigs);
	free(all.pieces);
	return (1);
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
		free(str);
	}
	i = 0;
	max_pos = 0;
	while (arr[++i])
		if (string().len(arr[max_pos]) < string().len(arr[i]))
			max_pos = i;
	i = -1;
	while (arr[++i])
		while (string().len(arr[i]) < string().len(arr[max_pos]))
			arr = (array().set)(arr, string().join(arr[i], " "), i);
	return (arr);
}

char	*ft_map_error(int i)
{
	if (i == 1)
		return ("Problem reading file");
	else if (i == 2)
		return ("Problem with NO image");
	else if (i == 3)
		return ("Problem with SO image");
	else if (i == 4)
		return ("Problem with WE image");
	else if (i == 5)
		return ("Problem with EA image");
	else if (i == 6)
		return ("Problem with F(floor colors) info");
	else if (i == 7)
		return ("Problem with C(ceiling colors) info");
	else if (i == -1)
		return ("There's no player in map");
	else if (i == -2)
		return ("There's two players in map");
	else if (i == -3)
		return ("Map contains invalid characters");
	else
		return ("General error");
}
