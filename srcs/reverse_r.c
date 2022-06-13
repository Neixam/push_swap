/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:38:50 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/13 20:10:52 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include <unistd.h>

void rra(data_t *instance)
{
    list_t *tmp;
    list_t *ant;

    tmp = instance->stack_a;
    if (!tmp || !tmp->next)
        return;
    while (tmp && tmp->next)
        tmp = tmp->next;
    ant = instance->stack_a;
    while (ant && ant->next != tmp)
        ant = ant->next;
    tmp->next = instance->stack_a;
    instance->stack_a = tmp;
    ant->next = 0;
    write(1, "rra\n", 4);
}

void rrb(data_t *instance)
{
    list_t *tmp;
    list_t *ant;

    tmp = instance->stack_b;
    if (!tmp || !tmp->next)
        return;
    while (tmp && tmp->next)
        tmp = tmp->next;
    ant = instance->stack_b;
    while (ant && ant->next != tmp)
        ant = ant->next;
    tmp->next = instance->stack_b;
    instance->stack_b = tmp;
    ant->next = 0;
    write(1, "rrb\n", 4);
}

void rrr(data_t *instance)
{
    list_t *tmp;
    list_t *ant;

    tmp = instance->stack_b;
    while (tmp && tmp->next)
        tmp = tmp->next;
    ant = instance->stack_b;
    while (ant && ant->next != tmp)
        ant = ant->next;
    tmp->next = instance->stack_b;
    instance->stack_b = tmp;
    ant->next = 0;
    tmp = instance->stack_a;
    while (tmp && tmp->next)
        tmp = tmp->next;
    ant = instance->stack_a;
    while (ant && ant->next != tmp)
        ant = ant->next;
    tmp->next = instance->stack_a;
    instance->stack_a = tmp;
    ant->next = 0;
    write(1, "rrr\n", 4);
}