/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:34:27 by rteles            #+#    #+#             */
/*   Updated: 2022/11/07 22:30:54 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <sys/time.h>
# include <ft_cub.h>

typedef struct s_engine				t_engine;
typedef struct s_canva				t_canva;
typedef struct s_data				t_data;
typedef struct s_player				t_player;

# define X 0
# define Y 1
# define FLOOR 0
# define CEILLING 1
# define ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_M 109
# define KEY_ENTER 65293
# define BUTTON_RIGHT 3
# define BUTTON_LEFT 1

struct s_data
{
	char			title;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*path;
	int				larg;
	int				alt;
	int				start_pos[2];
	t_data			*next;
};

struct s_engine
{
	void		*ptr;
	void		*win;
	int			*status;
	char		**game;
	int			color[2];
	int			size[2];
	int			max[2];
	int			count;
	int			pos[2];
	int			map;
	long int	time;
	long int	dif_time;
	int			sprt_for_sec;
	int			menu;
};

struct s_canva
{
	t_data		*data;
	int			rsz[2];
	t_data		*(*sprite)(char sprite);
	void		(*put)(t_data *data, int x, int y);
	int			(*getPxColor)(t_data *data, int x, int y);
	void		(*resize)(t_data *img, double larg, double alt, \
	int pos_x, int pos_y);
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
t_engine		*engine(void);
t_canva			*canva(void);

//canva
void			new_canva(void);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				get_pixel_color(t_data *data, int x, int y);
void			resize_image(t_data *img, double larg, double alt, int pos_x, \
int pos_y);
void	rev_resize_image(t_data *img, double larg, double alt, int pos_x, int pos_y);
t_data			*ft_sprite(char sprite);
void			ft_put_canva(t_data *data, int x, int y);
void			ft_print_color(int larg, int alt, int pos_x, int pos_y,\
				int color);
char			*ft_path(char sprite);
t_data			*create_sprite(char sprite);
t_data			*search_sprite(char sprite);
t_data			*last_sprite(void);
int				put_clouds(t_data *img, int x, int pos_x);
void			ft_initial_menu(double move);
void			ft_alpabeth(int letter);

//Colors
int				ft_trgb(unsigned char t, unsigned char r, \
unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

//Map
void			create_images_map(char **map);
void			ft_background(double move);
void			ft_hands(double move);
void			ft_minimap(char **map);

//Events
int				key_press_no_repeat(int keycode, char **map);
int 			key_press(int keycode, void *param);
int				key_mouse_press(int button, int x, int y, void *param);
int 			key_mouse_out(int button, int x, int y, void *param);
int				key_mouse_move(int x, int y, void *param);
int 			begin(void *param);

//End
int				end_game(void);


#endif