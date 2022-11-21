/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:02:42 by rteles            #+#    #+#             */
/*   Updated: 2022/11/21 12:36:43 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

int	is_collision(t_object *obj, double x, double y)
{
	t_object	*aux;

	aux = (engine())->object;
	while (aux)
	{
		if (aux->collision == 1 && aux != obj && \
			((aux->pos[X] + 1.10 >= x && aux->pos[X] - 0.1 <= x) &&\
			(aux->pos[Y] + 1.10 >= y  && aux->pos[Y] - 0.1 <= y )))
				return (1);
		aux = aux->next;
	}
	if (obj && (((player())->pos[X] + 1.10 >= x &&\
		(player())->pos[X] - 0.1 <= x) && ((player())->pos[Y] + 1.10 >= y &&\
		(player())->pos[Y] - 0.1 <= y)))
	{
		printf("colide com o player\n");
		return (1);
	}
	return (0);
}

t_object	*is_interation(t_object *obj, double x, double y)
{
	t_object	*aux;

	aux = (engine())->object;
	while (aux)
	{
		if (aux->interation > 0 && aux != obj && \
			((aux->pos[X] + 1.10 + aux->interation >= x &&\
			aux->pos[X] - 0.1 - aux->interation <= x) &&\
			(aux->pos[Y] + 1.10 + aux->interation >= y  &&\
			aux->pos[Y] - 0.1 - aux->interation <= y )) &&\
			!((aux->pos[X] + 1.10 >= x && aux->pos[X] - 0.1 <= x) &&\
			(aux->pos[Y] + 1.10 >= y  && aux->pos[Y] - 0.1 <= y )))
				return (aux);
		aux = aux->next;
	}
	if (obj && (((player())->pos[X] + 1.10 + (player())->interation >= x &&\
				(player())->pos[X] - 0.10 - (player())->interation <= x) &&\
				((player())->pos[Y] + 1.10 + (player())->interation >= y &&\
				(player())->pos[Y] - 0.10 - (player())->interation <= y)) &&\
				!((aux->pos[X] + 1.10 >= x && aux->pos[X] - 0.1 <= x) &&\
				(aux->pos[Y] + 1.10 >= y  && aux->pos[Y] - 0.1 <= y )))
	{
		printf("interagiu com o player\n");
		return (0);
	}
	return (0);
}

int	all_interation(t_object *obj, double x, double y)
{
	t_object	*aux;

	aux = (engine())->object;
	while (aux)
	{
		if (aux->interation > 0 && aux != obj && \
			((aux->pos[X] + 1.10 + aux->interation >= x &&\
			aux->pos[X] - 0.1 - aux->interation <= x) &&\
			(aux->pos[Y] + 1.10 + aux->interation >= y  &&\
			aux->pos[Y] - 0.1 - aux->interation <= y )) &&\
			!((aux->pos[X] + 1.10 >= x && aux->pos[X] - 0.1 <= x) &&\
			(aux->pos[Y] + 1.10 >= y  && aux->pos[Y] - 0.1 <= y )))
			{
				if (aux->title == DOOR)
					printf("Press E\n");
				return (1);
			}
		aux = aux->next;
	}
	return (0);
}

int	map_to_sprite(char title)
{
	if (title == '1')
		return (TREE);
	if (title == '2')
		return (HAY);
	if (title == '3')
		return (WOOD_FLOOR);
	if (title == '4')
		return (WINDOW);
	if (title == '5')
		return (DOOR);
	if (title == '6')
		return (CAVE);
	return (0);
}

int	ft_managemen_objects(char tittle, t_object *obj)
{
	/*if (obj->title == HAY || obj->title == WINDOW)//2, 4
		return (ft_create_wall(obj));
	if (obj->title == WOOD_FLOOR)//3
		return (ft_create_floor(obj));*/
	(void)tittle;
	if (obj->title == DOOR)//5
		return (ft_create_door(obj));
	return (0);
}
