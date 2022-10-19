/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:50:26 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/19 17:41:01 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	ft_init_map_info(t_map *map)
{
	map->map = NULL;
	map->NO = NULL;
	map->SO = NULL;
	map->WE = NULL;
	map->EA = NULL;
	map->F = NULL;
	map->C = NULL;
}

int	ft_check_map_info(t_map *map)
{
	if (!map->map)
		return (1);
	if (!map->NO)
		return (2);
	if (!map->SO)
		return (3);
	if (!map->WE)
		return (4);
	if (!map->EA)
		return (5);
	if (!map->F)
		return (6);
	if (!map->C)
		return (7);
	return (0);
}

t_list	*ft_del_w_spc(t_list *map, int j)
{
	int		i;
	char	*str;

	if (!map)
		return (NULL);
	i = -1;
	while (list().get(map, ++i) && i < j)
	{
		str = string().trim(list().get(map, i));
		if (!str || !string().len(str))
		{
			map = list().rmv(map, i--);
			j--;
		}	
		free(str);
	}
	return (map);
}

t_map	*ft_checker(int argc, char **argv)
{
	t_map	*map;
	char	*str;
	int		i;

	map = malloc(sizeof(t_map));
	ft_init_map_info(map);
	if (argc == 1)
		return (map);
	map->map = ft_read_map(argv[1]);
	if (!map->map)
		return (map);
	i = -1;
	while (list().get(map->map, ++i))
	{
		str = string().trim(list().get(map->map, i));
		if (string().len(str) && ft_check_line(str) == 0)
		{
			free(str);
			break ;
		}
		if (string().len(str) && ft_is_path(str) && !ft_map_inf_filed(map, str))
			ft_choose_inf_elm(map, str);
		else if (string().len(str) && ft_is_color(str) && !ft_map_inf_filed(map, str))
			ft_choose_inf_elm(map, str);
		else if (string().len(str))
		{
			free(str);
			break ;
		}
		free(str);
	}
	map->map = ft_del_w_spc(map->map, i);
	return (map);
}

void	ft_free_map_inf(t_map *map)
{
	list().free(map->map);
	free(map->NO);
	free(map->SO);
	free(map->WE);
	free(map->EA);
	array().free(map->C);
	array().free(map->F);
	free(map);
}
