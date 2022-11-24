/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:02:42 by rteles            #+#    #+#             */
/*   Updated: 2022/11/24 20:58:49 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_scenes_images.h>

int	is_collision(t_object *obj, double x, double y, int option)
{
	t_object	*aux;

	aux = (engine())->object;
	if (option == 1)
		aux = (engine())->enemies;
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
	if (option == 0)
		return (is_collision(obj, x, y, 1));
	return (0);
}

void	is_interation(t_object *obj, int keycode)
{
	t_object	*aux;

	aux = obj;
	while (aux)
	{
		if (aux->is_near)
			aux->player_interation(aux, keycode);
		aux = aux->next;
	}
}

void	all_interation(t_object *obj, double x, double y, int option)
{
	t_object	*aux;

	aux = obj;
	if ((canva())->scene_img[S_PRESS_E].on && option == 1)
		(canva())->scene_img[S_PRESS_E].on = 0;
	while (aux)
	{
		if (aux->interation > 0)
		{
			if (((aux->pos[X] + 1.10 + aux->interation >= x && aux->pos[X] -\
			0.1 - aux->interation <= x) && (aux->pos[Y] + 1.10 +\
			aux->interation >= y  && aux->pos[Y] - 0.1 - aux->interation <=\
			y)) && !((aux->pos[X] + 1.10 >= x && aux->pos[X] - 0.1 <= x) &&\
			(aux->pos[Y] + 1.10 >= y  && aux->pos[Y] - 0.1 <= y )))
			{
				aux->is_near = 1;
				aux->player_near(aux, 0);
			}
			else
				aux->is_near = 0;
		}
		aux = aux->next;
	}
	if (option == 1)
		all_interation((engine())->enemies, x, y, 0);
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
	if (title == 'p')
		return (PIG_S0);
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
	if (obj->title == PIG_S0)//5
		return (ft_create_pig(obj));
	return (0);
}
