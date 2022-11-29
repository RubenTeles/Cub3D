/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:02:42 by rteles            #+#    #+#             */
/*   Updated: 2022/11/29 15:43:34 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_engine.h>
#include <ft_sprites.h>
#include <ft_scenes_images.h>

void	ft_enemies_move(void)
{
	t_object	*aux;

	aux = (engine())->enemies;
	while (aux)
	{
		if (aux->move)
			aux->is_move(aux, 0);
		aux = aux->next;
	}
}
