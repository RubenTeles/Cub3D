/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:14:54 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/23 17:42:43 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYCASTER_H
# define FT_RAYCASTER_H

# define NUMSPRITES 3

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
	double	*z_buffer;
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

typedef struct s_sprite
{
	double	x;
	double	y;
	int		texture;
}			t_spr;

typedef struct s_sprites_values
{
	int		sprite_order[NUMSPRITES];
	double	sprite_dist[NUMSPRITES];
	double	sprite_x;
	double	sprite_y;
	double	invdet;
	double	transform_x;
	double	transform_y;
	int		sprite_scrn_x;
	int		sprite_hgt;
	int		draw_str_y;
	int		draw_end_y;
	int		sprite_wdt;
	int		draw_str_x;
	int		draw_end_x;
	int		stripe;
	int		tex_x;
	int		y;
	int		d;
	int		tex_y;
	int		color;
	double	*buffer;
	t_spr	*sprite;
}			t_spr_vls;

typedef struct s_caster
{
	t_view		view;
	t_player	player;
	t_alg		alg;
}				t_caster;

// SPRITES
void	ft_ray_sprites(double *buffer, t_view *view, t_data **data, t_spr *sprite);
void	ft_sort_sprites(int *order, double *dist, int amount);
void	ft_print_stripe(t_spr_vls *copy, t_data **data, int i, int vmovescreen);

// FLOOR
void	ft_ray_floor(t_view *view, t_alg_fl a);

// GRADIENT UTILS
int		ft_linear_gradient(int colors[2], float percent);
float	ft_convert_time(double time, int n);

#endif
