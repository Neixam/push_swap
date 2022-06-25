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
# define OPERATION_H
# include "data.h"
# define A 1
# define B 2

typedef void	(*t_instrs)(t_data *);

typedef enum e_instr
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
}	t_instr;

void	sa(t_data *instance);
void	sb(t_data *instance);
void	ss(t_data *instance);

void	pa(t_data *instance);
void	pb(t_data *instance);

void	ra(t_data *instance);
void	rb(t_data *instance);
void	rr(t_data *instance);

void	rra(t_data *instance);
void	rrb(t_data *instance);
void	rrr(t_data *instance);

int		is_rotate_in(int val, int aob);
int		is_rotate(int val);
int		is_statement_in(int val, int aob);
int		is_statement(int val);

void	opti_instr(t_list **instrs);
void	print_instr(t_list *l);
void	delete_instr(t_list **instrs, t_list **todel);
void	opti_rotate(t_list **instrs, t_list **pos, int flag);
void	opti_double(t_list **instrs, t_list **pos, int flag);
void	opti_swap(t_list **instrs, t_list **pos, int flag);
void	opti_push(t_list **instrs, t_list **pos, int flag);

#endif
