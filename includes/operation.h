/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:32:19 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 11:26:40 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
#define OPERATION_H
#include "data.h"
#define A 1
#define B 2

typedef void (*instrs_t)(data_t *);

typedef enum intr_e
{
    SA,
    SB,
    SS,
    PA,
    PB,
    RA,
    RB,
    RR,
    RRA,
    RRB,
    RRR
} instr_t;

void sa(data_t *instance);
void sb(data_t *instance);
void ss(data_t *instance);

void pa(data_t *instance);
void pb(data_t *instance);

void ra(data_t *instance);
void rb(data_t *instance);
void rr(data_t *instance);

void rra(data_t *instance);
void rrb(data_t *instance);
void rrr(data_t *instance);

int is_rotate_in(int val, int aob);
int is_rotate(int val);
int is_statement_in(int val, int aob);
int is_statement(int val);

void opti_instr(list_t **instrs);
void print_instr(list_t *l);
void delete_instr(list_t **instrs, list_t **todel);
void opti_rotate(list_t **instrs, list_t **pos, int flag);
void opti_double(list_t **instrs, list_t **pos, int flag);
void opti_swap(list_t **instrs, list_t **pos, int flag);
void opti_push(list_t **instrs, list_t **pos, int flag);

#endif