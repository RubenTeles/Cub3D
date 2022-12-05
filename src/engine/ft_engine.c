/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/12/05 19:22:15 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_scenes.h>
#include <ft_scenes_images.h>

long long	time_current(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000000 + t.tv_usec) / 1000);
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

int	loop_aux(long long start, int time)
{
	if (time > (engine())->sprt_for_sec)
	{
		while (time > 60)
		{
			time = (int)(1000 / time_diff(start, time_current()));
			usleep(10);
		}
	}
	ft_enemies_move();
	(engine())->time = time_diff((engine())->start_time, \
	time_current()) * 0.001;
	(canva())->word("FPS ", \
	ft_aux((engine())->size[X] * 0.05, (engine())->size[Y] * 0.02, \
	(engine())->size[X] * 0.915, (engine())->size[Y] * 0.956), 0);
	(canva())->word((string()).itoa(time), \
	ft_aux((engine())->size[X] * 0.03, (engine())->size[Y] * 0.02, \
	(engine())->size[X] * 0.955, (engine())->size[Y] * 0.956), 1);
	time = (int)(1000 / time_diff(start, time_current()));
	return (time);
}

int	loop_game(void)
{
	static int		a = 0;
	long long		start;
	static int		fps = 0;

	start = time_current();
	if ((engine())->count < 0 || \
		(engine())->count > (1000 / (engine())->sprt_for_sec))
	{
		a = 0;
		(engine())->dif_time = time_current();
	}
	(engine())->count = time_diff((engine())->dif_time, time_current());
	if (a == 0)
	{
		(canva())->show_scenes();
		a = 1;
		if (!(engine())->pause)
			fps = loop_aux(start, fps);
		else
			(engine())->pause_time = time_diff((engine())->start_pause, \
			time_current()) * 0.001;
		mlx_put_image_to_window((engine())->ptr, (engine())->win, \
			(canva())->data->img, 0, 0);
	}
	return (0);
}

int	ft_start(t_all *all)
{
	new_engine(all, 1344, 756);
	if (!(engine())->ptr)
		return (1);
	ft_create_game();
	mlx_put_image_to_window((engine())->ptr, (engine())->win, \
		(canva())->data->img, 0, 0);
	mlx_hook((engine())->win, 17, 0, end_game, (engine()));
	mlx_do_key_autorepeaton((engine())->ptr);
	mlx_hook((engine())->win, 2, 1L << 0, key_press_in, 0);
	mlx_hook((engine())->win, 3, 1L << 1, key_press_out, 0);
	mlx_hook((engine())->win, 4, 1L << 2, key_press_in, 0);
	mlx_hook((engine())->win, 5, 1L << 3, key_press_out, 0);
	mlx_hook((engine())->win, 6, 1L << 6, key_mouse_move, 0);
	(canva())->scene = &(canva())->scene_show[SC_LOGIN];
	(canva())->scene->init();
	all->mouse_x = 700;
	mlx_loop_hook((engine())->ptr, loop_game, 0);
	mlx_loop((engine())->ptr);
	return (0);
}
