/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:13:00 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/13 18:24:37 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolve.h"
#include "operation.h"

int is_sort(data_t *instance)
{
    list_t *tmp;

    tmp = instance->stack_a;
    while (tmp && tmp->next)
    {
        if (tmp->value > tmp->next->value)
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

void radix_sort(data_t *instance)
{
    int decal;
    int i;

    decal = 0;
    while (((instance->nb_enter - 1) >> decal) > 0 && !is_sort(instance))
    {
        i = 0;
        while (i++ < instance->nb_enter && instance->stack_a)
        {
            if ((instance->stack_a->id >> decal) & 1)
                ra(instance);
            else
                pb(instance);
        }
        while (instance->stack_b)
            pa(instance);
        decal++;
    }
}
