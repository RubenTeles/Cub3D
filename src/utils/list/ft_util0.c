/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:54:37 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/30 20:23:07 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst_util.h>

int	ft_lst_len(t_list *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 1;
	while (lst->next)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	*ft_lst_get(t_list *lst, int index)
{
	int	i;

	if (!lst || index < 0 || ft_lst_len(lst) <= index)
		return (NULL);
	i = 0;
	while (lst->next && i++ < index)
		lst = lst->next;
	return (lst->content);
}

t_list	*ft_new_lst(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_lst_add(t_list *lst, void *content)
{
	t_list	*new;
	t_list	*mem;

	new = ft_new_lst(content);
	if (!lst)
		return (new);
	mem = lst;
	while (mem->next)
		mem = mem->next;
	mem->next = new;
	return (lst);
}

t_list	*ft_lst_free(t_list *lst)
{
	t_list	*mem;

	while (lst)
	{
		free(lst->content);
		mem = lst->next;
		free(lst);
		lst = mem;
	}
	return (NULL);
}
