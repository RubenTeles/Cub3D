/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:04:23 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/19 17:50:02 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

int	ft_map_inf_filed(t_map *map, char *line)
{
	if (ft_check_line(line) == 1 && map->NO != NULL)
		return (1);
	else if (ft_check_line(line) == 2 && map->SO != NULL)
		return (2);
	else if (ft_check_line(line) == 3 && map->WE != NULL)
		return (3);
	else if (ft_check_line(line) == 4 && map->EA != NULL)
		return (4);
	else if (ft_check_line(line) == 5 && map->F != NULL)
		return (5);
	else if (ft_check_line(line) == 6 && map->C != NULL)
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
		str = list().get(map->map, i);
		while (*str)
		{
			if (*str == 'N' || *str == 'S' || *str == 'E' || *str == 'W')
			{
				if (player == -1)
					player = *str;
				else
					player = -2;
			}
			else if (!(*str == '0' || *str == '1' || string().is_spc(*str)))
				player = -3;
			str++;
		}
	}
	return (player);
}

int		ft_mapclosed(t_map *map)
{
	if (map)
		return (0);
	return (0);
}
