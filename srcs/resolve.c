/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:46:05 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/09 14:42:11 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolve.h"
#include "list.h"
#include "operation.h"
#include <stdlib.h>

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

int is_resolve(data_t *instance)
{

    if (instance->nb_enter <= 1)
        return (1);
    return (is_sort(instance));
}

void radix_resolve(data_t *instance)
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

#include <stdio.h>
int median(data_t *instance, int n)
{
    list_t *tmp;
    list_t *med;
    int dist;
    int i;

    tmp = instance->stack_a;
    med = tmp;
    if (med->id >= n / 2)
        dist = med->id - n / 2;
    else
        dist = n / 2 - med->id;
    i = 0;
    while (tmp && i < n)
    {
        i++;
        if ((tmp->id <= n / 2 &&
             n / 2 - tmp->id < dist) ||
            (tmp->id >= n / 2 &&
             tmp->id - n / 2 < dist))
        {
            med = tmp;
            if (med->id >= n / 2)
                dist = med->id - n / 2;
            else
                dist = n / 2 - med->id;
        }
        tmp = tmp->next;
    }
    return (med->value);
}

void quick_sort(data_t *instance, int n)
{
    int med;
    int i;
    int half_len;

    if (n <= 1)
        return;
    med = median(instance, n);
    i = 0;
    half_len = 0;
    while (i < n)
    {
        printf("%d\n", instance->stack_a->value);
        if (instance->stack_a->value >= med)
        {
            pb(instance);
            half_len++;
        }
        else
            ra(instance);
        i++;
    }
    printf("MED=%d, N=%d, H=%d\n", med, n, half_len);
    i = 0;
    while (i++ < n - half_len)
        rra(instance);
    i = 0;
    while (i++ < half_len)
        pa(instance);
    quick_sort(instance, half_len);
    i = 0;
    while (i++ < half_len)
        ra(instance);
    quick_sort(instance, n - half_len);
    i = 0;
    while (i++ < half_len)
        rra(instance);
}

void start_resolve(data_t *instance)
{
    if (is_resolve(instance))
        return;
    if (instance->nb_enter <= 5)
        return (resolve_less_than_5(instance));
    // radix_resolve(instance);
    quick_sort(instance, instance->nb_enter);
}