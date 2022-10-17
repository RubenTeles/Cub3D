/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:52:36 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/30 20:13:00 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARR_UTIL_H
# define FT_ARR_UTIL_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_arrlen(char **arr);
char	**ft_free_arr(char **arr);
char	**ft_create_arr(int len, ...);
char	**ft_add_arr(char **arr, char *str);
char	**ft_rmv_arr(char **arr, int index);
char	**ft_copy_arr(char **arr);
char	**ft_copy_n_arr(char **arr, int len);
char	**ft_arr_iter(char **arr, char *(*f)(const char *str));
char	**ft_arr_set(char **arr, char *str, int index);

#endif
