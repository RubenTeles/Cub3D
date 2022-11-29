/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:02:42 by rteles            #+#    #+#             */
/*   Updated: 2022/11/29 13:36:46 by rteles           ###   ########.fr       */
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
			((aux->pos[X] + 1.10 >= x && aux->pos[X] - 0.1 <= x) && \
			(aux->pos[Y] + 1.10 >= y && aux->pos[Y] - 0.1 <= y)))
			return (1);
		aux = aux->next;
	}
	if (obj && (((player())->pos[X] + 1.10 >= x && \
		(player())->pos[X] - 0.1 <= x) && ((player())->pos[Y] + 1.10 >= y && \
		(player())->pos[Y] - 0.1 <= y)))
	{
		(player())->life -= 55;
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
			if (((aux->pos[X] + 1.10 + aux->interation >= x && aux->pos[X] - \
			0.1 - aux->interation <= x) && (aux->pos[Y] + 1.10 + \
			aux->interation >= y && aux->pos[Y] - 0.1 - aux->interation <= \
			y)) && !((aux->pos[X] + 1.10 >= x && aux->pos[X] - 0.1 <= x) && \
			(aux->pos[Y] + 1.10 >= y && aux->pos[Y] - 0.1 <= y)))
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
		return (WOOD_FLOOR);
	if (title == '3')
		return (CAVE);
	if (title == 'M')
		return (HAY);
	if (title == 'm')
		return (WINDOW);
	if (title == 'D')
		return (DOOR);
	if (title == 'C')
		return (CAVE);
	if (title == 'p')
		return (PIG);
	if (title == 'c')
		return (CRISTAL);
	if (title == 'B')
		return (BUSH);
	return (0);
}

int	ft_managemen_objects(char tittle, t_object *obj)
{
	(void)tittle;
	if (obj->title == DOOR)
		return (ft_create_door(obj));
	if (obj->title == PIG)
		return (ft_create_pig(obj));
	if (obj->title == CRISTAL)
		return (ft_create_cristal(obj));
	if (obj->title == BUSH)
		return (ft_create_bush(obj));
	return (0);
}
