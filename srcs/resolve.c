/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:46:05 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/09 18:22:58 by ambouren         ###   ########.fr       */
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
		tmp->id = 0;
        tmp = tmp->next;
    }
    return (med->value);
}

void reload_med(data_t *instance, int val)
{
	list_t *tmp;
	int id;

	id = 0;
	tmp = instance->stack_b;
	while (tmp)
	{
		if (tmp->value > val)
			tmp->id++;
		else
			id++;
		tmp = tmp->next;
	}
	pb(instance);
	instance->stack_b->id = id;
}

void quick_sort(data_t *instance, int n)
{
    int i;
	int med;
    int half_len;

    if (n <= 1)
        return;
    i = 0;
    half_len = 0;
	med = median(instance, n);
    while (i < n)
    {
        if (instance->stack_a->value <= med)
        {
			reload_med(instance, instance->stack_a->value);
            half_len++;
        }
        else
            ra(instance);
        i++;
    }
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
