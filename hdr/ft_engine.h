/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:34:27 by rteles            #+#    #+#             */
/*   Updated: 2022/10/30 18:07:27 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <ft_cub.h>

typedef struct s_engine				t_engine;
typedef struct s_canva				t_canva;
typedef struct s_data				t_data;

# define X 0
# define Y 1

typedef struct	s_data {
	char	title;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*path;
	int		larg;
	int		alt;
	t_data	*next;
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
	int			rsz[2];
	void		(*sprite)(char sprite, int x, int y);
	int			(*getPxColor)(t_data *data, int x, int y);
	void		(*resize)(t_data *img, double larg, double alt, int pos_x, int pos_y);
	void		(*put_pixel)(t_data *data, int x, int y, int color);
	t_data		*(*create)(char sprite);
	t_data		*(*search)(char sprite);
	t_data		*(*last)(void);
	void		(*destroy)(void);
};
/*
struct s_player
{

};*/


//static
t_engine	*engine(void);
t_canva		*canva(void);


// Conjunto
void	new_engine(char	**map);
void	new_canva(void);

//canva
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_pixel_color(t_data *data, int x, int y);
void	resize_image(t_data *img, double larg, double alt, int pos_x, int pos_y);
void	ft_sprite(char sprite, int x, int y);
char	*ft_path(char sprite);
t_data	*create_sprite(char sprite);
t_data	*search_sprite(char sprite);
t_data	*last_sprite(void);

//Keys
int			key_hook_mode1(int keycode, void *all);

//End
int		end_game(void);

# define BUFFERSIZE 9999

#endif