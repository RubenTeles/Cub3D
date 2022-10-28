/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:34:27 by rteles            #+#    #+#             */
/*   Updated: 2022/10/29 00:21:11 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <ft_cub.h>

typedef struct s_engine				t_engine;
typedef struct s_canva				t_canva;

typedef struct	s_img {
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}				t_img;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

struct s_engine {
	void		*ptr;
	void		*win;
	int			*status;
	char		**game;
	int			max_x;
	int			max_y;
	int			*check_point[2];
	int			count;
	t_canva		*canva;
};

struct s_canva {
	t_data		*data;
	t_canva		*next;
	void		(*put_pixel)(t_data *data, int x, int y, int color);

};


t_engine	*engine(void);

//canva
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	get_pixel_color(t_data *data, int x, int y);

//Keys
int			key_hook_mode1(int keycode, void *all);

//End
int			end_game(void);

# define BUFFERSIZE 9999

#endif