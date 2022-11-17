/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/11/17 17:04:02 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>

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
	
	ft_background(0);
	ft_walls();
	ft_hands(0, 0);
	ft_minimap();
	ft_life();
	if (count >= 3)
		key_management();
	if ((engine())->map)
		ft_map();
	ft_pause();
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

	if ((engine())->count < 0 ||\
		(engine())->count > (1000 / (engine())->sprt_for_sec))
	{
		a = 0;
		(engine())->dif_time = time_current();
	}
	(engine())->count = time_diff((engine())->dif_time, time_current());
	if ((engine())->count == (1000 / (engine())->sprt_for_sec) && a == 0)
	{
		if ((engine())->menu)
			return (menu_game((engine())->count * 0.001));
		if ((engine())->pause > 0)
			return (pause_game());
		if (all()->wall == 0)
			ft_background(0.00017);
		ft_walls();
		ft_hands(0.0004, 0);
		ft_life();
		ft_minimap();
		key_management();
		a = 1;
		if ((engine())->map)
			ft_map();
		(engine())->time += (engine())->count * 0.001;
		//printf("%fs\n", (engine())->time);
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
	mlx_loop_hook((engine())->ptr, loop_game, 0);
	mlx_loop((engine())->ptr);
	return (0);
}
