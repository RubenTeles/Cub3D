/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:06:47 by rteles            #+#    #+#             */
/*   Updated: 2022/11/26 23:40:52 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sound.h>
#include <signal.h>

void	ft_sound(t_sound *sound)
{
	int	i;

	sound->pid = fork();
	if (sound->pid == 0)
	{
		i = system(sound->sound);
		exit(0);
	}
	(void)i;
}

void	stop_music(t_sound *sound)
{
    kill(sound->pid, SIGTERM);
}

void	sound_path(void)
{
	(engine())->sound[SD_WOLF].sound = "paplay src/sound/wolf_2.ogg";
	//(engine())->sound[SD_MUSIC].sound = "paplay src/sound/music_open.ogg";
	(engine())->sound[SD_MUSIC].sound = "paplay src/sound/pMLWWiBvWX8_48.ogg";
	(engine())->sound[SD_BREADING_IN].sound = "paplay src/sound/breathe_in.ogg";
	(engine())->sound[SD_BREADING_OUT].sound = "paplay src/sound/breathe_out.ogg";
	(engine())->sound[SD_DOOR].sound = "paplay src/sound/open_door.ogg";
	(engine())->sound[SD_WOLF_HAPPY].sound = "paplay src/sound/wolf_celebration.ogg";
	(engine())->sound[SD_WOLF_DIE].sound = "paplay src/sound/wolf_die.ogg";
	(engine())->sound[SD_MINING].sound = "paplay src/sound/mining.ogg";
	(engine())->sound[SD_DIAMOND].sound = "paplay src/sound/diamond_collect.ogg";
	(engine())->sound[SD_BUSH].sound = "paplay src/sound/bush.ogg";
}

static void	destroy_sound(void)
{
	free((engine())->sound);
}

void	new_sound(void)
{
	(engine())->sound = malloc(sizeof(t_sound) * _MAX_SOUNDS_);
	sound_path();
	(engine())->sound->play = ft_sound;
	(engine())->sound->stop = stop_music;
	(engine())->sound->destroy = destroy_sound;
}
