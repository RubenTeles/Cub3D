/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_methods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:06:02 by rteles            #+#    #+#             */
/*   Updated: 2022/12/07 00:11:45 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_keys.h>

int	key_press_in(int keycode)
{
	if (keycode == ESC)
		return (end_game());
	if ((engine())->key->search(keycode))
		(engine())->key->turn_on_off(keycode, 1);
	return (0);
}

int	key_press_out(int keycode)
{
	if ((engine())->key->search(keycode))
		(engine())->key->turn_on_off(keycode, 0);
	return (0);
}

//Ao mexer o mouse
int	key_mouse_move(int x, int y, void *param)
{
	double	move;

	(void)param;
	(void)y;
	if ((engine())->pause || (engine())->menu)
		return (0);
	if (x > (engine())->size[X] * 0.425 && x < (engine())->size[X])
	{
		move = (player())->turn * 0.10;
		ft_rotate_dir(move);
		(player())->turn_times -= move;
	}
	if (x < (engine())->size[X] * 0.575 && x > 1)
	{
		move = (player())->turn * 0.10;
		ft_rotate_dir(-move);
		(player())->turn_times += move;
	}
	return (0);
}
