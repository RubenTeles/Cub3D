/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie_pig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:25:28 by rteles            #+#    #+#             */
/*   Updated: 2022/11/28 22:44:08 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_sound.h>
#include <ft_scenes_images.h>
#include <ft_keys.h>

static void	_player_near_pig(t_object *pig, int key)
{
	double	dif_x;
	double	dif_y;

	(void)key;
	dif_x = (pig->pos[X] > player()->pos[X] - (pig->pos[X] < player()->pos[X]));
	dif_y = (pig->pos[Y] > player()->pos[Y] - (pig->pos[Y] < player()->pos[Y]));
	if (!is_collision(pig, pig->pos[X] + (dif_x * pig->vel) + 0.5, \
	pig->pos[Y] + 0.5, 0))
		pig->pos[X] += (dif_x * pig->vel);
	if (!is_collision(pig, pig->pos[X] + 0.5, \
	pig->pos[Y] + (dif_y * pig->vel) + 0.5, 0))
		pig->pos[Y] += (dif_y * pig->vel);
}

static void	_interation_pig(t_object *pig, int key)
{
	(void)key;
	(void)pig;
}

int	ft_create_pig(t_object *pig)
{
	pig->avatar = (canva())->sprite(PIG_S0);
	pig->sprite = (canva())->sprite(PIG_S0);
	pig->life = 200;
	pig->collision = 1;
	pig->interation = 5;
	pig->dimension[X] = 1;
	pig->dimension[Y] = 1;
	pig->dimension[2] = 100;
	pig->vel = 0.5;
	pig->player_interation = _interation_pig;
	pig->player_near = _player_near_pig;
	return (1);
}
