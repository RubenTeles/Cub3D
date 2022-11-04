/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:21:56 by rteles            #+#    #+#             */
/*   Updated: 2022/10/31 10:01:34 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

static void	__destroy(void)
{
	t_data	*aux;
	t_data	*aux_2;

	aux = (canva())->data;
	while (aux)
	{
		aux_2 = aux;
		aux = aux->next;
		free(aux_2);
	}
}

void	new_canva(void)
{
	(canva())->data = malloc(sizeof(t_data));
	(canva())->data->title = 'Z';
	(canva())->data->path = NULL;
	(canva())->data->img = mlx_new_image((engine())->ptr, (engine())->size[X], \
	(engine())->size[X]);
	(canva())->data->larg = (engine())->size[X];
	(canva())->data->alt = (engine())->size[X];
	(canva())->data->addr = mlx_get_data_addr((canva())->data->img, \
	&(canva())->data->bits_per_pixel, &(canva())->data->line_length, \
	&(canva())->data->endian);
	(canva())->data->next = NULL;
	(canva())->rsz[X] = (engine())->size[X] / (engine())->max[X];
	(canva())->rsz[Y] = (engine())->size[Y] / (engine())->max[Y];
	(canva())->sprite = ft_sprite;
	(canva())->getPxColor = get_pixel_color;
	(canva())->put_pixel = my_mlx_pixel_put;
	(canva())->resize = resize_image;
	(canva())->create = create_sprite;
	(canva())->search = search_sprite;
	(canva())->last = last_sprite;
	(canva())->destroy = __destroy;
}

t_canva	*canva(void)
{
	static t_canva	c;

	return (&c);
}