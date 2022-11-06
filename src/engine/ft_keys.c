/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:40:13 by rteles            #+#    #+#             */
/*   Updated: 2022/11/05 21:00:06 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

//Apenas aceita uma vez
int	key_press_no_repeat(int keycode, char **map)
{
	(void)map;
	if (keycode == ESC)
		return (end_game());
	if (keycode == KEY_M)
	{
		if ((engine())->map == 0)
			(engine())->map = 1;
		else
			(engine())->map = 0;
	}
	if (keycode == KEY_ENTER && (engine())->menu)
		(engine())->menu = 0;
	return (0);
}

//Quando pressionar uma tecla
int key_press(int keycode, void *param)
{
	(void)param;

	if (keycode == KEY_W)
		return (printf("KEY: W\n"));
	if (keycode == KEY_A)
		return (printf("KEY: A\n"));
	if (keycode == KEY_S)
		return (printf("KEY: S\n"));
	if (keycode == KEY_D)
		return (printf("KEY: D\n"));
	return (0);
}

//Quando pressionar o botao do rato
int key_mouse_press(int button, int x, int y, void *param)
{
	(void)param;
	(void)x;
	(void)y;

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
/*
int begin(void *param)
{
	(void)param;
	int		i;

	i = 
}*/

