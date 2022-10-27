/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:40:13 by rteles            #+#    #+#             */
/*   Updated: 2022/10/26 20:56:47 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>

int	key_hook_mode2(int keycode, void *a)
{
	(void)a;
	if (keycode == 53 || keycode == 65307)
		return (end_game());
	/*else if (keycode == 13 || keycode == 119)
		i = ft_method_mode2(all, all->t.pos_x, all->t.pos_y - 1, 'W');
	else if (keycode == 0 || keycode == 97)
		i = ft_method_mode2(all, all->t.pos_x - 1, all->t.pos_y, 'A');
	else if (keycode == 1 || keycode == 115)
		i = ft_method_mode2(all, all->t.pos_x, all->t.pos_y + 1, 'S');
	else if (keycode == 2 || keycode == 100)
		i = ft_method_mode2(all, all->t.pos_x + 1, all->t.pos_y, 'D');
	else
		i = 0;
	path_mode1(all, &all->t);
	animation_player(all, all->t.pos_x, all->t.pos_y, 0);
	put_menu(all);*/
	return (0);
}

int	key_hook_mode1(int keycode, void *a)
{
	(void)a;
	/*int	i;

	if (all->t.mode == 2)
		i = key_hook_mode2(keycode, all);
	else */
	if (keycode == 53 || keycode == 65307)
		return (end_game());
	/*else if (keycode == 13 || keycode == 119)
		i = ft_method(all, all->t.pos_x, all->t.pos_y - 1, 'W');
	else if (keycode == 0 || keycode == 97)
		i = ft_method(all, all->t.pos_x - 1, all->t.pos_y, 'A');
	else if (keycode == 1 || keycode == 115)
		i = ft_method(all, all->t.pos_x, all->t.pos_y + 1, 'S');
	else if (keycode == 2 || keycode == 100)
		i = ft_method(all, all->t.pos_x + 1, all->t.pos_y, 'D');
	else if (keycode == 46 || keycode == 109)
	{
		path_mode2(all, &all->t);
		i = animation_player(all, all->t.pos_x, all->t.pos_y, 0);
	}
	else
		return (0);
	all->m.paws += i;
	put_menu(all);
	return (i);*/
	return (0);
}
