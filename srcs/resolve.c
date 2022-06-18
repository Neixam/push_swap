/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:46:05 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/18 17:20:35 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolve.h"
#include "list.h"
#include "operation.h"
#include "utils.h"
#include <stdlib.h>

int is_resolve(data_t *instance)
{
    if (instance->nb_enter <= 1)
        return (1);
    return (is_sort(instance, A, ascending, instance->nb_enter));
}

int find_rchunk(list_t *lst, int min, int max, int *ret)
{
    int nb;

    if (!lst)
        return (0);
    nb = find_rchunk(lst->next, min, max, ret);
    if (*ret)
        return (nb);
    if (lst->id >= min && lst->id < max)
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
        if (lst->id >= min && lst->id < max)
            break;
        nb++;
        lst = lst->next;
    }
    if (nb < nb2)
        return (nb);
    else
        return (-nb2);
}

int find_appro(list_t *lst, int val)
{
    int pos;
    int valpos;
    int i;

    i = 0;
    pos = i;
    valpos = lst->value;
    while (lst)
    {
        if (ft_abs(lst->value - val) < ft_abs(valpos - val))
        {
            pos = i;
            valpos = lst->value;
        }
        i++;
        lst = lst->next;
    }
    if (valpos > val)
        pos++;
    return (pos);
}

void setup_b(data_t *instance, int pushs)
{
    int min;
    int max;
    int pos;

    if (pushs < 2)
        return (pb(instance));
    ft_lstmm(instance->stack_b, &min, &max);
    if (instance->stack_a->value < min)
        pos = find_value(instance->stack_b, min) + 1;
    else if (instance->stack_a->value > max)
        pos = find_value(instance->stack_b, max);
    else
        pos = find_appro(instance->stack_b, instance->stack_a->value);
    if (pos >= pushs / 2)
        pos -= pushs;
    go_to(instance, pos, B);
    pb(instance);
}

void insert_sort(data_t *instance, int part)
{
    int size_chunk;
    int pushs;
    int num_chunk;

    size_chunk = instance->nb_enter / part;
    num_chunk = 0;
    pushs = 0;
    while (instance->stack_a)
    {
        go_to(instance, find_chunk(instance->stack_a, size_chunk * num_chunk, size_chunk * (num_chunk + 1)), A);
        setup_b(instance, pushs);
        pushs++;
        if (pushs % size_chunk == 0)
            num_chunk++;
    }
    go_to(instance, find_value(instance->stack_b, instance->max), B);
    while (instance->stack_b)
        pa(instance);
}

void start_resolve(data_t *instance)
{
    if (is_resolve(instance))
        return;
    if (instance->nb_enter <= 5)
	{
        return (resolve_less_than_5(instance));
	}
	if (instance->nb_enter <= 100)
    	insert_sort(instance, 6);
	else
    	quick_sort_a(instance, instance->nb_enter);
    opti_instr(&instance->st_instr);
    print_instr(instance->st_instr);
}
