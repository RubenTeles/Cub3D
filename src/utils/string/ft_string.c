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

/*
len: //TODO

copy:
copia uma string (é preciso dar free);

copy_n:
Copia a string SRC para a string DEST num determinado numero de caracteres

strnstr: //TODO

contains: //TODO

compare:
Compara 2 strings. Retorna 1 se for verdadeiro ou 0 se nao.

compare_n:
Compara 2 strings, com n casas. Retorna 1 se for verdadeiro ou 0 se nao.

is_spc: //TODO


is_alfanumeric:
verifica se a string contem apenas caracteres alfa numericos 
retorna 1 se sim, ou 0 se nao.

only_this_chars:
Procura se a string tem apenas estes caracteres,
Retorna 1 se tiver alem destes.

join: //TODO


replace:
Muda o valor da str1 para o str2.

split: //TODO

sub_split_option:
Nova string, divida por um caracter. Se a opção for 0 é do inicio ate ao c,
se for 1 é do c ate '\0'.
Retorna Null se der erro.

atoi:
converte str de numeros em int.

itoa:
converte int em str.

trim: //TODO

sub_str:
Substring, uma nova string que começa apartir de x casa com x len.

sub_str_chars:
Substring, um nova string que começa apartir de c1, ate c2.

iter: //TODO


pos_char:
Retorna a primeira posição do char procurado.

pos_char_last:
Retorna a ultima posição do char procurado.

index_char:
retorna o index do char na string, ou -1 se nao tiver.
*/
t_string	string(void)
{
	static t_string	string = {
		ft_len, ft_copy, ft_copy_n, ft_strnstr, ft_contains,
		ft_compare, ft_compare_n, ft_is_space, ft_isalnum, ft_str_s_str,
		ft_join, replace_str, ft_replace, ft_split, split_two_str, ft_atoi,
		ft_itoa, ft_trim, ft_substr, ft_string_in_two_char, ft_iter, ft_strchr,
		ft_strrchr,	index_char
	};

	return (string);
}
