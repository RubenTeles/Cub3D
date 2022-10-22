/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:50:26 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/22 18:00:16 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	ft_init_map_info(t_map *map)
{
	map->map = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = NULL;
	map->c = NULL;
}

int	ft_check_map_info(t_map *map)
{
	if (!map->map)
		return (1);
	if (!map->no)
		return (2);
	if (!map->so)
		return (3);
	if (!map->we)
		return (4);
	if (!map->ea)
		return (5);
	if (!map->f)
		return (6);
	if (!map->c)
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

int	ft_checkerblock(t_map *map, int i)
{
	char	*str;

	str = string().trim(list().get(map->map, i));
	if (string().len(str) && ft_check_line(str) == 0)
	{
		free(str);
		return (1);
	}
	if (string().len(str) && ft_is_path(str) && !ft_map_inf_filed(map, str))
		ft_choose_inf_elm(map, str);
	else if (string().len(str) && ft_is_color(str) && \
	!ft_map_inf_filed(map, str))
		ft_choose_inf_elm(map, str);
	else if (string().len(str))
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

t_map	*ft_checker(int argc, char **argv)
{
	t_map	*map;
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
		if (ft_checkerblock(map, i))
			break ;
	map->map = ft_del_w_spc(map->map, i);
	return (map);
}
