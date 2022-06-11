/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:46:05 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/11 19:50:15 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolve.h"
#include "list.h"
#include "operation.h"
#include <stdlib.h>

int is_resolve(data_t *instance)
{

    if (instance->nb_enter <= 1)
        return (1);
    return (is_sort(instance));
}

int	find_rchunk(list_t *lst, int min, int max, int *ret)
{
	int	nb;

	if (!lst)
		return (0);
	nb = find_rchunk(lst->next, min, max, ret);
	if (*ret)
		return (nb);
	if (lst->value >= min && lst->value < max)
		*ret = 1;
	return (nb + 1);
}

int find_chunk(list_t *lst, int min, int max)
{
	int nb;
	int nb2;
	int ret;

	ret = 0;
	nb2 = find_rchunk(lst, min, max, &ret);
	nb = 0;
	while (lst)
	{
		if (lst->value >= min && lst->value < max)
			break;
		nb++;
		lst = lst->next;
	}
	if (nb < nb2)
		return (nb);
	else
		return (-nb2);
}

void insert_sort(data_t *instance)
{
	int	size_chunk;
	int	size;

	size_chunk = instance->nb_enter / 5;
	size = instance->nb_enter;
	while (instance->stack_a)
	{
		if (size == 1)
			break;
		push_pos(instance, find_chunk(instance->stack_a, ));
		size--;
	}
	while (instance->stack_b)
		pa(instance);
}

void start_resolve(data_t *instance)
{
    if (is_resolve(instance))
        return;
    if (instance->nb_enter <= 5)
        return (resolve_less_than_5(instance));
    if (instance->nb_enter <= 64)
		return radix_resolve(instance);
	if (instance->nb_enter < 500)
		return insert_sort(instance);
	insert_sort500(instance);
}
