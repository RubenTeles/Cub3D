/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/11/22 09:14:33 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_scenes.h>

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

int	pause_game()
{
	static int	count = 0;

	(canva())->scene[S_BACKGROUND].show(0);
	ft_raycasting();
	(canva())->scene[S_HAND].show(0);
	(canva())->scene[S_LIFE].show(0);
	(canva())->scene[S_MINI_MAP].show(0);
	if (count >= 3)
		key_management();
	if ((engine())->map)
		(canva())->scene[S_MAP].show(0);
	(canva())->scene[S_PAUSE].show(0);
	mlx_put_image_to_window((engine())->ptr, (engine())->win,\
		(canva())->data->img, 0, 0);
	count++;
	if ((engine())->pause == 0)
		count = 0;
	return (0);
}

int	loop_game(void)
{
	static int		a = 0;
	static int		x_wall = 0;

	if ((engine())->count < 0 ||\
		(engine())->count > (1000 / (engine())->sprt_for_sec))
	{
		a = 0;
		(engine())->dif_time = time_current();
	}
	(engine())->count = time_diff((engine())->dif_time, time_current());
	if ((engine())->count == (1000 / (engine())->sprt_for_sec) && a == 0)
	{
		x_wall++;
		if ((engine())->menu)
			return (menu_game((engine())->count * 0.001));
		if ((engine())->pause > 0)
			return (pause_game());
		(canva())->scene[S_BACKGROUND].show(&(canva())->scene[S_BACKGROUND]);
		ft_raycasting();
		(canva())->scene[S_HAND].show(&(canva())->scene[S_HAND]);
		key_management();
		(canva())->scene[S_LIFE].show(&(canva())->scene[S_LIFE]);
		(canva())->scene[S_MINI_MAP].show(&(canva())->scene[S_MINI_MAP]);
		a = 1;
		if ((engine())->map)
			(canva())->scene[S_MAP].show(&(canva())->scene[S_MAP]);
		(engine())->time += (engine())->count * 0.001;
		// printf("%fs\n", (engine())->time);
		mlx_put_image_to_window((engine())->ptr, (engine())->win,\
			(canva())->data->img, 0, 0);
	}
	return (0);
}

int	ft_start(t_all *all)
{
	new_engine(all, 1344, 756);
	if (!(engine())->ptr)
		return (1);
	ft_create_game();//TEMP.
	mlx_put_image_to_window((engine())->ptr, (engine())->win,\
		(canva())->data->img, 0, 0);
	mlx_hook((engine())->win, 17, 0, end_game, (engine()));//X
	mlx_do_key_autorepeaton((engine())->ptr);
	mlx_hook((engine())->win, 2, 1L<<0, key_press_in, 0);
	mlx_hook((engine())->win, 3, 1L<<1, key_press_out, 0);
	mlx_hook((engine())->win, 4, 1L<<2, key_press_in, 0);
	mlx_hook((engine())->win, 5, 1L<<3, key_press_out, 0);
	mlx_hook((engine())->win, 6, 1L<<6, key_mouse_move, 0);
	(canva())->scene[S_LOGIN].show(&(canva())->scene[S_LOGIN]);
	mlx_loop_hook((engine())->ptr, loop_game, 0);
	mlx_loop((engine())->ptr);
	return (0);
}
