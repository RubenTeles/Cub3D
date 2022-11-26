/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:34:27 by rteles            #+#    #+#             */
/*   Updated: 2022/11/26 11:34:50 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <sys/time.h>
# include <ft_cub.h>
# include <ft_raycaster.h>

typedef struct s_engine				t_engine;
typedef struct s_canva				t_canva;
typedef struct s_data				t_data;
typedef struct s_key				t_key;
typedef struct s_scene				t_scene;
typedef struct s_scene_img			t_scene_img;
typedef struct s_sound				t_sound;
typedef struct s_object				t_object;
typedef struct s_player1			t_player1;
typedef struct s_aux				t_aux;

# define X 0
# define Y 1
# define FLOOR 0
# define CEILLING 1

struct s_aux
{
	double		x;
	double		y;
	int			larg;
	int			alt;
	double		dir[2];
};

struct s_key
{
	int		key;
	int		on;
	int		is_on;
	int		(*search)(int keycode);
	void	(*turn_on_off)(int keycode, int turn);
	void	(*destroy)(void);
};

struct s_scene
{
	int			complete;
	void		(*init)(void);
	int			(*key)(void);
	t_scene		*next;
};

struct s_scene_img
{
	int		on;
	double	animation;
	int		option;
	void	(*show)(t_scene_img *scene);
};

struct s_sound
{
	int 		pid;
	int			status;
	char		*sound;
	int			len;
	long long	dif;
	void		(*play)(t_sound *sound);
	void		(*stop)(t_sound *sound);
	void		(*destroy)(void);
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
	int				load;
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
	long long	start_time;	
	double		time;
	long long	start_pause;
	double		pause_time;
	long int	dif_time;
	int			sprt_for_sec;
	int			menu;
	int			pause;
	t_key		*key;
	t_object	*enemies;
	t_object	*object;
	t_sound		*sound;
};

struct s_canva
{
	t_data		*data;
	int			rsz[2];
	t_scene		*scene;
	t_scene		*scene_show;
	t_scene_img	*scene_img;
	t_data		*(*sprite)(int sprite);
	void		(*put)(t_data *data, int x, int y);
	int			(*getPxColor)(t_data *data, int x, int y);
	void		(*resize)(t_data *img, double larg, double alt, \
	int pos_x, int pos_y);
	void		(*put_pixel)(t_data *data, int x, int y, int color);
	void 		(*create_data)(int min, int max);
	t_data		(*create_sprite)(t_data new, int sprite);
	t_data		*(*alphabet)(char c);
	void		(*reset_scenes)(void);
	void		(*show_scenes)(void);
	void		(*destroy)(void);
};

struct s_object
{
	int			title;
	t_data		*avatar;
	t_data		*sprite;
	char		*map;
	double		pos[2];
	double		dir[2];
	double		dimension[3];
	double		vel;
	double		turn;
	int			life;
	int			collision;
	double		interation;
	int			is_near;
	void		(*player_interation)(t_object *obj, int key);
	void		(*player_near)(t_object *obj, int key);
	void		(*create)(char title, int x, int y);
	int			(*is_collision)(t_object *obj, double x, double y, int option);
	t_object	*(*last)(t_object *obj);
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
	double	interation;
	int		move;
	double	fadigue;
	int		life;
	int		lives;
	int		atack;
	void	(*movement)(int move_x, int move_y, int dir_x, int dir_y);
	void	(*obj_interation)(int key);
};

//static
t_engine		*engine(void);
t_canva			*canva(void);
t_player1		*player(void);

//Sound
void			new_sound(void);

//canva
void			new_canva(void);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				get_pixel_color(t_data *data, int x, int y);
void			resize_image(t_data *img, double larg, double alt, int pos_x,\
int pos_y);
void			rev_resize_image(t_data *img, double larg, double alt,\
int pos_x, int pos_y);
t_data			*ft_sprite(int sprite);
void			ft_put_canva(t_data *data, int x, int y);
void			ft_print_color(int larg, int alt, int pos_x, int pos_y,\
int color);
void			ft_path_start(void);
t_data			create_sprite(t_data new, int sprite);
int				put_clouds(t_data *img, int x, int pos_x);
t_data			*ft_alphabet(char c);
void			ft_put_word(char *str, double larg, double alt, int pos_x,\
int pos_y);

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

//Menu
int 			menu_hooks(void);
void			ft_words_menu(void);
void			ft_head_wolf(double move);
void		 	ft_create_game(void);
int 			menu_game(double time);

//Object
t_object		*ft_new_object(char title, int x, int y);
int				is_collision(t_object *obj, double x, double y, int option);
int				ft_managemen_objects(char tittle, t_object *obj);
int				map_to_sprite(char title);

//Objects and Enimes
int				ft_create_door(t_object *door);
int 			ft_create_pig(t_object *pig);
int 			ft_create_cristal(t_object *cristal);
int 			ft_create_bush(t_object *bush);

//PLAYER
void			new_player(void);
void			all_interation(t_object *obj, double x, double y, int option);
void			is_interation(t_object *obj, int keycode);

//Colors
int				ft_trgb(unsigned char t, unsigned char r, \
unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

//Scenes
void			new_scenes(void);
void			init_management_scenes(void);
void 			scene_login(void);
void 			scene_menu(void);
void 			scene_game(void);
void 			scene_pause(void);

//Image_Scenes
void			new_scenes_img(void);
void			ft_login(t_scene_img *scene);
void			ft_initial_menu(t_scene_img *scene);
void			ft_background(t_scene_img *scene);
void			ft_run(t_scene_img *scene);
void			ft_hands(t_scene_img *scene);
void			ft_life(t_scene_img *scene);
void			ft_minimap(t_scene_img *scene);
void			ft_map(t_scene_img *scene);
void			ft_press_e(t_scene_img *scene);
void			ft_tasks(t_scene_img *scene);
void			ft_pause(t_scene_img *scene);

// Raycasting
double			ft_abs(double x);
void			ft_set_camera(void);
void			ft_calc_plane(void);
void			ft_raycasting(t_scene_img *scene);
void			ft_rotate_dir(double a);
int				ft_get_ray_color(t_data	*data, int tex_x, int tex_y, int condition);
int				ft_texture_num(int map_x, int map_y, int side, t_view view);

// Fog
int				ft_fog(t_data *data, double time);
int				ft_linear_gradient(int colors[2], float percent);
double			ft_dist_pts(double x1, double y1, double x2, double y2);
int				ft_grade_color(t_view *view, float x, float y, int color);


//Utils
long long		time_current(void);
long long		time_diff(long long past, long long pres);

//End
int				end_game(void);

#endif