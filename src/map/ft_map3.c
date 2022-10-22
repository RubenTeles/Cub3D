/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:18:21 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/22 16:13:56 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_cub.h>

void	ft_fill_nextpos(t_list *board, t_pos atual, t_pos *next)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		next[i].x = atual.x;
		next[i].y = atual.y;
		if (i < 3)
			next[i].x -= 1;
		if (i > 4)
			next[i].x += 1;
		if (i == 0 || i == 3 || i == 5)
			next[i].y -= 1;
		if (i == 2 || i == 4 || i == 7)
			next[i].y += 1;
		if (next[i].x >= list().len(board))
			next[i].x = -1;
		if (next[i].y >= string().len(list().get(board, next[i].x)))
			next[i].y = -1;
	}
}

int	ft_nextpos_opts(t_list *board, t_pos atual, t_pos *next)
{
	char	*str;
	int		i;

	if (atual.x == 0 || atual.y == 0 || atual.x == list().len(board) - 1)
		return (0);
	if (atual.y == string().len(list().get(board, atual.x)) - 1)
		return (0);
	if (atual.y == string().len(list().get(board, atual.x - 1)) - 1)
		return (0);
	if (atual.y == string().len(list().get(board, atual.x + 1)) - 1)
		return (0);
	ft_fill_nextpos(board, atual, next);
	i = -1;
	while (++i < 8)
	{
		if (next[i].x >= 0 && next[i].y >= 0)
		{
			str = list().get(board, next[i].x);
			if (str[next[i].y] == '1')
				next[i].y = -1;
			if (string().is_spc(str[next[i].y]))
				return (0);
		}
	}
	return (1);
}

int	ft_nextpos(t_list *board, t_pos atual, t_pos *next)
{
	t_pos	opts[8];
	char	*str;
	int		i;

	if (!ft_nextpos_opts(board, atual, opts))
		return (0);
	i = -1;
	while (++i < 8)
	{
		if (opts[i].x >= 0 && opts[i].y >= 0)
		{
			(*next).x = opts[i].x;
			(*next).y = opts[i].y;
			str = list().get(board, opts[i].x);
			str[opts[i].y] = '1';
			return (1);
		}
	}
	return (2);
}
