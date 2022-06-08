/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:36:13 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/09 00:28:41 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include <unistd.h>

void sa(data_t *instance)
{
    int tmp;

    if (!instance->stack_a || !instance->stack_a->next)
        return;
    tmp = instance->stack_a->value;
    instance->stack_a->value = instance->stack_a->next->value;
    instance->stack_a->next->value = tmp;
    write(1, "sa\n", 3);
}

void sb(data_t *instance)
{
    int tmp;

    if (!instance->stack_b || !instance->stack_b->next)
        return;
    tmp = instance->stack_b->value;
    instance->stack_b->value = instance->stack_b->next->value;
    instance->stack_b->next->value = tmp;
    write(1, "sb\n", 3);
}

void ss(data_t *instance)
{
    int tmp;

    if ((!instance->stack_a || !instance->stack_a->next) &&
        (!instance->stack_b || !instance->stack_b->next))
        return;
    tmp = instance->stack_a->value;
    instance->stack_a->value = instance->stack_a->next->value;
    instance->stack_a->next->value = tmp;
    tmp = instance->stack_b->value;
    instance->stack_b->value = instance->stack_b->next->value;
    instance->stack_b->next->value = tmp;
    write(1, "ss\n", 3);
}