/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:48:45 by rteles            #+#    #+#             */
/*   Updated: 2022/11/15 00:11:53 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

int	is_collision(t_object *obj, int x, int y)
{
	t_object	*aux;
	
	aux = (engine())->object;
	while (aux)
	{
		if (aux->collision == 1 && aux != obj && \
			(aux->pos[X] == x && aux->pos[Y] == y))
			{
				printf("colide\n");
			return (1);
			}
		aux = aux->next;
	}
	if (obj && (player())->pos[X] == x && (player())->pos[Y] == y)
			{
				printf("colide\n");
			return (1);
			}
	return (0);
}

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
}

static t_object	*last_object(void)
{
	t_object	*aux;

	aux = (engine())->object;
	while (aux)
	{
		if (!aux->next)
			return (aux);
		aux = aux->next;
	}
	return (0);
}

void	ft_new_object(char title, int x, int y)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return ;
	new->title = title;
	new->avatar = (canva())->sprite(title);
	new->sprite = 0;
	new->pos[X] = x;
	new->pos[Y] = y;
	new->dir[X] = 0;
	new->dir[Y] = -1;
	new->vel = 0.05;
	new->turn = 0.05;
	new->life = 50;
	new->collision = 1;
	new->create = ft_new_object;
	new->is_collision = is_collision;
	new->last = last_object;
	new->destroy = destroy_object;
	new->next = 0;
	if (!(engine())->object)
		(engine())->object = new;
	else
		(engine())->object->last()->next = new;
}
