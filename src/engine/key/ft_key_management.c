/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:37:16 by rteles            #+#    #+#             */
/*   Updated: 2022/11/22 13:17:46 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_keys.h>
#include <ft_sprites.h>
#include <ft_scenes.h>
#include <ft_scenes_images.h>


static int key_atack(void)
{
	static long	long	time_start = 0;
	long long			dif;

	if ((engine())->key->search(BUTTON_RIGHT)->on && (player())->fadigue - 2 >= 0)
	{
		if (!(player())->atack)
			(player())->atack = 1;
		(player())->sprite = 0;
		dif = time_diff(time_start, time_current());
		if (dif > 750 || time_start == 0)
		{
			time_start = time_current();
			(engine())->sound("paplay src/sound/breathe_in.ogg");
		}
		(player())->fadigue -= 2;
	}
	else if ((engine())->key->search(BUTTON_RIGHT)->on)
		(engine())->key->search(BUTTON_RIGHT)->on = 0;
	if (!(engine())->key->search(BUTTON_RIGHT)->on && (player())->atack == 1)
	{
		(player())->sprite = (canva())->sprite(HAND);
		(engine())->sound("paplay src/sound/breathe_out.ogg");
		(player())->atack = 0;
	}
	return (0);
}

static int key_pause(void)
{
	if ((engine())->key->search(KEY_P)->on && ((engine())->pause == 1))
		(engine())->pause = 2;
	if (!(engine())->key->search(KEY_P)->on && ((engine())->pause == 2))
	{
		(engine())->pause = 0;
		(canva())->scene = &(canva())->scene_show[SC_GAME];
		(canva())->scene->init();
	}
	return (0);
}

static int key_game_3(void)
{
	static int a = 0;

	if (!(engine())->key->search(KEY_E)->on && a == 1)
	{
		(player())->obj_interation();
		a = 0;
	}
	else if ((engine())->key->search(KEY_E)->on && a == 0)
		a = 1;
	return (0);
}

static int key_game_2(void)
{
	t_data	*data;

	if ((engine())->key->search(KEY_SHIFT)->on && (player())->move &&\
		(player())->fadigue - 2 >= 0)
	{
		if ((player())->vision >= 0.60)
			(player())->vision -= 0.01;
		(player())->vel = 0.30;
		(player())->move = 0;
		//(player())->fadigue -= 2;
		data = (canva())->sprite(RUN);
		(canva())->resize(data, (canva())->data->larg,\
		(canva())->data->alt, 0, 0);
	}
	else if ((engine())->key->search(KEY_SHIFT)->on &&
		(player())->vision <= 0.66 && (player())->move == 0)
			(player())->vision += 0.001;
	if ((engine())->key->search(KEY_SHIFT)->on && (player())->move &&\
		(player()->fadigue - 3 <= 0))
		(player())->vel = 0.10;
	if ((engine())->key->search(KEY_SHIFT)->on == 0 &&\
		((player())->vision <= 0.66 || (player())->fadigue + 0.25 < 100))
	{
		if ((player())->fadigue <= 100)
			(player())->fadigue += 0.25;
		if ((player())->vision <= 0.66)
			(player())->vision += 0.1;
		(player())->vel = 0.10;
	}
	if ((engine())->key->search(KEY_P)->on && ((engine())->pause == 0))
	{
		(engine())->pause = 1;
		(canva())->scene->complete = 1;
	}
	if ((engine())->key->search(KEY_T)->on)
	{
		printf("Mostrar barra de Vidas\n");
	}
	key_game_3();
	key_atack();
	return (0);
}

//Quando pressionar uma tecla
static int key_game(void)
{
	if ((engine())->key->search(KEY_M)->on && ((engine())->map == 0))
	{
		(engine())->map = 1;
		(canva())->scene_img[S_MAP].on = 1;
	}
	if ((engine())->key->search(KEY_M)->on && ((engine())->map == 2))
		(engine())->map = 3;
	if (!(engine())->key->search(KEY_M)->on && ((engine())->map == 1))
		(engine())->map = 2;
	if (!(engine())->key->search(KEY_M)->on && ((engine())->map == 3))
	{
		(engine())->map = 0;
		(canva())->scene_img[S_MAP].on = 0;
	}
	if ((engine())->key->search(KEY_W)->on && ++(player())->move)
		(player())->movement(1, 1, X, Y);
	if ((engine())->key->search(KEY_A)->on && ++(player())->move)
		(player())->movement(1, -1, Y, X);
	if ((engine())->key->search(KEY_S)->on && ++(player())->move)
		(player())->movement(-1, -1, X, Y);
	if ((engine())->key->search(KEY_D)->on && ++(player())->move)
		(player())->movement(-1, 1, Y, X);
	if ((engine())->key->search(KEY_N)->on) //TODO
		(canva())->scene_img[S_HAND].option = 1;
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
	if ((engine())->menu == 1)
	{
		if ((engine())->key->search(KEY_W)->on)
			(engine())->menu = 3;
		else if ((engine())->key->search(KEY_S)->on)
			(engine())->menu = 2;
		else if ((engine())->key->search(KEY_ENTER)->on)
		{
			(canva())->scene->complete = 1;
			//(engine())->sound("paplay src/sound/wolf.ogg");
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
	(canva())->scene_show[SC_LOGIN].key = 0;
	(canva())->scene_show[SC_MENU].key = key_menu;
	(canva())->scene_show[SC_GAME].key = key_game;
	(canva())->scene_show[SC_PAUSE].key = key_pause;
	/*if ((engine())->menu > 0)
		return (key_menu());
	if ((engine())->pause)
		return (key_pause());
	if ((engine())->menu == 0)
		return (key_game());*/
	return (0);
}
