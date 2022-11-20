/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:14:54 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/19 23:10:59 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYCASTER_H
# define FT_RAYCASTER_H

typedef struct s_data	t_data;

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
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}			t_view;

typedef struct s_algorithm
{
	int		x;
	int		y;
	int		w;
	double	h;
	double	cam_x;
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		map_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	perp_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		ln_hgt;
	int		draw_str;
	int		draw_end;
	int		texnum;
	double	texpos;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	int		tex_wdh;
	int		tex_hgt;
	int		color;
	int		check;
	int		percent;
}			t_alg;

typedef struct s_alg_floor
{
	int		y;
	int		x;
	int		h;
	int		w;
	float	ray_x0;
	float	ray_y0;
	float	ray_x1;
	float	ray_y1;
	int		p;
	float	posz;
	float	rowdist;
	float	stepx;
	float	stepy;
	float	floorx;
	float	floory;
	int		cellx;
	int		celly;
	int		tx;
	int		ty;
	int		floortex;
	int		c_tex;
	int		color;
	t_data	**data;
}			t_alg_fl;

typedef struct s_caster
{
	t_view		view;
	t_player	player;
	t_alg		alg;
}				t_caster;

#endif
