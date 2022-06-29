/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:38:04 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/26 15:21:39 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include <stdlib.h>

void	ra(t_data *instance)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = instance->stack_a;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp2 = instance->stack_a;
	tmp->next = instance->stack_a;
	instance->stack_a = instance->stack_a->next;
	tmp2->next = 0;
	if (ft_add_back(&instance->st_instr, RA))
		exit(1);
}

void	rb(t_data *instance)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = instance->stack_b;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp2 = instance->stack_b;
	tmp->next = instance->stack_b;
	instance->stack_b = instance->stack_b->next;
	tmp2->next = 0;
	if (ft_add_back(&instance->st_instr, RB))
		exit(1);
}

void	rr(t_data *instance)
{
	t_list	*tmp;
	t_list	*tmp2;

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
	if (ft_add_back(&instance->st_instr, RR))
		exit(1);
}

int	is_rotate(int val)
{
	if (is_rotate_in(val, A))
		return ((is_rotate_in(val, A) << 4) | A);
	if (is_rotate_in(val, B))
		return ((is_rotate_in(val, B) << 4) | B);
	return (0);
}

int	is_statement(int val)
{
	if (is_statement_in(val, A))
		return ((is_statement_in(val, A) << 4) | A);
	if (is_statement_in(val, B))
		return ((is_statement_in(val, B) << 4) | B);
	return (0);
}
