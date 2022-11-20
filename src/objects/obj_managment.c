/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:02:42 by rteles            #+#    #+#             */
/*   Updated: 2022/11/20 15:39:31 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

int	map_to_sprite(char title)
{
	if (title == '1')
		return (TREE);
	if (title == '2')
		return (HAY);
	if (title == '3')
		return (WOOD_FLOOR);
	if (title == '4')
		return (WINDOW);
	if (title == '5')
		return (DOOR);
	if (title == '6')
		return (CAVE);
	return (0);
}

int	ft_managemen_objects(char tittle, t_object *obj)
{
	/*if (obj->title == HAY || obj->title == WINDOW)//2, 4
		return (ft_create_wall(obj));
	if (obj->title == WOOD_FLOOR)//3
		return (ft_create_floor(obj));*/
	(void)tittle;
	if (obj->title == DOOR)//5
		return (ft_create_door(obj));
	return (0);
}
