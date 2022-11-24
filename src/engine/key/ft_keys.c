/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:56:36 by rteles            #+#    #+#             */
/*   Updated: 2022/11/24 11:58:32 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_keys.h>

static void	destroy_key(void)
{
	free((engine())->key);
}

static int	search_key(int keycode)
{
	int	i;

	i = -1;
	while (++i < _MAX_KEYS_)
	{
		if ((engine())->key[i].key == keycode)
			return (1);
	}
	return (0);
}

static void	turn_on_of_key(int keycode, int turn)
{
	int	i;

	i = -1;
	while (++i < _MAX_KEYS_)
	{
		if ((engine())->key[i].key == keycode)
		{
			if (turn)
				(engine())->key->is_on++;
			else if (!turn && (engine())->key->is_on > 0)
				(engine())->key->is_on--;
			(engine())->key[i].on = turn;
			return ;
		}
	}
}

static void	_reset_keys(void)
{
	int	i;

	i = -1;
	while (++i < _MAX_KEYS_)
		(engine())->key[i].on = 0;
}

void	new_key(void)
{
	(engine())->key = malloc(sizeof(t_key) * _MAX_KEYS_);
	(engine())->key->is_on = 0;
	(engine())->key->search = search_key;
	(engine())->key->turn_on_off = turn_on_of_key;
	(engine())->key->destroy = destroy_key;
	(engine())->key[_KEY_W].key = KEY_W;
	(engine())->key[_KEY_A].key = KEY_A;
	(engine())->key[_KEY_S].key = KEY_S;
	(engine())->key[_KEY_D].key = KEY_D;
	(engine())->key[_KEY_N].key = KEY_N;
	(engine())->key[_KEY_M].key = KEY_M;
	(engine())->key[_KEY_E].key = KEY_E;
	(engine())->key[_KEY_ENTER].key = KEY_ENTER;
	(engine())->key[_BUTTON_RIGHT].key = BUTTON_RIGHT;
	(engine())->key[_BUTTON_LEFT].key = BUTTON_LEFT;
	(engine())->key[_KEY_RIGHT].key = KEY_RIGHT;
	(engine())->key[_KEY_LEFT].key = KEY_LEFT;
	(engine())->key[_KEY_SHIFT].key = KEY_SHIFT;
	(engine())->key[_KEY_P].key = KEY_P;
	(engine())->key[_KEY_TAB].key = KEY_TAB;
	_reset_keys();
}
