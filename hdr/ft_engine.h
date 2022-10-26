/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:34:27 by rteles            #+#    #+#             */
/*   Updated: 2022/10/25 01:09:48 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# include <ft_cub.h>

typedef struct s_engine				t_engine;
//typedef struct s_game				t_game;

struct s_engine {	
	void		*ptr;
	void		*win;
	char		**game;
	int			max_x;
	int			max_y;
	int			*check_point[2];
	int			count;
};

/*struct s_game {	
	void		*ptr;
	void		*win;
	char		**game;
	int			max_x;
	int			max_y;
	int			frst_pos_x;
	int			frst_pos_y;
	int			count;
};*/

int			start(t_map	*map);
void		new_engine(void);
t_engine	engine(void);

# define BUFFERSIZE 9999

#endif