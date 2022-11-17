/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:34:27 by rteles            #+#    #+#             */
/*   Updated: 2022/11/17 10:50:37 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <sys/time.h>
# include <ft_cub.h>

typedef struct s_engine				t_engine;
typedef struct s_canva				t_canva;
typedef struct s_data				t_data;
typedef struct s_key				t_key;
typedef struct s_object				t_object;
typedef struct s_player1			t_player1;

# define X 0
# define Y 1
# define FLOOR 0
# define CEILLING 1

struct s_key
{
	int		key;
	int		on;
	t_key	*next;
    t_key	*(*create)(int keycode);
	t_key	*(*search)(int keycode);
	t_key	*(*last)(void);
	void	(*destroy)(void);
};

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
	double		time;
	long int	dif_time;
	int			sprt_for_sec;
	int			menu;
	int			pause;
	t_key		*key;
	t_object	*object;
};

struct s_canva
{
	t_data		*data;
	t_data		*alphabet;
	int			rsz[2];
	t_data		*(*sprite)(char sprite);
	void		(*put)(t_data *data, int x, int y);
	int			(*getPxColor)(t_data *data, int x, int y);
	void		(*resize)(t_data *img, double larg, double alt, \
	int pos_x, int pos_y);
	void		(*put_pixel)(t_data *data, int x, int y, int color);
	t_data		*(*create_sprite)(char sprite);
	t_data		*(*create_alphabet)(char c);
	t_data		*(*search)(t_data *data, char sprite);
	t_data		*(*last)(t_data *data);
	void		(*destroy)(void);
};


struct s_object
{
	char		title;
	t_data		*avatar;
	t_data		*sprite;
	double		pos[2];
	double		dir[2];
	double		vel;
	double		turn;
	int			life;
	int			collision;
	void		(*create)(char title, int x, int y);
	int			(*is_collision)(t_object *obj, double x, double y);
	t_object	*(*last)(void);
	void		(*destroy)(void);
	t_object	*next;
};

struct s_player1
{
	char	title;
	t_data	*avatar;
	t_data	*sprite;
	double	pos[2];
	double	dir[2];
	double	vel;
	double	turn;
	double	turn_times;
	double	vision;
	int		collision;
	int		move;
	double	fadigue;
	int		life;
	int		lives;
	void	(*movement)(int move_x, int move_y, int dir_x, int dir_y);
};

//static
t_engine		*engine(void);
t_canva			*canva(void);
t_player1		*player(void);

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
char			*path_alphabet(char	letter);
t_data			*create_alphabet(char c);
t_data			*create_sprite(char sprite);
t_data			*search_sprite(t_data *data, char sprite);
t_data			*last_sprite(t_data *data);
int				put_clouds(t_data *img, int x, int pos_x);
t_data			*ft_alphabet(char c);
void			ft_put_word(char *str, double larg, double alt, int pos_x, int pos_y);

//Keys
void			new_key(void);
t_data			*create(char sprite);
t_data			*search(t_data *data, char sprite);
t_data			*last(t_data *data);
int				key_press_in(int keycode);
int				key_press_out(int keycode);
int				key_mouse_move(int x, int y, void *param);
int				key_management(void);
int 			begin(void *param);
int				key_esc(void);

//Object
void			ft_new_object(char title, int x, int y);
int				is_collision(t_object *obj, double x, double y);

//Menu
int				ft_login(double move);
int 			menu_game(double time);
int 			menu_hooks(void);
void			ft_initial_menu(double move);
void			ft_words_menu(void);
void			ft_head_wolf(double move);
void		 	ft_create_game(void);

//Pause
void			ft_pause(void);

//PLAYER
void			new_player(void);
void			ft_life(void);

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
void			ft_hands(double move, int nice);
void			ft_minimap(char **map);
void			ft_walls(void);
void			ft_rotate_dir(double a);

//Utils
long long		time_current(void);
long long		time_diff(long long past, long long pres);

//End
int				end_game(void);

#endif