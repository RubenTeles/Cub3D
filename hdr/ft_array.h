/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:53:09 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/30 20:13:37 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include <stdarg.h>

typedef struct ft_array
{
	int		(*len)(char **arr);
	char	**(*free)(char **arr);
	char	**(*create)(int len, ...);
	char	**(*add)(char **arr, char *str);
	char	**(*rmv)(char **arr, int index);
	char	**(*cpy)(char **arr);
	char	**(*cpy_n)(char **arr, int len);
	char	**(*iter)(char **arr, char *(*f)(const char *str));
	char	**(*set)(char **arr, char *str, int index);
}			t_array;

t_array	array(void);

#endif
