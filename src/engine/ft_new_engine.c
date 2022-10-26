/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:36:41 by rteles            #+#    #+#             */
/*   Updated: 2022/10/26 14:46:24 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
/*
int	start(t_map *map)
{
	new_engine(map);
	if (!engine().ptr)
		return (1);
	//path_images(all);
	//verification_map(all, 0, 0, all->game);
	//put_menu(all);
	//mlx_key_hook(all->win, key_hook_mode1, all);
	//mlx_hook(all->win, 17, 0, end_game, all);
	//mlx_loop_hook(all->ptr, put_images, all);
	mlx_loop(engine().ptr);
	return (0);
}
*/
 36  
src/engine/ft_new_engine.c
@@ -0,0 +1,36 @@
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:49:41 by rteles            #+#    #+#             */
/*   Updated: 2022/10/25 11:31:03 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <mlx.h>
void	new_engine(void)
{
	engine().ptr = mlx_init();
	
	if (!engine().ptr)
		return ;
	(engine()).win = 0;//mlx_new_window(engine().ptr, 1920, 1080, "WOLF EAT PIG'S");
	(engine()).game = NULL;
	(engine()).max_x = NULL;
	(engine()).max_y = NULL;
	(engine()).check_point[0] = NULL;
	(engine()).check_point[1] = NULL;
}

t_engine	engine(void)
{
	static t_engine	e;
	return (e);
}
