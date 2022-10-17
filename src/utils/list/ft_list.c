/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:54:29 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/30 20:21:53 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>
#include <ft_lst_util.h>

t_list_utils	list(void)
{
	static t_list_utils	linked_list = {
		ft_lst_len, ft_lst_get, ft_new_lst, ft_lst_add,
		ft_lst_free, ft_lst_iter, ft_lst_set, ft_lst_rmv,
		ft_lst_swap
	};

	return (linked_list);
}
