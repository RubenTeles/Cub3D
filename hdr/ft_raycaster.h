/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:14:54 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/10 17:51:13 by amaria-m         ###   ########.fr       */
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
	char	buffer[10000][10000];
}			t_alg;

// typedef struct s_fov
// {
// 	int		pos_x;
// 	int		pos_y;
// 	float	angle;
// }	t_fov;

typedef struct s_caster
{
	t_view		view;
	t_player	player;
	t_alg		alg;
}				t_caster;

#endif
