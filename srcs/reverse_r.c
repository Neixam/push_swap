/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:38:50 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/26 15:23:25 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include <stdlib.h>

void	rra(t_data *instance)
{
	t_list	*tmp;
	t_list	*ant;

	tmp = instance->stack_a;
	if (!tmp || !tmp->next)
		return ;
	while (tmp && tmp->next)
		tmp = tmp->next;
	ant = instance->stack_a;
	while (ant && ant->next != tmp)
		ant = ant->next;
	tmp->next = instance->stack_a;
	instance->stack_a = tmp;
	ant->next = 0;
	if (ft_add_back(&instance->st_instr, RRA))
		exit(1);
}

void	rrb(t_data *instance)
{
	t_list	*tmp;
	t_list	*ant;

	tmp = instance->stack_b;
	if (!tmp || !tmp->next)
		return ;
	while (tmp && tmp->next)
		tmp = tmp->next;
	ant = instance->stack_b;
	while (ant && ant->next != tmp)
		ant = ant->next;
	tmp->next = instance->stack_b;
	instance->stack_b = tmp;
	ant->next = 0;
	if (ft_add_back(&instance->st_instr, RRB))
		exit(1);
}

void	rrr(t_data *instance)
{
	t_list	*tmp;
	t_list	*ant;

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
	if (ft_add_back(&instance->st_instr, RRR))
		exit(1);
}
