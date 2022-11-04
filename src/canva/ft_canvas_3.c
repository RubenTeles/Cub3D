/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:21:14 by rteles            #+#    #+#             */
/*   Updated: 2022/10/31 10:00:30 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>


t_data	*search_sprite(char sprite)
{
	t_data	*aux;

	aux = (canva())->data;
	while (aux)
	{
		if (aux->title && aux->title == sprite)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

t_data	*last_sprite(void)
{
	t_data	*aux;

	aux = (canva())->data;
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
	(canva())->last()->next = new;
	return (new);
}