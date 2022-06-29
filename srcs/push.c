/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:37:14 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/26 15:20:38 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include "list.h"
#include <stdlib.h>

void	pa(t_data *instance)
{
	t_list	*tmp;

	if (!instance->stack_b)
		return ;
	tmp = instance->stack_b;
	instance->stack_b = instance->stack_b->next;
	tmp->next = instance->stack_a;
	instance->stack_a = tmp;
	if (ft_add_back(&instance->st_instr, PA))
		exit(1);
}

void	pb(t_data *instance)
{
	t_list	*tmp;

	if (!instance->stack_a)
		return ;
	tmp = instance->stack_a;
	instance->stack_a = instance->stack_a->next;
	tmp->next = instance->stack_b;
	instance->stack_b = tmp;
	if (ft_add_back(&instance->st_instr, PB))
		exit(1);
}

int	is_rotate_in(int val, int aob)
{
	if ((aob == A && val == RA)
		|| (aob == B && val == RB)
		|| val == RR)
		return (RR);
	if ((aob == A && val == RRA)
		|| (aob == B && val == RRB)
		|| val == RRR)
		return (RRR);
	return (0);
}

int	is_statement_in(int val, int aob)
{
	if ((aob == A && val == SA)
		|| (aob == B && val == SB)
		|| val == SS)
		return (SS);
	if (val == PB || val == PA)
		return (val);
	return (0);
}
