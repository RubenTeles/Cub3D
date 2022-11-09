/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:07:47 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/08 18:52:10 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>

#define N_WALL 'N'
#define S_WALL 'S'
#define W_WALL 'W'
#define E_WALL 'E'

void	ft_walls(void)
{
	t_data	*data[4];
	//int		pos;

	data[0] = (canva())->sprite(N_WALL);
	data[1] = (canva())->sprite(S_WALL);
	data[2] = (canva())->sprite(W_WALL);
	data[3] = (canva())->sprite(E_WALL);
	if (!data[2] || !data[1] || !data[2] || !data[3])
		return ;
	(canva())->resize(data[0], (engine())->size[X] * 0.50, (engine())->size[Y] *\
		0.50, 0, (engine())->size[Y] * 0.3);
	(canva())->resize(data[0], (engine())->size[X] * 0.50, (engine())->size[Y] *\
		0.50, (engine())->size[X] * 0.5, (engine())->size[Y] * 0.3);
}
