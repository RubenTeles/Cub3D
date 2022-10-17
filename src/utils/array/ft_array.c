/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:54:04 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/30 20:19:08 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>
#include <ft_arr_util.h>

t_array	array(void)
{
	static t_array	array_of_strings = {
		ft_arrlen, ft_free_arr, ft_create_arr,
		ft_add_arr, ft_rmv_arr, ft_copy_arr, ft_copy_n_arr,
		ft_arr_iter, ft_arr_set
	};

	return (array_of_strings);
}
