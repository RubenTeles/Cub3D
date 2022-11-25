/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_methods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:06:02 by rteles            #+#    #+#             */
/*   Updated: 2022/11/25 18:03:14 by amaria-m         ###   ########.fr       */
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
int key_mouse_move(int x, int y, void *param)
{
	(void)param;
	(void)y;

	if (x > 800)
	{
		ft_rotate_dir((player())->turn);
		(player())->turn_times -= (player())->turn;
	}
	if (x < 500)
	{
		ft_rotate_dir(-(player())->turn);	
		(player())->turn_times += (player())->turn;
	}
	// printf("X: %i Y: %i\n", x, y);
	return (0);
}
