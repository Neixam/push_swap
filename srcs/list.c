/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:41:00 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 14:13:22 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

t_list	*ft_new_cell(int value)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->value = value;
	ret->id = 0;
	ret->next = NULL;
	return (ret);
}

int	ft_add_back(t_list **lst, int value)
{
	t_list	*head;

	if (!lst)
		return (1);
	if (!*lst)
	{
		*lst = ft_new_cell(value);
		if (!*lst)
			return (1);
		return (0);
	}
	head = *lst;
	while (head->next)
		head = head->next;
	head->next = ft_new_cell(value);
	if (!head->next)
		return (1);
	return (0);
}

int	ft_add_head(t_list **lst, int value)
{
	t_list	*head;

	if (!lst)
		return (1);
	head = ft_new_cell(value);
	if (!head)
		return (1);
	head->next = *lst;
	*lst = head;
	return (0);
}

void	ft_destroy_lst(t_list **lst)
{
	if (!lst || !*lst)
		return ;
	ft_destroy_lst(&(*lst)->next);
	free(*lst);
	*lst = NULL;
}
