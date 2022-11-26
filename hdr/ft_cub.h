/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:56:15 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/26 17:55:59 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB_H
# define FT_CUB_H

# include <ft_string.h>
# include <ft_array.h>
# include <ft_list.h>
# include <mlx.h>
# include <math.h>
# include <unistd.h> // read
# include <fcntl.h> // open, close, ...
# include <stdio.h> // printf
# include <ft_engine.h>
# include <ft_raycaster.h>

# define BUFFERSIZE 9999

typedef struct s_map_info
{
	t_list	*map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**f;
	char	**c;
}			t_map;

typedef struct s_board_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_all
{
	t_map		*file;
	char		**map;
	t_pos		player;
	t_caster	caster;
	t_data		**data;
	int			fog_color;
	int			mouse_x;
	int			fog_checker;
	int			stop_weather;
	double		pitch;
}			t_all;

// utils
char	*get_next_line(int fd);

// map
t_list	*ft_read_map(char *filename);
int		ft_check_line(char *line);
int		ft_is_path(char *str);
int		ft_is_color(char *str);
void	ft_choose_inf_elm(t_map *map, char *line);
t_list	*ft_del_w_spc(t_list *map, int j);
t_map	*ft_checker(int argc, char **argv);
int		ft_check_map_info(t_map *map);
void	ft_init_map_info(t_map *map);
void	ft_free_map_inf(t_map *map);
int		ft_map_inf_filed(t_map *map, char *line);
int		ft_checkplayer(t_map *map);
t_map	*ft_check_map(int argc, char **argv);
int		ft_nextpos(t_list *board, t_pos atual, t_pos *next);
t_pos	ft_player_pos(t_list *board);
int		ft_find_paths(t_map *map, t_pos atual);
int		ft_mapclosed(t_map *map);
char	**ft_lst_toarr(t_all *all);
char	*ft_map_error(int i);

// Aditional functions for lists
t_list	*ft_lst_copy(t_list *lst);

// test
void	ft_print_mapinf(t_map *map);
void	ft_view_init(void);
void	ft_start_caster(void);
t_all	*all(void);

//conjunto
int		ft_start(t_all	*all);
void	new_engine(t_all *all, int larg, int alt);

#endif