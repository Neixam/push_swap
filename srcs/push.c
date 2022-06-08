/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:37:14 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/09 00:31:54 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include "list.h"
#include <unistd.h>

void pa(data_t *instance)
{
    list_t *tmp;

    if (!instance->stack_b)
        return;
    tmp = instance->stack_b;
    instance->stack_b = instance->stack_b->next;
    tmp->next = instance->stack_a;
    instance->stack_a = tmp;
    write(1, "pa\n", 3);
}

void pb(data_t *instance)
{
    list_t *tmp;

    if (!instance->stack_a)
        return;
    tmp = instance->stack_a;
    instance->stack_a = instance->stack_a->next;
    tmp->next = instance->stack_b;
    instance->stack_b = tmp;
    write(1, "pb\n", 3);
}