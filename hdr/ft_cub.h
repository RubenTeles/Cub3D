/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:56:15 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/19 17:47:55 by amaria-m         ###   ########.fr       */
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

# define BUFFERSIZE 9999

typedef struct	s_map_info
{
	t_list	*map;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	**F;
	char	**C;
}			t_map;

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
int		ft_mapclosed(t_map *map);

#endif