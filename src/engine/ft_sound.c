/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:06:47 by rteles            #+#    #+#             */
/*   Updated: 2022/11/29 15:08:46 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sound.h>
#include <signal.h>

void	play_music(t_sound *sound)
{
	int	i;

	sound->dif = time_diff(sound->time_start, time_current());
	if (sound->dif > sound->len || sound->time_start == 0)
	{
		sound->time_start = time_current();
		sound->on = 1;
		sound->pid = fork();
		if (sound->pid == 0)
		{
			i = system(sound->sound);
			exit(0);
		}			
	}
	(void)i;
}

void	stop_music(t_sound sound)
{
	if (sound.on)
	{
		if (fork() == 0)
			kill(sound.pid, SIGTERM);
	}
}

static void	destroy_sound(void)
{
	int	i;

	i = -1;
	while (++i < _MAX_SOUNDS_)
		(engine())->sound->stop((engine())->sound[i]);
	free((engine())->sound);
}

void	new_sound(void)
{
	(engine())->sound = malloc(sizeof(t_sound) * _MAX_SOUNDS_);
	(engine())->sound->play = play_music;
	(engine())->sound->stop = stop_music;
	(engine())->sound->destroy = destroy_sound;
	sounds_init();
}
//(engine())->sound[SD_MUSIC].sound = "paplay src/sound/music_open.ogg";