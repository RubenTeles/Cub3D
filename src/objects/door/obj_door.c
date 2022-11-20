/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:58:17 by rteles            #+#    #+#             */
/*   Updated: 2022/11/20 15:38:14 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

int ft_create_door(t_object *door)
{
	door->avatar = (canva())->sprite(DOOR);
	door->sprite = (canva())->sprite(DOOR);
	door->collision = 0;
    return (1);
}
