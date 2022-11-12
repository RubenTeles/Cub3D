/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:37:16 by rteles            #+#    #+#             */
/*   Updated: 2022/11/12 20:02:29 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_keys.h>

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
	if ((engine())->key->search(KEY_W)->on && (player())->pos[Y] > 0 && ++(player())->move)
		(player())->pos[Y] += (player())->vel * (player())->dir[Y];
	if ((engine())->key->search(KEY_A)->on && (player())->pos[X] > 0 && ++(player())->move)
		(player())->pos[X] += (player())->vel * (player())->dir[Y];
	if ((engine())->key->search(KEY_S)->on && (player())->pos[Y] < (engine())->max[Y] - 1\
		&& ++(player())->move)
		(player())->pos[Y] -= (player())->vel * (player())->dir[Y];
	if ((engine())->key->search(KEY_D)->on && (player())->pos[X] < (engine())->max[X] - 1\
		&& ++(player())->move)
		(player())->pos[X] -= (player())->vel * (player())->dir[Y];
	if ((engine())->key->search(BUTTON_RIGHT)->on)
		printf("Right Button PRESS\n");
	if ((engine())->key->search(KEY_K)->on)
		ft_rotate_dir(0.05);
	if ((engine())->key->search(KEY_J)->on)
		ft_rotate_dir(-0.05);
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
	if ((engine())->menu == 0)
		return (key_game());
	return (0);
}
