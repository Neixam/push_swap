/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_less_than.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:53:26 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/09 10:35:28 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolve.h"
#include "operation.h"

void resolve_less_than_3(data_t *instance)
{
    if (is_sort(instance))
        return;
    if (instance->nb_enter == 2)
        return (sa(instance));
    if (instance->stack_a->value > instance->stack_a->next->value)
    {
        if (instance->stack_a->value < instance->stack_a->next->next->value)
            return (sa(instance));
        if (instance->stack_a->next->value < instance->stack_a->next->next->value)
            return (ra(instance));
        sa(instance);
        return (rra(instance));
    }
    if (instance->stack_a->value > instance->stack_a->next->next->value)
        return (rra(instance));
    sa(instance);
    ra(instance);
}

void insert_borne(data_t *instance)
{
    pa(instance);
    ra(instance);
}

void resolve_less_than_5(data_t *instance)
{

    if (instance->nb_enter < 4)
        return (resolve_less_than_3(instance));
    if (instance->nb_enter == 5)
        pb(instance);
    pb(instance);
    resolve_less_than_3(instance);
}
