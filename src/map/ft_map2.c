/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:04:23 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/18 18:57:43 by amaria-m         ###   ########.fr       */
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