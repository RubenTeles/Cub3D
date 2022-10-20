/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:53:34 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/30 20:15:59 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_UTIL_H
# define FT_STR_UTIL_H

# include <stdlib.h>
# include <stdio.h>

int		ft_len(const char *s);
char	*ft_copy(const char *str);
char	*ft_copy_n(const char *str, int n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_contains(const char *str, const char *hey);
int		ft_compare(const char *str1, const char *str2);
int		ft_compare_n(const char *str1, const char *str2, int n);
int		ft_is_space(char c);
char	*ft_join(const char *str1, const char *str2);
char	*ft_replace(const char *str1, const char *str2, const char *hey);
char	**ft_split(const char *str, char *div);
char	*ft_trim(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_iter(const char *str, char (*f)(char c));
char	*split_two_str(char *str, char c, int option);
char	*ft_string_in_two_char(char *str, char c1, char c2);
char	*replace_str(char *str1, char *str2);
int		index_char(char *str, char c);
int		ft_atoi(char *str);
char	*ft_itoa(int n);
int		ft_isalnum(char *str);
char	*ft_strchr(const char *string, int c);
char	*ft_strrchr(const char *string, int c);
int	    ft_str_s_str(char *s1, char *s2);

#endif