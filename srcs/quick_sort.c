/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:39:41 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/18 09:19:59 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolve.h"
#include "operation.h"

#include <stdio.h>
void print_list(list_t *l)
{
    for (; l; l = l->next)
        fprintf(stderr, "%d:%d%s", l->id, l->value, (l->next) ? ", " : "\n");
}

void printlet(data_t instance)
{
    fprintf(stderr, "STACK A:\n");
    print_list(instance.stack_a);
    fprintf(stderr, "STACK B:\n");
    print_list(instance.stack_b);
    fprintf(stderr, "MAX=%d, MIN=%d, SIZE=%d\n", instance.max, instance.min, instance.nb_enter);
}

void opti_balance(data_t *instance, int rot, int aob, int len)
{
    if (rot >= len / 2)
        rot -= len;
    while (rot)
    {
        if (rot > 0)
        {
            if (aob == A)
                rra(instance);
            else
                rrb(instance);
            rot--;
        }
        else
        {
            if (aob == A)
                ra(instance);
            else
                rb(instance);
            rot++;
        }
    }
}

void sort_less_than_3(data_t *instance, int len)
{
    if (len == 1)
        return;
    if (len == 3 && ft_lstsize(instance->stack_a) == 3)
        return (resolve_less_than_3(instance));
    if (len == 2)
        return (sa(instance));
    if (instance->stack_a->value > instance->stack_a->next->value)
    { // 2 1 3 || 3 2 1 || 3 1 2
        if (instance->stack_a->next->value > instance->stack_a->next->next->value)
        { // 3 2 1
            sa(instance);
            pb(instance);
            sa(instance);
            pa(instance);
            sa(instance);
        }
        else if (instance->stack_a->value > instance->stack_a->next->next->value)
        { // 3 1 2
            sa(instance);
            pb(instance);
            sa(instance);
            pa(instance);
        }
        else
        { // 2 1 3
            sa(instance);
        }
    }
    else
    { // 1 3 2 || 2 3 1
        if (instance->stack_a->value < instance->stack_a->next->next->value)
        { // 1 3 2
            pb(instance);
            sa(instance);
            pa(instance);
        }
        else
        { // 2 3 1
            pb(instance);
            sa(instance);
            pa(instance);
            sa(instance);
        }
    }
}

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
    { // 1 2 3 || 1 3 2 || 2 3 1
        if (instance->stack_b->next->value < instance->stack_b->next->next->value)
        { // 1 2 3
            rb(instance);
            sb(instance);
            pa(instance);
            pa(instance);
            rrb(instance);
            pa(instance);
        }
        else if (instance->stack_b->value > instance->stack_b->next->next->value)
        { // 2 3 1
            sb(instance);
            pa(instance);
            pa(instance);
            pa(instance);
        }
        else
        { // 1 3 2
            rb(instance);
            pa(instance);
            pa(instance);
            rrb(instance);
            pa(instance);
        }
    }
    else
    { // 3 1 2 || 2 1 3
        if (instance->stack_b->value < instance->stack_b->next->next->value)
        { // 2 1 3
            pa(instance);
            sb(instance);
            pa(instance);
            sa(instance);
            pa(instance);
        }
        else
        { // 3 1 2
            pa(instance);
            sb(instance);
            pa(instance);
            pa(instance);
        }
    }
}

void refresh_med(list_t *lst, int len)
{
    list_t *tmp;
    list_t *head;
    int i;
    int j;

    head = lst;
    i = 0;
    while (lst && i < len)
    {
        lst->id = 0;
        tmp = head;
        j = 0;
        while (tmp && j < len)
        {
            if (lst->value > tmp->value)
                lst->id++;
            tmp = tmp->next;
            j++;
        }
        lst = lst->next;
        i++;
    }
}

void quick_sort_b(data_t *instance, int len)
{
    int i;
    int rot;

    if (is_sort(instance, B, descending, len))
    {
        while (len--)
            pa(instance);
        return;
    }
    if (len <= 3)
        return (push_less_than_3(instance, len));
    refresh_med(instance->stack_b, len);
    i = 0;
    rot = 0;
    while (i++ < len)
    {
        if (instance->stack_b->id >= len / 2)
            pa(instance);
        else if (++rot)
            rb(instance);
    }
    if (ft_lstsize(instance->stack_b) != len / 2)
        opti_balance(instance, rot, B, ft_lstsize(instance->stack_b));
    quick_sort_a(instance, len / 2 + len % 2);
    quick_sort_b(instance, len / 2);
}

void quick_sort_a(data_t *instance, int len)
{
    int i;
    int rot;

    if (is_sort(instance, A, ascending, len))
        return;
    if (len <= 3)
        return (sort_less_than_3(instance, len));
    if (len != instance->nb_enter)
        refresh_med(instance->stack_a, len);
    i = 0;
    rot = 0;
    while (i++ < len)
    {
        if (instance->stack_a->id < len / 2)
            pb(instance);
        else if (++rot)
            ra(instance);
    }
    if (ft_lstsize(instance->stack_a) != len / 2 + len % 2)
        opti_balance(instance, rot, A, ft_lstsize(instance->stack_a));
    quick_sort_a(instance, len / 2 + len % 2);
    quick_sort_b(instance, len / 2);
}
