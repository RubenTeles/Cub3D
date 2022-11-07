/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/11/07 18:11:41 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>

static void	colors_floor_ceilling(char **floor, char **ceilling)
{
	char	r;
	char	g;
	char	b;

	r = (string()).atoi(floor[0]);
	g = (string()).atoi(floor[1]);
	b = (string()).atoi(floor[2]);
	(engine())->color[FLOOR] = ft_trgb(0, r, g, b);
	r = (string()).atoi(ceilling[0]);
	g = (string()).atoi(ceilling[1]);
	b = (string()).atoi(ceilling[2]);
	(engine())->color[CEILLING] = ft_trgb(0, r, g, b);
}

void	new_engine(t_all *all, int larg, int alt)
{
	(void)all;
	(engine())->ptr = mlx_init();
	if (!engine()->ptr)
		return ;
	(engine())->size[X] = larg;
	(engine())->size[Y] = alt;
	(engine())->max[X] = -1;
	(engine())->max[Y] = -1;
	(engine())->win = mlx_new_window((engine())->ptr, (engine())->size[X], \
		(engine())->size[Y], "WOLF EAT PIG'S");
	colors_floor_ceilling(all->file->f, all->file->c);
	(engine())->map = 0;
	(engine())->time = 0;
	(engine())->count = -1;
	(engine())->sprt_for_sec = 10;
	(engine())->menu = 1;
	new_canva();
}

t_engine	*engine(void)
{
	static t_engine	e;

	return (&e);
}
