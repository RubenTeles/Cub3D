/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:34:46 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/20 16:18:28 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>

double	ft_abs(double x)
{
	if (x < (double)0)
		return (x * (double)-1);
	return (x);
}

void	ft_rotate_dir(double a)
{
	double	dir_x;
	double	dir_y;

	dir_x = all()->caster.player.dir_x;
	dir_y = all()->caster.player.dir_y;
	all()->caster.player.dir_x = dir_x * cos(a) - dir_y * sin(a);
	all()->caster.player.dir_y = dir_x * sin(a) + dir_y * cos(a);
}

void	ft_set_camera(void)
{
	char	dir;

	all()->caster.player.pos_x = (player())->pos[X];
	all()->caster.player.pos_y = (player())->pos[Y];
	if (all()->caster.player.dir_x == 0 && all()->caster.player.dir_y == 0)
	{
		dir = all()->map[(int)(player())->pos[Y]][(int)(player())->pos[X]];
		printf("1\n");
		all()->map[(int)(player())->pos[Y]][(int)(player())->pos[X]] = '0';
		if (dir == 'N' || dir == 'S')
			all()->caster.player.dir_x = 0;
		if (dir == 'W' || dir == 'E')
			all()->caster.player.dir_y = 0;
		if (dir == 'W')
			all()->caster.player.dir_x = -1;
		if (dir == 'E')
			all()->caster.player.dir_x = 1;
		if (dir == 'N')
			all()->caster.player.dir_y = -1;
		if (dir == 'S')
			all()->caster.player.dir_y = 1;
	}
}

void	ft_calc_plane(void)
{
	all()->caster.view.plane_x = all()->caster.player.dir_y;
	all()->caster.view.plane_y = all()->caster.player.dir_x * (double)-1;
	all()->caster.view.plane_x *= -0.66;
	all()->caster.view.plane_y *= -0.66;
	all()->caster.view.dir_x = all()->caster.player.dir_x * (player())->vision;
	all()->caster.view.dir_y = all()->caster.player.dir_y * (player())->vision;
	all()->caster.view.pos_x = all()->caster.player.pos_x;
	all()->caster.view.pos_y = all()->caster.player.pos_y;
	player()->dir[X] = all()->caster.player.dir_x;
	player()->dir[Y] = all()->caster.player.dir_y;
}

int	ft_get_ray_color(t_data	*data, int tex_x, int tex_y, int condition)
{
	int	arr[2];
	int	color;

	color = canva()->getPxColor(data, tex_x, tex_y);
	arr[0] = 1;
	arr[1] = color;
	if (condition)
		color = ft_linear_gradient(arr, 100);
	return (color);
}
