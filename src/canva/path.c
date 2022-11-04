/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:24:48 by rteles            #+#    #+#             */
/*   Updated: 2022/11/04 19:17:41 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

#define FOREST '1'
#define PIG 'p'
#define DOOR 'd'
#define MAP 'M'
#define HAND 'H'
#define NICE 'n'

char	*ft_path(char sprite)
{
	if (sprite == 'N' || sprite == 'S' || sprite == 'W' || sprite == 'E')
		return ("./sprite/wolf/head1.xpm");
	if (sprite == FOREST)
		return ("./sprite/item/tree_02.xpm");
	/*if (sprite == PIG)
		return ("pig/s");*/
	if (sprite == MAP)
		return ("./sprite/item/map.xpm");
	if (sprite == HAND)
		return ("./sprite/wolf/hand_1.xpm");
	if (sprite == NICE)
		return ("./sprite/wolf/hand_nice.xpm");
	/*if (sprite == DOOR)
		return ("door");*/
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

t_data	*ft_sprite(char sprite)
{
	t_data	*data;

	data = (canva())->search(sprite);
	if (!data && sprite != ' ' && sprite != '0')
		data = (canva())->create(sprite);
	if (!data)
	{
		if (sprite == '0' || sprite == ' ')
			return (0);
		printf("Erro: '%c' não existe!\n", sprite);
		return (0);
	}
	return (data);
}

void	ft_put_canva(t_data *data, int x, int y)
{
	if (data->title == 'M')
		resize_image(data, (canva())->rsz[X], (canva())->rsz[Y], x, y);
	else if (data->title == 'N')
	{
		printf("WOLF:\nWidth: %i = %i\nHeigth: %i = %i\n", data->larg, data->alt, \
		(canva())->rsz[X], (canva())->rsz[Y]);
		resize_image(data, (canva())->rsz[X] * 0.50, (canva())->rsz[Y] * 0.50,\
			x * (canva())->rsz[X] + ((canva())->rsz[X] * 0.25),\
			y * (canva())->rsz[Y] + ((canva())->rsz[Y] * 0.25));
	}
	else
		resize_image(data, (canva())->rsz[X], (canva())->rsz[Y], x * \
		(canva())->rsz[X], y * (canva())->rsz[Y]);
}