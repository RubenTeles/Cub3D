/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:54:44 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/30 20:25:06 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst_util.h>

t_list	*ft_lst_iter(t_list *lst, void *ptr, int check)
{
	t_list	*mem;
	void	*temp;
	void	*(*f)(void *lst);

	if (!lst)
		return (lst);
	f = ptr;
	mem = lst;
	while (mem)
	{
		temp = mem->content;
		mem->content = f(mem->content);
		if (check)
			free(temp);
		mem = mem->next;
	}
	return (lst);
}

t_list	*ft_lst_set(t_list *lst, void *content, int index)
{
	t_list	*mem;
	int		i;

	if (!lst || !content || !ft_lst_len(lst))
		return (lst);
	if (index < 0 || index >= ft_lst_len(lst))
		return (lst);
	mem = lst;
	i = 0;
	while (mem)
	{
		if (i == index)
		{
			free(mem->content);
			mem->content = content;
		}
		i++;
		mem = mem->next;
	}
	return (lst);
}

t_list	*ft_lst_rmv(t_list *lst, int index)
{
	t_list	*mem;

	if (!lst || index < 0 || index >= ft_lst_len(lst))
		return (lst);
	if (!index)
	{
		mem = lst->next;
		free(lst->content);
		free(lst);
		return (mem);
	}
	lst->next = ft_lst_rmv(lst->next, --index);
	return (lst);
}

t_list	*ft_lst_swap(t_list *lst, int i, int j)
{
	void	*mem;
	t_list	*temp;
	int		index;

	if (ft_lst_len(lst) < 2 || i >= ft_lst_len(lst))
		return (lst);
	if (j >= ft_lst_len(lst) || i == j || i < 0 || j < 0)
		return (lst);
	mem = ft_lst_get(lst, i);
	temp = lst;
	index = -1;
	while (++index < i)
		temp = temp->next;
	temp->content = ft_lst_get(lst, j);
	temp = lst;
	index = -1;
	while (++index < j)
		temp = temp->next;
	temp->content = mem;
	return (lst);
}
