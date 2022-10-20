/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:39:56 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/19 17:47:30 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	*ft_print_lst(void *ptr)
{
	printf("%s", (char*)ptr);
	return (ptr);
}

t_map	*ft_check_map(int argc, char **argv)
{
	t_map	*map;
	int		map_info;
	int		check_player;
	int		map_closed;

	map = ft_checker(argc, argv);
	map_info = ft_check_map_info(map);
	if (map_info)
	{
		printf("Error\n%i\n", map_info);
		ft_free_map_inf(map);
		return (NULL);
	}	
	check_player = ft_checkplayer(map);
	if (check_player < 0)
	{
		printf("Error\n%i\n", check_player);
		ft_free_map_inf(map);
		return (NULL);
	}
	map_closed = ft_mapclosed(map);
	if (map_closed < 0)
	{
		printf("Error\n%i\n", map_closed);
		ft_free_map_inf(map);
		return (NULL);
	}
	return (map);
}

int	main(int argc, char **argv)
{
	t_map *map;

	map = ft_check_map(argc, argv);
	if (!map)
		return (0);
	
	list().iter(map->map, ft_print_lst, 0);
	ft_free_map_inf(map);
	return (0);
}
