/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:40:22 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/22 19:18:04 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	ft_try(t_list *lst)
{
	char	**map;
	int		i;

	map = ft_lst_toarr(lst);
	i = -1;
	while (map[++i])
		printf("|%s|\n", map[i]);
	array().free(map);
}
