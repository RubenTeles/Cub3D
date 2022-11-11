/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:40:13 by rteles            #+#    #+#             */
/*   Updated: 2022/11/10 21:25:39 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

//Apenas aceita uma vez
int	key_press(int keycode, char **map)
{
	(void)map;
	if (keycode == ESC)
		return (end_game());
	if ((engine())->menu == 0)
		return (key_press_game(keycode, 0));
	if ((engine())->menu > 0)
		return (key_press_menu(keycode, 0));
	return (0);
}

//Quando pressionar uma tecla
int key_press_game(int keycode, void *param)
{
	(void)param;
	
	if ((engine())->menu > 0)
		return (0);
	if (keycode == KEY_M)
	{
		if ((engine())->map == 0)
			(engine())->map = 1;
		else
			(engine())->map = 0;
	}
	if (keycode == KEY_W && (player())->pos[Y] > 0 && ++(player())->move)
		(player())->pos[Y] -= (player())->vel;
	if (keycode == KEY_A && (player())->pos[X] > 0 && ++(player())->move)
		(player())->pos[X] -= (player())->vel;
	if (keycode == KEY_S && (player())->pos[Y] < (engine())->max[Y] - 1\
		&& ++(player())->move)
		(player())->pos[Y] += (player())->vel;
	if (keycode == KEY_D && (player())->pos[X] < (engine())->max[X] - 1\
		&& ++(player())->move)
		(player())->pos[X] += (player())->vel;
	return (0);
}

//Quando pressionar o botao do rato
int key_mouse_press(int button, int x, int y, void *param)
{
	(void)param;
	(void)x;
	(void)y;

	if ((engine())->menu > 0)
		return (0);
	if (button == BUTTON_RIGHT)
		printf("Right Button PRESS\n");
	return (0);
}

//Quando largar o botao do rato
int key_mouse_out(int button, int x, int y, void *param)
{
	(void)param;
	(void)x;
	(void)y;

	if ((engine())->menu > 0)
		return (0);
	if (button == BUTTON_RIGHT)
		printf("Right Button OUT\n");
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
