/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:01:00 by rteles            #+#    #+#             */
/*   Updated: 2022/11/09 01:34:03 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>

//Quando pressionar uma tecla
int key_press_menu(int keycode, void *param)
{
	(void)param;

	if ((engine())->time < 0.2)
		return (0);
	if ((engine())->menu == 1)
	{
		if (keycode == KEY_W)
			(engine())->menu = 3;
		else if (keycode == KEY_S)
			(engine())->menu = 2;
		else if (keycode == KEY_ENTER)
		{
			(engine())->menu = 0;
			(engine())->time = 0;
		}
		return (1);
	}
	else if ((engine())->menu == 2)
	{
		if (keycode == KEY_W)
			(engine())->menu = 1;
		if (keycode == KEY_S)
			(engine())->menu = 3;
		/*if (keycode == KEY_ENTER)
			(engine())->menu = 4;*/
		return (1);
	}
	else if ((engine())->menu == 3)
	{
		if (keycode == KEY_W)
			(engine())->menu = 2;
		if (keycode == KEY_S)
			(engine())->menu = 1;
		/*if (keycode == KEY_ENTER)
			(engine())->menu = 5;*/
		return (1);
	}
	return (0);
}

int menu_game(double time)
{
	static int	a = 0;
	static int	i = 0;

	if (ft_login(0.01))
		return (0);
	(engine())->time += time;
	ft_initial_menu(0.01);
	ft_words_menu();
	ft_head_wolf(0);
	i++;
	if (a == 0)
	{
		//i = system("paplay src/music/pMLWWiBvWX8_48.ogg");
		a = 1;
	}
	(void)i;
	return (0);
}
