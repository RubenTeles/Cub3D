/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_game_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:51:31 by rteles            #+#    #+#             */
/*   Updated: 2022/11/28 19:56:08 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_keys.h>
#include <ft_sprites.h>
#include <ft_scenes.h>
#include <ft_scenes_images.h>
#include <ft_sound.h>

//Key TAB and P
static void	key_game_tab_p(void)
{
	if ((engine())->key[_KEY_P].on && ((engine())->pause == 0))
	{
		(engine())->start_pause = time_current();
		(engine())->pause = 1;
		(canva())->scene->complete = 1;
	}
	if ((engine())->key[_KEY_TAB].on)
		(canva())->scene_img[S_TASKS].on = 1;
	if (!(engine())->key[_KEY_TAB].on)
		(canva())->scene_img[S_TASKS].on = 0;
}

//Key E
static void	key_game_e(void)
{
	static int	a = 0;

	if (!(engine())->key[_KEY_E].on && a == 1)
	{
		(player())->obj_interation(KEY_E);
		a = 0;
	}
	else if ((engine())->key[_KEY_E].on && a == 0)
		a = 1;
}

//Key SHITF 2
static void	key_game_shitf_2(void)
{
	if ((engine())->key[_KEY_SHIFT].on && (player())->move && \
		(player()->fadigue - 3 <= 0))
	{
		(player())->vel = 0.10;
		(canva())->scene_img[S_RUN].on = 0;
	}
	if (!(engine())->key[_KEY_SHIFT].on && \
		((player())->vision <= 0.66 || (player())->fadigue + 0.25 < 100))
	{
		if ((player())->fadigue <= 100)
			(player())->fadigue += 0.25;
		if ((player())->vision < 0.66)
			(player())->vision += 0.1;
		(player())->vel = 0.10;
		(canva())->scene_img[S_RUN].on = 0;
	}
}

//Key SHITF 1
int	key_game_2(void)
{
	if ((engine())->key[_KEY_SHIFT].on && (player())->move && \
		(player())->fadigue - 2 >= 0)
	{
		if ((player())->vision >= 0.60)
			(player())->vision -= 0.01;
		(player())->vel = 0.30;
		(player())->move = 0;
		(player())->fadigue -= 2;
		(canva())->scene_img[S_RUN].on = 1;
	}
	else if ((engine())->key[_KEY_SHIFT].on && \
		(player())->vision <= 0.66 && (player())->move == 0)
	{
		(player())->vision += 0.001;
		(canva())->scene_img[S_RUN].on = 0;
	}
	key_game_shitf_2();
	key_game_e();
	key_game_tab_p();
	key_atack();
	return (0);
}
