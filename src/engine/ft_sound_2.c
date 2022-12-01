/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sound_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:06:47 by rteles            #+#    #+#             */
/*   Updated: 2022/12/01 17:09:50 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sound.h>

static void	sound_path(void)
{
	(engine())->sound[SD_WOLF].sound = "paplay src/sound/wolf_.ogg";
	(engine())->sound[SD_MUSIC].sound = "paplay src/sound/music.ogg";
	(engine())->sound[SD_BREADING_IN].sound = "paplay src/sound/breathe_in.ogg";
	(engine())->sound[SD_BREADING_OUT].sound = \
	"paplay src/sound/breathe_out.ogg";
	(engine())->sound[SD_DOOR].sound = "paplay src/sound/open_door.ogg";
	(engine())->sound[SD_WOLF_HAPPY].sound = \
	"paplay src/sound/wolf_celebration.ogg";
	(engine())->sound[SD_WOLF_HURT].sound = "paplay src/sound/wolf_hurt.ogg";
	(engine())->sound[SD_WOLF_DIE].sound = "paplay src/sound/wolf_die.ogg";
	(engine())->sound[SD_MINING].sound = "paplay src/sound/mining.ogg";
	(engine())->sound[SD_DIAMOND].sound = \
	"paplay src/sound/diamond_collect.ogg";
	(engine())->sound[SD_BUSH].sound = "paplay src/sound/bush.ogg";
	(engine())->sound[SD_PIG_RUN].sound = "paplay src/sound/pig_run.ogg";
	(engine())->sound[SD_PIG_ATACKED].sound = "paplay src/sound/pig_atack.ogg";
	(engine())->sound[SD_PIG_DIED].sound = "paplay src/sound/pig_die.ogg";
	(engine())->sound[SD_BULL].sound = "paplay src/sound/bull.ogg";
	(engine())->sound[SD_BULL_RUN].sound = "paplay src/sound/bull_run.ogg";
	(engine())->sound[SD_KEYS].sound = "paplay src/sound/keys.ogg";
	(engine())->sound[SD_DENNY].sound = "paplay src/sound/denny.ogg";
}

static void	sound_len(void)
{
	(engine())->sound[SD_WOLF].len = 1000;
	(engine())->sound[SD_MUSIC].len = 1000;
	(engine())->sound[SD_BREADING_IN].len = 750;
	(engine())->sound[SD_BREADING_OUT].len = 0;
	(engine())->sound[SD_DOOR].len = 0;
	(engine())->sound[SD_WOLF_HAPPY].len = 900;
	(engine())->sound[SD_WOLF_HURT].len = 0;
	(engine())->sound[SD_WOLF_DIE].len = 1000;
	(engine())->sound[SD_MINING].len = 700;
	(engine())->sound[SD_DIAMOND].len = 0;
	(engine())->sound[SD_BUSH].len = 700;
	(engine())->sound[SD_PIG_RUN].len = 500;
	(engine())->sound[SD_PIG_ATACKED].len = 650;
	(engine())->sound[SD_PIG_DIED].len = 1000;
	(engine())->sound[SD_BULL].len = 1200;
	(engine())->sound[SD_BULL_RUN].len = 1400;
	(engine())->sound[SD_KEYS].len = 0;
	(engine())->sound[SD_DENNY].len = 0;
}

void	sounds_init(void)
{
	int	i;

	i = -1;
	sound_path();
	sound_len();
	while (++i < _MAX_SOUNDS_)
	{
		(engine())->sound[i].time_start = 0;
		(engine())->sound[i].on = 0;
	}
}
//(engine())->sound[SD_MUSIC].sound = "paplay src/sound/music_open.ogg";