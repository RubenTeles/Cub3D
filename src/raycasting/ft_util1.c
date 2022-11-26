/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:41:00 by amaria-m          #+#    #+#             */
/*   Updated: 2022/11/26 20:56:25 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_cub.h>
#include <ft_sprites.h>
#include <ft_raycaster.h>

int	ft_texture_num(int map_x, int map_y, int side, t_view view)
{
	char	c;

	c = all()->map[map_y][map_x];
	if (c == '1')
	{
		if (side == 1 && map_y > view.pos_y)
			return (1);
		if (side == 0 && map_x > view.pos_x)
			return (3);
		if (side == 0 && map_x < view.pos_x)
			return (2);
		if (side == 0 && view.dir_x == 0 && map_x > view.pos_x)
			return (3);
		if (side == 0 && view.dir_x == 0)
			return (2);
	}
	else if (c == 'd' || c == 'D')
		return (4 + (c == 'D'));
	else if (c == 'm' || c == 'M')
		return (6 + (c == 'M'));
	else if (c == 'C')
		return (8);
	return (0);
}

float	ft_convert_time(double time, int n)
{
	static int	time_capsule;
	static int	past_value;
	int			t;
	int			t2;

	t = (((int)time - 1) % n) + 1;
	if (time_capsule != t)
	{
		time_capsule = t;
		past_value = t;
		t2 = (n - t) + 1;
		if (t == n)
		{
			all()->fog_checker = (all()->fog_checker == 0);
			if (all()->fog_checker)
				return ((float)t);
			past_value = t2;
			return ((float)t2);
		}
		if (all()->fog_checker)
		{
			past_value = t2;
			return ((float)t2);
		}
		return ((float)t);
	}
	else
		return ((float)past_value);
}

int	ft_setup_ray_imgs(t_data **data)
{
	data[0] = (canva())->sprite(N_WALL);
	data[1] = (canva())->sprite(S_WALL);
	data[2] = (canva())->sprite(W_WALL);
	data[3] = (canva())->sprite(E_WALL);
	data[4] = (canva())->sprite(DOOR_OPEN);
	data[5] = (canva())->sprite(DOOR);
	data[6] = (canva())->sprite(WINDOW);
	data[7] = (canva())->sprite(HAY);
	data[8] = (canva())->sprite(CAVE);
	data[9] = (canva())->sprite(CAVE); // MUDA ESTE PARA A IMAGEM DA RELVA
	if (!data[2] || !data[1] || !data[2] || !data[3])
		return (1);
	if (!data[4] || !data[5] || !data[6] || !data[7])
		return (1);
	if (!data[8] || !data[9])
		return (1);
	return (0);
}

int	ft_objects_len(t_object *sprites)
{
	int	i;

	i = 0;
	while (sprites)
	{
		sprites = sprites->next;
		i++;
	}
	return (i);
}

void	ft_choose_spr_size(t_spr *sprite, t_object *obj)
{
	sprite->udiv = obj->dimension[X];
	sprite->vdiv = obj->dimension[Y];
	sprite->vmove = obj->dimension[2];
}

t_spr	*ft_setup_sprites(t_object *objs)
{
	t_spr	*sprites;
	int		len;
	int		i;

	len = ft_objects_len(objs);
	if (!len)
		return (NULL);
	sprites = malloc(sizeof(t_spr) * (len + 1));
	if (!sprites)
		return (NULL);
	i = -1;
	while (++i < len && objs)
	{
		while (objs && !objs->sprite)
		{
			i--;
			len--;
			objs = objs->next;
		}
		if (!objs)
			break ;
		sprites[i].texture = objs->sprite;
		sprites[i].x = objs->pos[0] + 0.5;
		sprites[i].y = objs->pos[1] + 0.5;
		ft_choose_spr_size(&sprites[i], objs);
		objs = objs->next;
	}
	i = -1;
	while (++i < len)
		sprites[i].len = len;
	return (sprites);
}
