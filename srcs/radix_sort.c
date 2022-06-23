/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:13:00 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/23 20:33:29 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolve.h"
#include "operation.h"

void push_less_than_3(data_t *instance, int len)
{
    if (len == 1)
        return (pa(instance));
    if (len == 2)
    {
        if (instance->stack_b->value < instance->stack_b->next->value)
            sb(instance);
        pa(instance);
        return (pa(instance));
    }
    if (instance->stack_b->value < instance->stack_b->next->value)
    {
        if (instance->stack_b->next->value < instance->stack_b->next->next->value)
        {
            rb(instance);
            sb(instance);
            pa(instance);
            pa(instance);
            rrb(instance);
            pa(instance);
        }
        else if (instance->stack_b->value > instance->stack_b->next->next->value)
        {
            sb(instance);
            pa(instance);
            pa(instance);
            pa(instance);
        }
        else
        {
            rb(instance);
            pa(instance);
            pa(instance);
            rrb(instance);
            pa(instance);
        }
    }
    else
    {
        if (instance->stack_b->value < instance->stack_b->next->next->value)
        {
            pa(instance);
            sb(instance);
            pa(instance);
            sa(instance);
            pa(instance);
        }
        else
        {
            pa(instance);
            sb(instance);
            pa(instance);
            pa(instance);
        }
    }
}

int is_sort(data_t *instance, int aob, int (*cmp)(list_t *, list_t *), int len)
{
    list_t *tmp;

    if (aob == A)
        tmp = instance->stack_a;
    else
        tmp = instance->stack_b;
    while (tmp && tmp->next && --len > 0)
    {
        if (!cmp(tmp, tmp->next))
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void go_to(data_t *instance, int pos, int aob)
{
    while (pos != 0)
    {
        if (pos > 0)
        {
            if (aob == A)
                ra(instance);
            else
                rb(instance);
            pos--;
        }
        else
        {
            if (aob == A)
                rra(instance);
            else
                rrb(instance);
            pos++;
        }
    }
}