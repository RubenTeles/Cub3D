/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:37:16 by rteles            #+#    #+#             */
/*   Updated: 2022/11/17 08:55:37 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_keys.h>

static int key_pause(void)
{
	if ((engine())->key->search(KEY_P)->on && ((engine())->pause == 1))
		(engine())->pause = 2;
	if (!(engine())->key->search(KEY_P)->on && ((engine())->pause == 2))
		(engine())->pause = 0;
	return (0);
}

static int key_game_2(void)
{
	if ((engine())->key->search(KEY_SHIFT)->on && (player())->move)
	{
		if ((player())->vision >= 0.60)
			(player())->vision -= 0.01;
		(player())->vel = 0.30;
		(player())->move = 0;
	}
	else if ((engine())->key->search(KEY_SHIFT)->on &&
		(player())->vision <= 0.66 && (player())->move == 0)\
		(player())->vision += 0.001;
	if ((engine())->key->search(KEY_SHIFT)->on == 0 &&\
		(player())->vision <= 0.66)
	{
		(player())->vision += 0.002;
		(player())->vel = 0.10;
	}
	if ((engine())->key->search(KEY_P)->on && ((engine())->pause == 0))
		(engine())->pause = 1;
	if ((engine())->key->search(KEY_T)->on)
	{
		printf("Mostrar barra de Vidas\n");
	}
	return (0);
}

//Quando pressionar uma tecla
static int key_game(void)
{
	if ((engine())->key->search(KEY_M)->on && ((engine())->map == 0))
		(engine())->map = 1;
	if ((engine())->key->search(KEY_M)->on && ((engine())->map == 2))
		(engine())->map = 3;
	if (!(engine())->key->search(KEY_M)->on && ((engine())->map == 1))
		(engine())->map = 2;
	if (!(engine())->key->search(KEY_M)->on && ((engine())->map == 3))
		(engine())->map = 0;
	if ((engine())->key->search(KEY_W)->on && ++(player())->move)
		(player())->movement(1, 1, X, Y);
	if ((engine())->key->search(KEY_A)->on && ++(player())->move)
		(player())->movement(1, -1, Y, X);
	if ((engine())->key->search(KEY_S)->on && ++(player())->move)
		(player())->movement(-1, -1, X, Y);
	if ((engine())->key->search(KEY_D)->on && ++(player())->move)
		(player())->movement(-1, 1, Y, X);
	if ((engine())->key->search(BUTTON_RIGHT)->on)
		printf("Right Button PRESS\n");
	if ((engine())->key->search(KEY_N)->on)
		ft_hands(0, 1);
	if ((engine())->key->search(KEY_RIGHT)->on)
	{
		ft_rotate_dir((player())->turn);
		(player())->turn_times -= (player())->turn;
	}
	if ((engine())->key->search(KEY_LEFT)->on)
	{
		ft_rotate_dir(-(player())->turn);	
		(player())->turn_times += (player())->turn;
	}
	key_game_2();
	return (0);
}

//Quando pressionar uma tecla
static int key_menu(void)
{
	if ((engine())->time < 0.1)
		return (0);
	if ((engine())->menu == 1)
	{
		if ((engine())->key->search(KEY_W)->on)
			(engine())->menu = 3;
		else if ((engine())->key->search(KEY_S)->on)
			(engine())->menu = 2;
		else if ((engine())->key->search(KEY_ENTER)->on)
		{
			(engine())->menu = 0;
			(engine())->time = 0;
			//ft_create_game();
		}
		return (1);
	}
	else if ((engine())->menu == 2)
	{
		if ((engine())->key->search(KEY_W)->on)
			(engine())->menu = 1;
		if ((engine())->key->search(KEY_S)->on)
			(engine())->menu = 3;
		/*if ((engine())->key->search(KEY_ENTER)->on)
			(engine())->menu = 4;*/
		return (1);
	}
	else if ((engine())->menu == 3)
	{
		if ((engine())->key->search(KEY_W)->on)
			(engine())->menu = 2;
		if ((engine())->key->search(KEY_S)->on)
			(engine())->menu = 1;
		/*if ((engine())->key->search(KEY_ENTER)->on)
			(engine())->menu = 5;*/
		return (1);
	}
	return (0);
}

int	key_management(void)
{
	key_esc();
	if ((engine())->menu > 0)
		return (key_menu());
	if ((engine())->pause)
		return (key_pause());
	if ((engine())->menu == 0)
		return (key_game());
	return (0);
}
