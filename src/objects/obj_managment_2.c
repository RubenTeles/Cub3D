/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_managment_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:02:42 by rteles            #+#    #+#             */
/*   Updated: 2022/12/01 18:56:23 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_scenes_images.h>
#include <ft_sound.h>

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

void	ft_destroy_enemies(t_object *obj)
{
	if ((engine())->enemies == obj)
	{
		if (obj->next)
			(engine())->enemies = obj->next;
		else
			return ;
		printf("aaa\n");
	}
	if (obj->prev)
	{
		if (obj->next)
			obj->prev->next = obj->next;
		else
			obj->prev->next = 0;
	}
	else
	{
		if (obj->next)
			obj->next->prev = obj->prev;
		else
			obj->next->prev = 0;
	}
	free(obj);
}
