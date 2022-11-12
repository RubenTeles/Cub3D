/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:24:48 by rteles            #+#    #+#             */
/*   Updated: 2022/11/12 12:49:37 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

#define FOREST '1'
#define DOOR 'd'
#define NICE 'n'
#define MINIMAP 'm'
#define PIG 'p'
#define MENU 'A'
#define HAND 'H'
#define CLOUD_1 'I'
#define CLOUD_2 'J'
#define CLOUD_3 'K'
#define MAP 'M'
#define ALPHABET 'P'
#define WALK 'Q'
#define TREE 'T'
#define N_WALL 'N'
#define S_WALL 'S'
#define W_WALL 'W'
#define E_WALL 'E'
#define SIGN 'U'
#define AVATAR 'X'

char	*ft_path(char sprite)
{
	// if (sprite == 'N' || sprite == 'S' || sprite == 'W' || sprite == 'E')
	// 	return ("./sprite/phpUnsLhe.xpm");
	if (sprite == MENU)
		return ("./sprite/item/background_menu.xpm");
	if (sprite == TREE)
		return ("./sprite/item/tree_02.xpm");
	/*if (sprite == PIG)
		return ("pig/s");*/
	if (sprite == CLOUD_1)
		return ("./sprite/item/cloud_1.xpm");
	if (sprite == CLOUD_2)
		return ("./sprite/item/cloud_2.xpm");
	if (sprite == CLOUD_3)
		return ("./sprite/item/cloud_3.xpm");
	if (sprite == MAP)
		return ("./sprite/item/map.xpm");
	if (sprite == MINIMAP)
		return ("./sprite/item/minimap.xpm");
	if (sprite == HAND)
		return ("./sprite/wolf/hand_1.xpm");
	if (sprite == NICE)
		return ("./sprite/wolf/hand_nice.xpm");
	if (sprite == AVATAR)
		return ("./sprite/wolf/head1.xpm");
	if (sprite == WALK)
		return ("./sprite/wolf/wolf_walk.xpm");
	if (sprite == N_WALL)
		return (all()->file->no);
	if (sprite == S_WALL)
		return (all()->file->so);
	if (sprite == W_WALL)
		return (all()->file->we);
	if (sprite == E_WALL)
		return (all()->file->ea);

	if (sprite == SIGN)
		return ("./sprite/item/sign.xpm");
	if (sprite == ALPHABET)
		return ("./sprite/item/alphabet.xpm");
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