/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:05:02 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/04 18:38:26 by amaria-m         ###   ########.fr       */
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

void	ft_init_cas_values(void)
{
	all()->caster.scrn.hgt = 480;
	all()->caster.scrn.wdt = 640;
	all()->caster.view.plane_x = 0;
	all()->caster.view.plane_y = 0.66;
	all()->caster.view.time = 0;
	all()->caster.view.oldtime = 0;
}

// void	ft_set_camera(void)
// {
// 	char	dir;

// 	all()->player = ft_player_pos(all()->file->map);
// 	all()->caster.player.pos_x = (double)all()->player.x;
// 	all()->caster.player.pos_y = (double)all()->player.y;
// 	dir = all()->map[all()->player.x][all()->player.y];
// 	dir = 'E';
// 	if (dir == 'N' || dir == 'S')
// 		all()->caster.player.dir_x = 0;
// 	if (dir == 'W' || dir == 'E')
// 		all()->caster.player.dir_y = 0;
// 	if (dir == 'W')
// 		all()->caster.player.dir_x = -1;
// 	if (dir == 'E')
// 		all()->caster.player.dir_x = 1;
// 	if (dir == 'N')
// 		all()->caster.player.dir_y = 1;
// 	if (dir == 'S')
// 		all()->caster.player.dir_y = -1;
// 	ft_init_cas_values();

// }

// void	ft_casting_loop(t_player *player, t_view *view)
// {
// 	t_algorithm	*alg;
// 	int			x;

// 	alg = &(all()->caster.alg);
	
// }

// void	ft_view_init(void)
// {
// 	t_player	*player;
// 	t_view		*view;
// 	t_screen	*scrn;
// 	t_img		*img;

// 	view = &(all()->caster.view);
// 	player = &(all()->caster.player);
// 	img = &(all()->caster.img);
// 	scrn = &(all()->caster.scrn);
// 	scrn->mlx = mlx_init();
// 	scrn->win = mlx_new_window(scrn->mlx, scrn->wdt, scrn->hgt, "Cub3D");
// 	img->img = mlx_new_image(scrn->mlx, scrn->wdt, scrn->hgt);
// 	img->addr = mlx_get_data_addr(img->img, &img->bits, &img->line, &img->endian);
// 	pixel_put(img, 50, 0x00FF0000, scrn->mlx);
// 	mlx_put_image_to_window(scrn->mlx, scrn->win, img->img, 0, 0);
// 	ft_casting_loop(player, view);
// }
