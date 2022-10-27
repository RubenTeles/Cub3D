/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:34:27 by rteles            #+#    #+#             */
/*   Updated: 2022/10/26 21:48:04 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <ft_cub.h>

typedef struct s_engine				t_engine;
typedef struct s_canva				t_canva;

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

//Keys
int			key_hook_mode1(int keycode, void *all);

//End
int			end_game(void);

# define BUFFERSIZE 9999

#endif