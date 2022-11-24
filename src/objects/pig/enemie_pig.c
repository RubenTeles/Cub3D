/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie_pig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:25:28 by rteles            #+#    #+#             */
/*   Updated: 2022/11/24 11:20:48 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_sound.h>
#include <ft_scenes_images.h>

static void	_player_near_pig(t_object *pig, int key)
{
	(void)key;
	(void)pig;
	printf("PROXIMO DO PORCO\n");
}

static void	_interation_pig(t_object *pig, int key)
{
	(void)key;
	(void)pig;
}

int ft_create_pig(t_object *pig)
{
	pig->avatar = (canva())->sprite(PIG_S0);
	pig->sprite = (canva())->sprite(PIG_S0);
	pig->collision = 1;
	pig->interation = 5;
	pig->player_interation = _interation_pig;
	pig->player_near = _player_near_pig;
	return (1);
}
