/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:53:41 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/21 19:02:49 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>

typedef struct s_string
{
	int		(*len)(const char *str);
	char	*(*cpy)(const char *str);
	char	*(*cpy_n)(const char *str, int n);
	char	*(*strnstr)(const char *haystack, const char *needle, size_t len);
	int		(*contains)(const char *str, const char *hey);
	int		(*cmp)(const char *str1, const char *str2);
	int		(*cmp_n)(const char *str, const char *hey, int n);
	int		(*is_spc)(char c);
	int		(*is_alfanumeric)(char *str);
	int		(*only_this_chars)(char *s1, char *s2);
	char	*(*join)(const char *str1, const char *str2);
	char	*(*replace)(char *str1, char *str2);
	char	*(*replace_in_str)(const char *str1, const char *str2, \
	const char *hey);
	char	**(*split)(char const *s, char *div);
	char	*(*sub_split_option)(char *str, char c, int option);
	int		(*atoi)(char *str);
	char	*(*itoa)(int n);
	char	*(*trim)(const char *str);
	char	*(*substr)(char const *s, unsigned int start, size_t len);
	char	*(*sub_str_chars)(char *str, char c1, char c2);	
	char	*(*iter)(const char *str, char (*f)(char c));
	char	*(*pos_char)(const char *string, int c);
	char	*(*pos_char_last)(const char *string, int c);
	int		(*index_char)(char *str, char c);
}			t_string;

t_string	string(void);

#endif
