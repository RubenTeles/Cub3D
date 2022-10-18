/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:39:56 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/18 18:58:13 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	*ft_print_lst(void *ptr)
{
	printf("%s", (char*)ptr);
	return (ptr);
}

int	ft_map_closed(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 6)
		map->map = list().rmv(map->map, 0);
	
	return (0);
}

int	main(int argc, char **argv)
{
	t_map map;

	map = ft_checker(argc, argv);
	if (ft_check_map_info(&map))
		printf("err %i\n", ft_check_map_info(&map));
	ft_map_closed(&map);
	list().iter(map.map, ft_print_lst, 0);
	ft_free_map_inf(map);
	return (0);
}
