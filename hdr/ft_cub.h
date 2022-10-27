/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:56:15 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/26 21:00:51 by rteles           ###   ########.fr       */
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

typedef struct s_player
{
	t_pos	pos;
	char	dir;
}			t_player;

typedef struct s_game_info
{
	char		**board;
	t_player	wolf;
	t_list		*pigs;
}				t_game;

typedef struct t_image
{
	void	*img_ptr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	int		width;
	int		height;
}		t_img;

typedef struct s_all
{
	t_map	*file;
	t_game	*pieces;
	void	*ptr;
	void	*win;
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
int		ft_free_all(t_all all);
int		ft_map_inf_filed(t_map *map, char *line);
int		ft_checkplayer(t_map *map);
t_map	*ft_check_map(int argc, char **argv);
int		ft_nextpos(t_list *board, t_pos atual, t_pos *next);
t_pos	ft_player_pos(t_list *board);
int		ft_find_paths(t_map *map, t_pos atual);
int		ft_mapclosed(t_map *map);
char	**ft_lst_toarr(t_list *lst);
char	*ft_map_error(int i);

// Aditional functions for lists
t_list	*ft_lst_copy(t_list *lst);

// game
int		ft_init_game(t_all *all);

// test
void	ft_try(t_list *lst);

// Conjunto
int		ft_start(t_map	*map);
void	new_engine(t_map	*map);

#endif