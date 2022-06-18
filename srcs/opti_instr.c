/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 09:31:38 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/18 13:07:19 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include <stdlib.h>
#include "utils.h"

void delete_instr(list_t **instrs, list_t **todel)
{
    list_t *tmp;

    if (!*todel)
        return;
    if (*todel == *instrs)
    {
        *instrs = (*todel)->next;
        free(*todel);
        (*todel) = (*instrs);
        return;
    }
    tmp = *instrs;
    while (tmp && tmp->next)
    {
        if (tmp->next == *todel)
        {
            tmp->next = tmp->next->next;
            free(*todel);
            (*todel) = tmp;
            return;
        }
        tmp = tmp->next;
    }
}

void opti_rotate(list_t **instrs, list_t **pos, int flag)
{
    list_t *tmp;
    int inv;

    tmp = *pos;
    if (flag >> 4 == RR)
        inv = (RRR << 4) | (flag & 3);
    else
        inv = (RR << 4) | (flag & 3);
    while (tmp && is_rotate(tmp->value) != inv && !is_statement_in(tmp->value, flag & 3))
        tmp = tmp->next;
    if (tmp && is_rotate(tmp->value) == inv)
    {
        delete_instr(instrs, pos);
        delete_instr(instrs, &tmp);
    }
}

void opti_swap(list_t **instrs, list_t **pos, int flag)
{
    list_t *tmp;

    tmp = (*pos)->next;
    while (tmp && !is_rotate_in(tmp->value, flag & 3) && !is_statement_in(tmp->value, flag & 3))
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

    tmp = (*pos)->next;
    while (tmp && !is_statement_in(tmp->value, flag & 3))
    {
        if (((is_rotate(tmp->value) & 3) != (flag & 3)) &&
            ((is_rotate(tmp->value) >> 4) == (flag >> 4)))
        {
            (*pos)->value = flag >> 4;
            delete_instr(instrs, &tmp);
            return;
        }
        tmp = tmp->next;
    }
}

void opti_push(list_t **instrs, list_t **pos, int flag)
{
    list_t *tmp;
    int inv;

    tmp = *pos;
    if (flag >> 4 == PA)
        inv = (PB << 4);
    else
        inv = (PA << 4);
    while (tmp && !is_rotate(tmp->value) && is_statement(tmp->value) == flag)
        tmp = tmp->next;
    if (tmp && (is_statement(tmp->value) >> 4) == inv)
    {
        delete_instr(instrs, pos);
        delete_instr(instrs, &tmp);
    }
}

void opti_instr(list_t **instrs)
{
    list_t *tmp;

    tmp = *instrs;
    while (tmp)
    {
        if (is_rotate(tmp->value))
            opti_rotate(instrs, &tmp, is_rotate(tmp->value));
        tmp = tmp->next;
    }
    tmp = *instrs;
    while (tmp)
    {
        if (is_statement(tmp->value) >> 4 == SS)
            opti_swap(instrs, &tmp, is_statement(tmp->value));
        else if (is_statement(tmp->value) >> 4 != SS)
            opti_push(instrs, &tmp, is_statement(tmp->value));
        tmp = tmp->next;
    }
    tmp = *instrs;
    while (tmp)
    {
        if (is_rotate(tmp->value))
            opti_double(instrs, &tmp, is_rotate(tmp->value));
        tmp = tmp->next;
    }
}

void print_instr(list_t *l)
{
    static char *to_string[] =
        {
            "sa\n",
            "sb\n",
            "ss\n",
            "pa\n",
            "pb\n",
            "ra\n",
            "rb\n",
            "rr\n",
            "rra\n",
            "rrb\n",
            "rrr\n",
        };

    while (l)
    {
        ft_putstr(to_string[l->value]);
        l = l->next;
    }
}