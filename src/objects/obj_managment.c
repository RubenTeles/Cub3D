/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:02:42 by rteles            #+#    #+#             */
/*   Updated: 2022/11/20 18:10:47 by rteles           ###   ########.fr       */
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
			((aux->pos[X] >= x - 1.10 && aux->pos[X] <= x + 0.1) &&\
				(aux->pos[Y] >= y - 1.10 && aux->pos[Y] <= y + 0.1)))
				return (1);
		aux = aux->next;
	}
	if (obj && (((player())->pos[X] >= x - 1.10 && (player())->pos[X] <= x + 0.1) &&\
				((player())->pos[Y] >= y - 1.10 && (player())->pos[Y] <= y + 0.1)))
			{
				printf("colide\n");
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
			((aux->pos[X] >= x - 1.10 - aux->interation &&\
			aux->pos[X] <= x + 0.1 + aux->interation) &&\
			(aux->pos[Y] >= y - 1.10 - aux->interation &&\
			aux->pos[Y] <= y + 0.1 + aux->interation)))
				return (aux);
		aux = aux->next;
	}
	
	if (obj && (((player())->pos[X] >= x - 1.10 - (player())->interation &&\
			(player())->pos[X] <= x + 0.1 + (player())->interation) &&\
			((player())->pos[Y] >= y - 1.10 - (player())->interation &&\
			(player())->pos[Y] <= y + 0.1 + (player())->interation)))
			{
				printf("interagiu com o player\n");
				return (0);
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