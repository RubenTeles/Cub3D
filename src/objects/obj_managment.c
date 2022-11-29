/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:02:42 by rteles            #+#    #+#             */
/*   Updated: 2022/11/29 18:57:14 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_scenes_images.h>

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
	if (title == 'B')
		return (BUSH);
	if (title == 'b')
		return (BULL);
	if (title == 'C')
		return (CAVE);
	if (title == 'c')
		return (CRISTAL);
	if (title == 'D')
		return (DOOR);
	if (title == 'M')
		return (HAY);
	if (title == 'm')
		return (WINDOW);
	if (title == 'p')
		return (PIG);
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
	if (obj->title == BULL)
		return (ft_create_bull(obj));
	return (0);
}
