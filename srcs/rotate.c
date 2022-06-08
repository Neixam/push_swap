/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:38:04 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/09 00:42:03 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include <unistd.h>

void ra(data_t *instance)
{
    list_t *tmp;
    list_t *tmp2;

    tmp = instance->stack_a;
    while (tmp && tmp->next)
        tmp = tmp->next;
    tmp2 = instance->stack_a;
    tmp->next = instance->stack_a;
    instance->stack_a = instance->stack_a->next;
    tmp2->next = 0;
    write(1, "ra\n", 3);
}

void rb(data_t *instance)
{
    list_t *tmp;
    list_t *tmp2;

    tmp = instance->stack_b;
    while (tmp && tmp->next)
        tmp = tmp->next;
    tmp2 = instance->stack_b;
    tmp->next = instance->stack_b;
    instance->stack_b = instance->stack_b->next;
    tmp2->next = 0;
    write(1, "rb\n", 3);
}

void rr(data_t *instance)
{
    list_t *tmp;
    list_t *tmp2;

    tmp = instance->stack_b;
    while (tmp && tmp->next)
        tmp = tmp->next;
    tmp2 = instance->stack_b;
    tmp->next = instance->stack_b;
    instance->stack_b = instance->stack_b->next;
    tmp2->next = 0;
    tmp = instance->stack_a;
    while (tmp && tmp->next)
        tmp = tmp->next;
    tmp2 = instance->stack_a;
    tmp->next = instance->stack_a;
    instance->stack_a = instance->stack_a->next;
    tmp2->next = 0;
    write(1, "rr\n", 3);
}