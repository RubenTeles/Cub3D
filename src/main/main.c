/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:39:56 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/26 15:15:49 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>
#include <ft_engine.h>

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
	t_all	all;
	//(void)argv;
	//(void)argc;
	/*char	**file = malloc(sizeof(char *) * 3);
	char	exe[8] = {"./cub3D"};
	char	map[8] = {"ex.cub"};

	argc = 2;
	file[0] = exe;
	file[1] = map;
	file[2] = NULL;*/
	all.file = ft_check_map(argc, argv);
	if (!all.file)
		return (0);
	ft_free_map_inf(all.file);
	return (0);
}
