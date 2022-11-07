/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/11/07 18:20:44 by amaria-m         ###   ########.fr       */
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

int menu_game(void)
{
	static int	a = 0;
	int			i;

	ft_initial_menu(0.01);
	if (a == 0)
	{
		//i = system("paplay src/music/pMLWWiBvWX8_48.ogg");
		a = 1;
	}
	(void)i;
	return (0);
}

int	loop_game(char **map)
{
	static double	time = 0;
	static int		a = 0;

	if ((engine())->count < 0 ||\
		(engine())->count > (1000 / (engine())->sprt_for_sec))
	{
		a = 0;
		(engine())->time = time_current();
	}
	(engine())->count = time_diff((engine())->time, time_current());
	if ((engine())->count == (1000 / (engine())->sprt_for_sec) && a == 0)
	{
		if ((engine())->menu)
			return (menu_game());
		ft_background(0.001);
		//ft_walls();
		ft_hands(0.001);
		ft_minimap();
		time += (engine())->count * 0.001;
		a = 1;
		if ((engine())->map)
			create_images_map(map);
		printf("%fs\n", time);
	}
	mlx_put_image_to_window((engine())->ptr, (engine())->win,\
		(canva())->data->img, 0, 0);
	return (0);
}

int	ft_start(t_all *all)
{
	new_engine(all, 1344, 756);
	if (!(engine())->ptr)
		return (1);
	//create_images_menu(all->map);
	mlx_put_image_to_window((engine())->ptr, (engine())->win,\
		(canva())->data->img, 0, 0);
	mlx_key_hook((engine())->win, key_press_no_repeat, all->map); //teclas
	mlx_hook((engine())->win, 2, 1L<<0, key_press, 0);
	mlx_hook((engine())->win, 4, 1L<<2, key_mouse_press, 0);
	mlx_hook((engine())->win, 5, 1L<<3, key_mouse_out, 0);
	mlx_hook((engine())->win, 6, 1L<<6, key_mouse_move, 0);
	mlx_hook((engine())->win, 17, 0, end_game, (engine()));//Fechar
	mlx_loop_hook((engine())->ptr, loop_game, all->map);
	mlx_loop((engine())->ptr);
	return (0);
}
