/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:24:48 by rteles            #+#    #+#             */
/*   Updated: 2022/11/04 19:06:07 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

#define FOREST '1'
#define PIG 'p'
#define DOOR 'd'

char	*ft_path(char sprite)
{
	if (sprite == 'N' || sprite == 'S' || sprite == 'W' || sprite == 'E')
		return ("./sprite/wolf/hand0.xpm");
	if (sprite == FOREST)
		return ("./sprite/forest.xpm");
	if (sprite == PIG)
		return ("pig/s");
	if (sprite == DOOR)
		return ("door");
	return (0);
}

void	ft_print_color(int larg, int alt, int pos_x, int pos_y, int color)
{
	int		x;
	int		y;

	y = -1;
	while (++y <= alt)
	{
		x = -1;
		while (++x <= larg)
			my_mlx_pixel_put((canva())->data, x + pos_x, y + pos_y, color);
	}
}

void	ft_sprite(char sprite, int x, int y)
{
	t_data	*data;

	data = (canva())->search(sprite);
	if (!data && sprite != ' ' && sprite != '0')
		data = (canva())->create(sprite);
	if (sprite == ' ')
		ft_print_color((canva())->rsz[X], (canva())->rsz[Y], x * \
		(canva())->rsz[X], y * (canva())->rsz[Y], (engine())->color[CEILLING]);
	else if (sprite != '1')
		ft_print_color((canva())->rsz[X], (canva())->rsz[Y], x * \
		(canva())->rsz[X], y * (canva())->rsz[Y], (engine())->color[FLOOR]);
	if (!data)
	{
		if (sprite == '0' || sprite == ' ')
			return ;
		printf("Erro: '%c' não existe!\n", sprite);
		return ;
	}
	if (data->title == 'N')
	{
		printf("Width: %i = %i\nHeigth: %i = %i\n", data->larg, data->alt, \
		(canva())->rsz[X], (canva())->rsz[Y]);
		resize_image(data, 75, 40, x * (canva())->rsz[X] + \
		(canva())->rsz[X]/4, y * (canva())->rsz[Y] + (canva())->rsz[Y]/4);
	}
	else
		resize_image(data, (canva())->rsz[X], (canva())->rsz[Y], x * \
		(canva())->rsz[X], y * (canva())->rsz[Y]);
}