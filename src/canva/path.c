/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:24:48 by rteles            #+#    #+#             */
/*   Updated: 2022/11/18 15:25:35 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

char	*ft_path(char sprite)
{
	// if (sprite == 'N' || sprite == 'S' || sprite == 'W' || sprite == 'E')
	// 	return ("./sprite/item/sign.xpm");
	if (sprite == HAY)
		return ("./sprite/item/house_wall.xpm");//"./sprite/item/house_wall.xpm"
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
		return ("./sprite/item/minimap_2.xpm");
	if (sprite == HAND)
		return ("./sprite/wolf/hand_1.xpm");
	if (sprite == NICE)
		return ("./sprite/wolf/hand_nice.xpm");
	if (sprite == AVATAR_2)
		return ("./sprite/wolf/head0.xpm");
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
	if (sprite == WOOD_FLOOR)
		return ("./sprite/item/house_wall.xpm");
	if (sprite == SIGN)
		return ("./sprite/item/sign.xpm");
	if (sprite == DOOR)
		return ("./sprite/item/house_door.xpm");
	if (sprite == DOOR_OPEN)
		return ("./sprite/item/house_door_open.xpm");
	if (sprite == RUN)
		return ("./sprite/item/run_effect.xpm");
	if (sprite == WINDOW)
		return ("./sprite/item/house_window.xpm");
	return (0);
}
