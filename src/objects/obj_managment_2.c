/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_managment_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:02:42 by rteles            #+#    #+#             */
/*   Updated: 2022/11/30 19:54:34 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_scenes_images.h>

static int	_player_is_atacked(t_object *obj)
{
	double	d_x;
	double	d_y;

	obj->dif = time_diff(obj->time_start, time_current());
	if (obj->dif > 200 || obj->time_start == 0)
	{
		obj->time_start = time_current();
		if ((player())->life - 30 >= 1)
			(player())->life -= 30;
		else
			return ((player())->dead());
		d_x = (obj->pos[X] > player()->pos[X]) - \
				(obj->pos[X] < player()->pos[X]);
		d_y = (obj->pos[Y] > player()->pos[Y]) - \
				(obj->pos[Y] < player()->pos[Y]);
		if (!obj->is_collision(obj, obj->pos[X] + (d_x * 0.1) + 0.5, \
			obj->pos[Y] + 0.5, 0))
			obj->pos[X] += (d_x * 0.1);
		if (!obj->is_collision(obj, obj->pos[X] + 0.5, \
			obj->pos[Y] + (d_y * 0.1) + 0.5, 0))
			obj->pos[Y] += (d_y * 0.1);
	}
	return (1);
}

int	ft_exception(t_object *obj, t_object *aux)
{
	if ((obj && obj->title == BREATH) && \
	(aux->title == PIG || aux->title == BULL || \
	aux->title == CRISTAL))
	{
		aux->is_atack(aux, 10);
		return (1);
	}
	if (obj && obj->title == PIG && aux->title == WINDOW)
		return (0);
	return (1);
}

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
			return (ft_exception(obj, aux));
		aux = aux->next;
	}
	if (obj && obj->title != BREATH && (((player())->pos[X] + 1.10 >= x && \
		(player())->pos[X] - 0.1 <= x) && ((player())->pos[Y] + 1.10 >= y && \
		(player())->pos[Y] - 0.1 <= y)))
		return (_player_is_atacked(obj));
	if (option == 0)
		return (is_collision(obj, x, y, 1));
	return (0);
}

void	ft_enemies_move(void)
{
	t_object	*aux;

	aux = (engine())->enemies;
	while (aux)
	{
		if (aux->move)
			aux->is_move(aux, 0);
		aux = aux->next;
	}
}
