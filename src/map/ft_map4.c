/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:59:28 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/22 18:00:02 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	ft_free_map_inf(t_map *map)
{
	list().free(map->map);
	free(map->no);
	free(map->so);
	free(map->we);
	free(map->ea);
	array().free(map->c);
	array().free(map->f);
	free(map);
}
