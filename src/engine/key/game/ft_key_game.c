/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:49:10 by rteles            #+#    #+#             */
/*   Updated: 2022/12/07 00:14:57 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_keys.h>
#include <ft_sprites.h>
#include <ft_scenes.h>
#include <ft_scenes_images.h>
#include <ft_sound.h>

//KEY LEFT and KEY RIGHT
static void	key_game_left_right(void)
{
	if ((engine())->key[_KEY_RIGHT].on)
	{
		ft_rotate_dir((player())->turn);
		(player())->turn_times -= (player())->turn;
	}
	if ((engine())->key[_KEY_LEFT].on)
	{
		ft_rotate_dir(-(player())->turn);
		(player())->turn_times += (player())->turn;
	}
}

//KEYS WSAD
static void	key_game_wsad(void)
{
	if ((engine())->key[_KEY_W].on && ++(player())->move)
		(player())->movement(1, 1, X, Y);
	if ((engine())->key[_KEY_A].on && ++(player())->move)
		(player())->movement(1, -1, Y, X);
	if ((engine())->key[_KEY_S].on && ++(player())->move)
		(player())->movement(-1, -1, X, Y);
	if ((engine())->key[_KEY_D].on && ++(player())->move)
		(player())->movement(-1, 1, Y, X);
	if (!(engine())->key[_KEY_W].on && !(engine())->key[_KEY_D].on \
		&& !(engine())->key[_KEY_A].on && !(engine())->key[_KEY_S].on)
		(player())->move = 0;
}

//KEY M
static void	key_game_m(void)
{
	if ((engine())->key[_KEY_M].on && ((engine())->map == 0))
	{
		(canva())->scene_img[S_HAND].on = 0;
		(engine())->map = 1;
		(canva())->scene_img[S_MAP].on = 1;
	}
	if ((engine())->key[_KEY_M].on && ((engine())->map == 2))
		(engine())->map = 3;
	if (!(engine())->key[_KEY_M].on && ((engine())->map == 1))
		(engine())->map = 2;
	if (!(engine())->key[_KEY_M].on && ((engine())->map == 3))
	{
		(canva())->scene_img[S_HAND].on = 1;
		(engine())->map = 0;
		(canva())->scene_img[S_MAP].on = 0;
	}
}

//KEY N
int	key_game(void)
{
	static long long	time_start = 0;

	if ((engine())->key[_KEY_N].on)
	{
		(engine())->sound[SD_WOLF_HAPPY].dif = \
		time_diff(time_start, time_current());
		if ((engine())->sound[SD_WOLF_HAPPY].dif > 1000 || time_start == 0)
		{
			time_start = time_current();
			(engine())->sound->play(&(engine())->sound[SD_WOLF_HAPPY]);
			(canva())->scene_img[S_HAND].option = 1;
			if ((all())->stop_weather == 3)
				(all())->stop_weather = 0;
			else
				(all())->stop_weather += 1;
		}
	}
	key_game_left_right();
	key_game_m();
	key_game_wsad();
	key_game_2();
	mlx_mouse_move((engine())->ptr, (engine())->win, \
		(engine())->size[X] * 0.5, (engine())->size[Y] * 0.5);
	return (0);
}
