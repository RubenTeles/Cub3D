/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:00:10 by rteles            #+#    #+#             */
/*   Updated: 2022/11/17 00:23:46 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

void	ft_put_minimap(void)
{
	t_object	*aux;
	double		larg;
	double		alt;
	double		init_x;
	double		init_y;
	double		board_x;
	double		board_y;
	
	init_x = (canva())->data->larg * 0.735;
	init_y = (canva())->data->alt * 0.08;
	alt = (canva())->data->alt * 0.245 - init_y;
	larg = (canva())->data->larg * 0.955 - init_x;
	//printf("inicial: %f, final: %f MAX: %d\n", ((canva())->data->larg * 0.735), larg, (canva())->data->larg);

	board_x = ((player())->pos[X] - 10) + ((player())->pos[X] + 10);
	board_y = ((player())->pos[Y] - 8) + ((player())->pos[Y] + 8);
	aux = (engine())->object;
	while (aux)
	{
		if (aux->pos[X] >= (player())->pos[X] - 10 && aux->pos[X] <= (player())->pos[X] + 10 &&\
			aux->pos[Y] >= (player())->pos[Y] - 8 && aux->pos[Y] <= (player())->pos[Y] + 8)
		{
			if (aux->avatar)
				(canva())->resize(aux->avatar, (canva())->data->larg * 0.01, (canva())->data->alt * 0.015,\
				(init_x + (larg * (aux->pos[X]/ board_x))), (init_y + (alt * (aux->pos[Y] / board_y))));
			//}
		}
		aux = aux->next;
	}
	(canva())->resize((player())->avatar, (canva())->data->larg * 0.01, (canva())->data->alt * 0.015,\
	(init_x + (larg * ((player())->pos[X]/ board_x))), (init_y + (alt * ((player())->pos[Y] / board_y))));
	
}

void	ft_minimap(char	**map)
{
	t_data		*data;

	(void)map;
	data = (canva())->sprite(MINIMAP);
	if (!data)
		return ;
	ft_print_color((engine())->size[X] * 0.221, (engine())->size[Y] * 0.174,\
		 (engine())->size[X] * 0.741, (engine())->size[Y] * 0.086, 0xe6be7e);
	ft_put_minimap();
	(canva())->resize(data, (engine())->size[X] * 0.30, (engine())->size[Y] *\
		0.35, (engine())->size[X] * 0.70, (engine())->size[Y] * 0.00);
	ft_put_word("MINI MAP", (engine())->size[X] * 0.15, (engine())->size[Y] *\
		0.04, (engine())->size[X] * 0.775, (engine())->size[Y] * 0.26);
}
