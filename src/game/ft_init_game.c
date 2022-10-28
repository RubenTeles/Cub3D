/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:24:52 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/25 11:15:11 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

t_game	*ft_get_game_info(t_map *map)
{
	t_game	*game;
	char	*str;

	game = malloc(sizeof(t_game));
	game->wolf.pos = ft_player_pos(map->map);
	str = list().get(map->map, game->wolf.pos.x);
	game->wolf.dir = str[game->wolf.pos.y];
	str[game->wolf.pos.y] = '0';
	game->board = ft_lst_toarr(map->map);
	game->pigs = NULL;
	return (game);
}

int	ft_init_game(t_all *all)
{
	all->pieces = ft_get_game_info(all->file);
	all->ptr = mlx_init();
	all->win = mlx_new_window(all->ptr, 1000, 1000, "Cub3D");
	return (0);
}