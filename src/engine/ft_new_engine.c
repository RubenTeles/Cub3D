/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/10/26 21:49:06 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

t_canva	*create_image(void)
{
	/*t_canva	*c;
	int		offset;

	c = malloc(sizeof(t_canva));
	c->data->img = mlx_new_image((engine())->ptr, 1344, 756);
	c->data->addr = mlx_get_data_addr(c->data->img, &c->data->bits_per_pixel, \
	&c->data->line_length, &c->data->endian);
	offset = (756 * c->data->line_length + 1344 *\
	(c->data->bits_per_pixel / 8));
	//(void)offset;
	c->put_pixel = my_mlx_pixel_put;
	return (c);*/
	return (0);
}

void	new_engine(t_map *map)
{
	t_list	*aux;

	aux = map->map;
	/*while (aux)
	{
		printf("%p\n", (char *)aux->content);
		aux = aux->content;
	}*/
	(void)aux;
	(engine())->ptr = mlx_init();
	if (!engine()->ptr)
		return ;
	(engine())->win = mlx_new_window((engine())->ptr, 1344, 756, "WOLF EAT PIG'S");
	(engine())->game = NULL;
	(engine())->max_x = 0;
	(engine())->max_y = 0;
	(engine())->check_point[0] = NULL;
	(engine())->check_point[1] = NULL;
	//(engine())->canva = malloc(sizeof(t_canva));//create_image();
	//(engine())->canva->put_pixel = my_mlx_pixel_put;
	//my_mlx_pixel_put((engine())->canva->data, 5, 5, 0x00FF0000);
	//mlx_put_image_to_window((engine())->ptr, (engine())->win, (engine())->canva->data->img, 0, 0);
	//mlx_loop((engine()->ptr));
}

t_engine	*engine(void)
{
	static t_engine	e;

	return (&e);
}
