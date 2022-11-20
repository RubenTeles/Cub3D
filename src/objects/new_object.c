/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:48:45 by rteles            #+#    #+#             */
/*   Updated: 2022/11/20 01:53:11 by rteles           ###   ########.fr       */
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
			((aux->pos[X] >= x - 1.10 && (aux->pos[X] <= x + 0.1) &&\
				(aux->pos[Y] >= y - 1.10 && aux->pos[Y] <= y + 0.1))))
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

int		map_to_sprite(char title)
{
	if (title == '1')
		return (TREE);
	if (title == '2')
		return (HAY);
	if (title == '3')
		return (WINDOW);
	if (title == '4')
		return (WINDOW);
	if (title == '5')
		return (DOOR);
	if (title == '6')
		return (CAVE);
	return (0);
}

void	ft_new_object(char title, int x, int y)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return ;
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
	new->life = 50;
	new->collision = 1;
	if (new->title == DOOR)
		new->collision = 0;
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
