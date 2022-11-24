/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:48:45 by rteles            #+#    #+#             */
/*   Updated: 2022/11/24 12:38:57 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

static void	destroy_object(void)
{
	t_object	*aux;
	t_object	*destroy;

	aux = (engine())->object;
	while (aux)
	{
		destroy = aux;
		aux = aux->next;
		free(destroy);
	}
	aux = (engine())->enemies;
	while (aux)
	{
		destroy = aux;
		aux = aux->next;
		free(destroy);
	}
}

static t_object	*last_object(t_object *obj)
{
	t_object	*aux;

	aux = obj;
	while (aux)
	{
		if (!aux->next)
			return (aux);
		aux = aux->next;
	}
	return (0);
}

static void	_interation_zero_(t_object	*obj, int key)
{
	(void)obj;
	(void)key;
}

t_object	*ft_new_object(char title, int x, int y)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (0);
	new->title = map_to_sprite(title);
	new->avatar = 0;
	if (new->title != 0)
		new->avatar = (canva())->sprite(new->title);
	new->sprite = 0;
	if (new->title != 0)
		new->sprite = new->sprite;
	new->pos[X] = x;
	new->pos[Y] = y;
	new->dir[X] = 0;
	new->dir[Y] = -1;
	new->vel = 0.05;
	new->turn = 0.05;
	new->life = 100;
	new->collision = 1;
	new->interation = 0;
	new->is_near = 0;
	new->player_near = _interation_zero_;
	new->player_interation = _interation_zero_;
	new->is_collision = is_collision;
	new->last = last_object;
	new->destroy = destroy_object;
	new->next = 0;
	if (new->title == PIG_S0 && !(engine())->enemies) 
		(engine())->enemies = new;
	else if (new->title == PIG_S0 && (engine())->enemies) 
		(engine())->enemies->last((engine())->enemies)->next = new;
	else if (!(engine())->object)
		(engine())->object = new;
	else
		(engine())->object->last((engine())->object)->next = new;
	ft_managemen_objects(title, new);
	return (new);
}
