/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_methods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:06:02 by rteles            #+#    #+#             */
/*   Updated: 2022/11/15 00:04:14 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_keys.h>

int	key_press_in(int keycode)
{
	if ((engine())->key->search(keycode))
		(engine())->key->search(keycode)->on = 1;
	return (0);
}

int	key_press_out(int keycode)
{
	if ((engine())->key->search(keycode))
		(engine())->key->search(keycode)->on = 0;
	return (0);
}

//Ao mexer o mouse
int key_mouse_move(int x, int y, void *param)
{
	(void)param;
	(void)x;
	(void)y;

	//printf("X: %i Y: %i\n", x, y);
	return (0);
}

int	key_esc(void)
{
	if ((engine())->key->search(ESC)->on)
		return (end_game());
	return (0);
}
