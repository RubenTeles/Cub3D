/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:39:56 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/22 18:01:27 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	*ft_print_lst(void *ptr)
{
	printf("%s", (char *)ptr);
	return (ptr);
}

void	ft_print_mapinf(t_map *map)
{
	printf("no: %s\n", map->no);
	printf("so: %s\n", map->so);
	printf("we: %s\n", map->we);
	printf("ea: %s\n", map->ea);
	printf("f: %s, %s, %s\n", map->f[0], map->f[1], map->f[2]);
	printf("c: %s, %s, %s\n", map->c[0], map->c[1], map->c[2]);
	(list().iter)(map->map, ft_print_lst, 0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = ft_check_map(argc, argv);
	if (!map)
		return (0);
	ft_print_mapinf(map);
	ft_free_map_inf(map);
	return (0);
}
