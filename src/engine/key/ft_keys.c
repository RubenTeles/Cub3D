/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:56:36 by rteles            #+#    #+#             */
/*   Updated: 2022/11/17 08:03:46 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_keys.h>

static void	destroy_key(void)
{
	t_key	*aux;
	t_key	*destroy;

	aux = (engine())->key;
	while (aux)
	{
		destroy = aux;
		aux = aux->next;
		free(destroy);
	}
}

static t_key	*search_key(int keycode)
{
	t_key	*aux;

	aux = (engine())->key;
	while (aux)
	{
		if (aux->key && aux->key == keycode)
			return (aux);
		aux = aux->next;
	}
	return (0);
}

static t_key	*last_key(void)
{
	t_key	*aux;

	aux = (engine())->key;
	while (aux)
	{
		if (!aux->next)
			break ;
		aux = aux->next;
	}
	return (aux);
}

static t_key	*create_key(int keycode)
{
	t_key	*new;
	t_key	*aux;

	new = malloc(sizeof(t_key));
	if (!new)
		return (0);
	new->key = keycode;
	new->on = 0;
	new->next = NULL;
	new->create = create_key;
	new->search = search_key;
	new->last = last_key;
	new->destroy = destroy_key;
	if (!(engine())->key)
		(engine())->key = new;
	else
	{
		aux = new->last();
		aux->next = new;
	}
	return (new);
}

void	new_key(void)
{
	create_key(ESC);
	create_key(KEY_W);
	create_key(KEY_A);
	create_key(KEY_S);
	create_key(KEY_D);
	create_key(KEY_N);
	create_key(KEY_M);
	create_key(KEY_ENTER);
	create_key(BUTTON_RIGHT);
	create_key(BUTTON_LEFT);
	create_key(KEY_RIGHT);
	create_key(KEY_LEFT);
	create_key(KEY_SHIFT);
	create_key(KEY_P);
	create_key(KEY_T);
}