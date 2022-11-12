/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas_methods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:21:14 by rteles            #+#    #+#             */
/*   Updated: 2022/11/12 14:18:02 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

t_data	*search_sprite(t_data *data, char sprite)
{
	t_data	*aux;

	aux = data;
	while (aux)
	{
		if (aux->title && aux->title == sprite)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

t_data	*last_sprite(t_data *data)
{
	t_data	*aux;

	aux = data;
	while (aux)
	{
		if (!aux->next)
			break ;
		aux = aux->next;
	}
	return (aux);
}

t_data	*create_sprite(char sprite)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (0);
	new->title = sprite;
	new->path = ft_path(sprite);
	new->img = mlx_xpm_file_to_image((engine())->ptr, new->path, &new->larg, \
	&new->alt);
	if (!new->img)
	{
		printf("Erro: Sprite '%c' com o Path: '%s' não existe!\n", \
		sprite, new->path);
		free(new);
		return (NULL);
	}
	new->addr = mlx_get_data_addr(new->img, &new->bits_per_pixel, \
	&new->line_length, &new->endian);
	new->next = NULL;
	(canva())->last((canva()->data))->next = new;
	return (new);
}

t_data	*ft_sprite(char sprite)
{
	t_data	*data;

	data = (canva())->search((canva())->data, sprite);
	if (!data && sprite != ' ' && sprite != '0')
		data = (canva())->create_sprite(sprite);
	if (!data)
	{
		if (sprite == '0' || sprite == ' ')
			return (0);
		printf("Erro: '%c' não existe!\n", sprite);
		return (0);
	}
	return (data);
}
