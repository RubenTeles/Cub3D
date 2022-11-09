/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:27 by rteles            #+#    #+#             */
/*   Updated: 2022/11/09 15:37:21 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
/*


void	new_player(char **map)
{
	(player())->sprite = malloc(sizeof(t_data));
	(player())->sprite->title = '';
	(player())->sprite->path = NULL;
	(player())->sprite->img = mlx_new_image((engine())->ptr, (engine())->size[X], \
	(engine())->size[X]);
	(player())->sprite->larg = (engine())->size[X];
	(player())->sprite->alt = (engine())->size[Y];
	(player())->sprite->addr = mlx_get_sprite_addr((player())->sprite->img, \
	&(player())->sprite->bits_per_pixel, &(player())->sprite->line_length, \
	&(player())->data->endian);
	(player())->data->next = NULL;
	(player())->alphabet = NULL;
	(player())->rsz[X] = 0;
	(player())->rsz[Y] = 0;
	(player())->sprite = ft_sprite;
	(player())->getPxColor = get_pixel_color;
	(player())->put_pixel = my_mlx_pixel_put;
	(player())->resize = resize_image;
	(player())->create_sprite = create_sprite;
	(player())->create_alphabet = create_alphabet;
	(player())->search = search_sprite;
	(player())->last = last_sprite;
	(player())->destroy = __destroy;
}*/

t_player1	*player(void)
{
	static t_player1	p;

	return (&p);
}
