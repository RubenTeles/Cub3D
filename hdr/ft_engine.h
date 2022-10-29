/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:34:27 by rteles            #+#    #+#             */
/*   Updated: 2022/10/29 22:44:15 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <ft_cub.h>

typedef struct s_engine				t_engine;
typedef struct s_canva				t_canva;

# define X 0
# define Y 1

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
	int		larg;
	int		alt;
}				t_data;

struct s_engine {
	void		*ptr;
	void		*win;
	int			*status;
	char		**game;
	int			size[2];
	int			max[2];
	int			count;
	int			pos[2];
};

struct s_canva {
	t_data		*data;
	void		(*sprite)(char sprite, int x, int y);
	int			(*getPxColor)(t_data *data, int x, int y);
	void		(*resize)(t_data *img, int larg, int alt, int pos_x, int pos_y);
	void		(*put_pixel)(t_data *data, int x, int y, int color);
	void		(*destroy)(void);
};

//static
t_engine	*engine(void);
t_canva		*canva(void);


// Conjunto
void	new_engine(char	**map);
void	new_canva(void);

//canva
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_pixel_color(t_data *data, int x, int y);
void	resize_image(t_data *img, int larg, int alt, int pos_x, int pos_y);
void	ft_sprite(char sprite, int x, int y);

//Keys
int			key_hook_mode1(int keycode, void *all);

//End
int		end_game(void);

# define BUFFERSIZE 9999

#endif