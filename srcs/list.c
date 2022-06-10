/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:41:00 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/10 16:05:22 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	ft_lstmxmn(list_t *lst, int *max, int *min)
{
	*max = lst->value;
	*min = lst->value;
    while (lst)
    {
		if (lst->value > *max)
			*max = lst->value;
		if (lst->value < *min)
			*min = lst->value;
        lst = lst->next;
    }
}

list_t	*ft_new_cell(int value)
{
    list_t *ret;

    ret = (list_t *)malloc(sizeof(list_t));
    if (!ret)
        return (NULL);
    ret->value = value;
    ret->id = 0;
    ret->next = NULL;
    return (ret);
}

int ft_add_back(list_t **lst, int value)
{
    list_t *head;

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

int ft_add_head(list_t **lst, int value)
{
    list_t *head;

    if (!lst)
        return (1);
    head = ft_new_cell(value);
    if (!head)
        return (1);
    head->next = *lst;
    *lst = head;
    return (0);
}

void ft_destroy_lst(list_t **lst)
{
    if (!lst || !*lst)
        return;
    ft_destroy_lst(&(*lst)->next);
    free(*lst);
    *lst = NULL;
}
