/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:16:19 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 10:21:53 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

void opti_rotate(list_t **instrs, list_t **pos, int flag)
{
    list_t *tmp;
    int inv;

    tmp = *pos;
    if (flag >> 4 == RR)
        inv = (RRR << 4) | (flag & 3);
    else
        inv = (RR << 4) | (flag & 3);
    while (tmp && is_rotate(tmp->value) != inv &&
           !is_statement_in(tmp->value, flag & 3))
        tmp = tmp->next;
    if (tmp && is_rotate(tmp->value) == inv)
    {
        delete_instr(instrs, pos);
        delete_instr(instrs, &tmp);
    }
}

void opti_push(list_t **instrs, list_t **pos, int flag)
{
    list_t *tmp;
    int inv;

    tmp = *pos;
    if (flag >> 4 == PA)
        inv = PB;
    else
        inv = PA;
    while (tmp && !is_rotate(tmp->value) && is_statement(tmp->value) == flag)
        tmp = tmp->next;
    if (tmp && (is_statement(tmp->value) >> 4) == inv)
    {
        delete_instr(instrs, pos);
        delete_instr(instrs, &tmp);
    }
}

void opti_swap(list_t **instrs, list_t **pos, int flag)
{
    list_t *tmp;

    tmp = (*pos)->next;
    while (tmp && !is_rotate_in(tmp->value, flag & 3) &&
           !is_statement_in(tmp->value, flag & 3))
        tmp = tmp->next;
    if (tmp && is_statement(tmp->value) == flag)
    {
        delete_instr(instrs, pos);
        delete_instr(instrs, &tmp);
    }
}

void opti_double(list_t **instrs, list_t **pos, int flag)
{
    list_t *tmp;
    int aob;

    if ((flag & 3) == A)
        aob = B;
    else
        aob = A;
    tmp = (*pos)->next;
    while (tmp && !is_statement_in(tmp->value, aob))
    {
        if ((((is_rotate(tmp->value) & 3) == aob)) &&
            ((is_rotate(tmp->value) >> 4) == (flag >> 4)))
        {
            (*pos)->value = flag >> 4;
            delete_instr(instrs, &tmp);
            return;
        }
        tmp = tmp->next;
    }
}