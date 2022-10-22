/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:54:54 by amaria-m          #+#    #+#             */
/*   Updated: 2022/10/22 19:41:42 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_str_util.h>

/*
len:
retorna o comprimento de s

copy:
copia uma string (é preciso dar free);

copy_n:
Copia a string SRC para a string DEST num determinado numero de caracteres

strnstr: 
retorna um ponteiro que aponta para a string "needle" dentro da string "haystack"
so procura até o index especificado por len

contains:
retorna 0 se a string hey não se encontrar na str
retorna (index + 1) se a string hey existir dentro de str
index -> localização de hey na str

compare:
Compara 2 strings. Retorna 1 se for verdadeiro ou 0 se nao.

compare_n:
Compara 2 strings, com n casas. Retorna 1 se for verdadeiro ou 0 se nao.

is_spc: 
retorna 1 se 'c' for um dos seguintes caracteres:
'\t' , '\n' , '\v' , '\r' , ' '


is_alfanumeric:
verifica se a string contem apenas caracteres alfa numericos 
retorna 1 se sim, ou 0 se nao.

only_this_chars:
Procura se a string tem apenas estes caracteres,
Retorna 1 se tiver alem destes.

join:
retorna uma nova string que é a junção de str1 e str2
não faz free de nenhuma string


replace:
Muda o valor da str1 para o str2.

split:
divide a string str em várias, tendo em conta o separador div (que pode ter qualquer tamanho)
retorna uma array de strings

sub_split_option:
Nova string, divida por um caracter. Se a opção for 0 é do inicio ate ao c,
se for 1 é do c ate '\0'.
Retorna Null se der erro.

atoi:
converte str de numeros em int.

itoa:
converte int em str.

trim:
retorna uma string igual a 'str' mas sem os espaços em branco, 
que se possam encontrar no inicio e fim de 'str'
os espaços em branco correspondem aos seguintes caracteres:
'\t' , '\n' , '\v' , '\r' , ' '

sub_str:
Substring, uma nova string que começa apartir de x casa com x len.

sub_str_chars:
Substring, um nova string que começa apartir de c1, ate c2.

iter:
retorna uma nova string que é igual á string dada,
mas com a função f aplicada a cada carater de str
do seguinte modo:
sendo mem a nova string,
mem[i] = f(str[i]);

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
