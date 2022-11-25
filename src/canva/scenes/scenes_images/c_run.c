/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_run.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:18:19 by rteles            #+#    #+#             */
/*   Updated: 2022/11/23 23:22:01 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>

void	ft_run(t_scene_img *scene)
{
	t_data	*data;

	(void)scene;
	data = (canva())->sprite(RUN);
	(canva())->resize(data, (canva())->data->larg, (canva())->data->alt, 0, 0);
}
