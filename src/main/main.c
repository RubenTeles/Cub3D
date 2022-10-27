/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:39:56 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/27 13:34:18 by amaria-m         ###   ########.fr       */
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

/*
all.map é uma array de strings (char **) em que cada string é uma linha do mapa

exemplo:
all.map = {
	"1111111111",
	"1010N10011",
	"1010000001",
	"1010010011",
	"1111111111"
	};
	
Ou seja depois para mexer, vai ser assim,
all.map[1] = "1010N10011"
ou
all.map[1][4] = 'N'

*/
int	main(int argc, char **argv)
{
	t_all	all;
	char	**file;

	file = array().create(2, "./cub3D", "ex.cub");
	if (argc == 1)
		all.file = ft_check_map(2, file);
	else
		all.file = ft_check_map(argc, argv);
	if (!all.file)
		return (0);
	all.map = ft_lst_toarr(all.file->map);
	printf("%s\n", all.map[1]);
	if (ft_start(all.file))
		return (-1);

	array().free(file);
	array().free(all.map);
	ft_free_map_inf(all.file);
	return (0);
}
