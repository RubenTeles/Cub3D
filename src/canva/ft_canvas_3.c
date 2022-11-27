/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:17:23 by rteles            #+#    #+#             */
/*   Updated: 2022/11/27 13:23:14 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

/*void	ft_print_color(int larg, int alt, int pos_x, int pos_y, int color)
{
	int		x;
	int		y;

	y = -1;
	while (++y <= alt)
	{
		x = -1;
		while (++x <= larg)
			if (color > 0)
				my_mlx_pixel_put(&(canva())->data[CANVA], \
					x + pos_x, y + pos_y, color);
	}
}*/

void	ft_print_color(t_aux aux, int color)
{
	int		x;
	int		y;

	y = -1;
	while (++y <= aux.alt)
	{
		x = -1;
		while (++x <= aux.larg)
			if (color > 0)
				my_mlx_pixel_put(&(canva())->data[CANVA], \
					x + aux.x, y + aux.y, color);
	}
}

void	ft_put_canva(t_data *data, int x, int y)
{
	if (data->title == 'M')
		resize_image(data, ft_aux((canva())->rsz[X], (canva())->rsz[Y], x, y));
	else if (data->title == 'N')
	{
		printf("WOLF:\nWidth: %i = %i\nHeigth: %i = %i\n", data->larg, data->alt, \
		(canva())->rsz[X], (canva())->rsz[Y]);
		resize_image(data, ft_aux((canva())->rsz[X] * 0.50, (canva())->rsz[Y] * \
		0.50, x * (canva())->rsz[X] + ((canva())->rsz[X] * 0.25), \
			y * (canva())->rsz[Y] + ((canva())->rsz[Y] * 0.25)));
	}
	else
		resize_image(data, ft_aux((canva())->rsz[X], (canva())->rsz[Y], x * \
		(canva())->rsz[X], y * (canva())->rsz[Y]));
}

t_aux	ft_aux(double larg, double alt, int x, int y)
{
	t_aux	aux;

	aux.alt = alt;
	aux.larg = larg;
	aux.x = x;
	aux.y = y;
	return (aux);
}
