/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:40:13 by rteles            #+#    #+#             */
/*   Updated: 2022/11/03 00:52:49 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

//Apenas aceita uma vez
int	key_press_no_repeat(int keycode, char **map)
{
	static int key_m = 0;

	if (keycode == ESC)
		return (end_game());
	if (keycode == KEY_M)
	{
		if (key_m == 0)
		{
			//repeat
			create_images_map(map);
			mlx_put_image_to_window((engine())->ptr, (engine())->win,\
				(canva())->data->img, 0, 0);
			key_m = 1;
		}
		else
		{
			//no repeat
			key_m = 0;
		}
	}
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
int key_mouse_move(int x, int y, void *param)
{
	(void)param;
	(void)x;
	(void)y;

	//printf("X: %i Y: %i\n", x, y);
	//printf("Button: %i X: %i Y: %i\n", button, x, y);
	//mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
*/