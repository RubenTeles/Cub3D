/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:04:23 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/27 16:30:49 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	ft_map_inf_filed(t_map *map, char *line)
{
	if (ft_check_line(line) == 1 && map->no != NULL)
		return (1);
	else if (ft_check_line(line) == 2 && map->so != NULL)
		return (2);
	else if (ft_check_line(line) == 3 && map->we != NULL)
		return (3);
	else if (ft_check_line(line) == 4 && map->ea != NULL)
		return (4);
	else if (ft_check_line(line) == 5 && map->f != NULL)
		return (5);
	else if (ft_check_line(line) == 6 && map->c != NULL)
		return (6);
	else
		return (0);
}

int	ft_checkplayer(t_map *map)
{
	char	*str;
	int		player;
	int		i;

	i = -1;
	while (++i < 6)
		map->map = list().rmv(map->map, 0);
	player = -1;
	i = -1;
	while (list().get(map->map, ++i))
	{
		str = list().get(map->map, i) - 1;
		while (*(++str))
		{
			if (string().index_char("NSEW", *str) >= 0 && player == -1)
				player = *str;
			else if (string().index_char("NSEW", *str) >= 0 && player != -1)
				player = -2;
			else if (!(*str == '0' || *str == '1' || string().is_spc(*str)))
				player = -3;
		}
	}
	return (player);
}

t_map	*ft_check_map(int argc, char **argv)
{
	t_map	*map;
	int		map_info;
	int		check_player;

	map = ft_checker(argc, argv);
	map_info = ft_check_map_info(map);
	if (map_info)
	{
		printf("Error\n%s\n", ft_map_error(map_info));
		ft_free_map_inf(map);
		return (NULL);
	}	
	check_player = ft_checkplayer(map);
	if (check_player < 0)
	{
		printf("Error\n%s\n", ft_map_error(check_player));
		ft_free_map_inf(map);
		return (NULL);
	}
	if (ft_mapclosed(map))
		return (NULL);
	return (map);
}

t_pos	ft_player_pos(t_list *board)
{
	char	*str;
	t_pos	pos;
	int		i;

	i = -1;
	pos.y = -1;
	while (list().get(board, ++i))
	{
		pos.x = i;
		str = list().get(board, i);
		if (string().contains(str, "N"))
			pos.y = string().index_char(str, 'N');
		if (string().contains(str, "S"))
			pos.y = string().index_char(str, 'S');
		if (string().contains(str, "E"))
			pos.y = string().index_char(str, 'E');
		if (string().contains(str, "W"))
			pos.y = string().index_char(str, 'W');
		if (pos.y != -1)
			break ;
	}
	return (pos);
}

int	ft_find_paths(t_map *map, t_pos atual)
{
	int		check;
	t_pos	next;

	check = ft_nextpos(map->map, atual, &next);
	while (check == 1)
	{
		if (ft_find_paths(map, next) == 0)
			return (0);
		check = ft_nextpos(map->map, atual, &next);
	}
	if (check == 2)
		return (1);
	return (0);
}
