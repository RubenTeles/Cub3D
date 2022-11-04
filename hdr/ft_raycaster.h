/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:14:54 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/04 17:00:04 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYCASTER_H
# define FT_RAYCASTER_H

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}			t_player;

typedef struct s_view
{
	double	plane_x;
	double	plane_y;
	double	time;
	double	oldtime;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
}			t_view;

typedef struct s_screen
{
	void	*mlx;
	void	*win;
	int		wdt;
	int		hgt;
}		t_screen;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
}			t_img;

typedef struct s_algrithm
{
	int		map_x;
	int		map_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}			t_algorithm;

typedef struct s_caster
{
	t_img		img;
	t_screen	scrn;
	t_view		view;
	t_player	player;
	t_algorithm	alg;
}				t_caster;

#endif
