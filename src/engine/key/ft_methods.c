/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_methods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:06:02 by rteles            #+#    #+#             */
/*   Updated: 2022/11/27 12:30:39 by rteles           ###   ########.fr       */
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
	if (x > 720)
	{
		move = (player())->turn * (double)((float)(x - 720) / (float)(620));
		ft_rotate_dir(move);
		(player())->turn_times -= move;
	}
	if (x < 620)
	{
		move = (player())->turn * (double)(((float)620 * 0.1) / (float)(x));
		ft_rotate_dir(-move);
		(player())->turn_times += move;
	}
	return (0);
}
