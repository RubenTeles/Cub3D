/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:54:54 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/30 20:25:26 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_str_util.h>

t_string	string(void)
{
	static t_string	string = {
		ft_len, ft_copy, ft_copy_n, ft_strnstr, ft_contains,
		ft_compare, ft_compare_n, ft_is_space, ft_join,
		ft_replace, ft_split, ft_atoi, ft_trim, ft_substr,
		ft_iter
	};

	return (string);
}
