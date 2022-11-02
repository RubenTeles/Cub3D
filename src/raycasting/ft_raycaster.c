/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:05:02 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/02 18:27:55 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_raycaster.h>
#include <ft_cub.h>

void	pixel_put(t_img *img, int pixel, int color, void *mlx)
{
	if (img->bits != 32)
		color = mlx_get_color_value(mlx, color);
	if (img->endian)
	{
		img->addr[pixel + 0] = (color >> 24);
		img->addr[pixel + 1] = (color >> 16) & 0xFF;
		img->addr[pixel + 2] = (color >> 8) & 0xFF;
		img->addr[pixel + 3] = (color) & 0xFF;
	}
	else
	{
		img->addr[pixel + 0] = (color) & 0xFF;
		img->addr[pixel + 1] = (color >> 8) & 0xFF;
		img->addr[pixel + 2] = (color >> 16) & 0xFF;
		img->addr[pixel + 3] = (color >> 24);
	}
}

void	ft_start_caster(void)
{
	char	dir;

	all()->caster.player.pos_x = all()->player.x;
	all()->caster.player.pos_y = all()->player.y;
	dir = all()->map[all()->player.x][all()->player.y];
	printf("%c\n", dir);
	/*
	east = (-1, 0)
	west = (1, 0)
	north = (0, 1)
	south = (0, -1)
	*/
}

void	ft_view_init(void)
{
	// t_player	*player;
	// t_view		*view;
	t_screen	*scrn;
	t_img		*img;

	// view = &(all()->caster.view);
	// player = &(all()->caster.player);
	img = &(all()->caster.img);
	scrn = &(all()->caster.scrn);
	scrn->mlx = mlx_init();
	scrn->win = mlx_new_window(scrn->mlx, scrn->wdt, scrn->hgt, "Cub3D");
	img->img = mlx_new_image(scrn->mlx, scrn->wdt, scrn->hgt);
	img->addr = mlx_get_data_addr(img->img, &img->bits, &img->line, &img->endian);
	pixel_put(img, 5, 0x00FF0000, scrn->mlx);
	mlx_put_image_to_window(scrn->mlx, scrn->mlx, img->img, 0, 0);
}
