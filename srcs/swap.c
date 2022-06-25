/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:36:13 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 10:23:37 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

void	sa(t_data *instance)
{
	int	tmp;

	if (!instance->stack_a || !instance->stack_a->next)
		return ;
	tmp = instance->stack_a->value;
	instance->stack_a->value = instance->stack_a->next->value;
	instance->stack_a->next->value = tmp;
	tmp = instance->stack_a->id;
	instance->stack_a->id = instance->stack_a->next->id;
	instance->stack_a->next->id = tmp;
	ft_add_back(&instance->st_instr, SA);
}

void	sb(t_data *instance)
{
	int	tmp;

	if (!instance->stack_b || !instance->stack_b->next)
		return ;
	tmp = instance->stack_b->value;
	instance->stack_b->value = instance->stack_b->next->value;
	instance->stack_b->next->value = tmp;
	tmp = instance->stack_b->id;
	instance->stack_b->id = instance->stack_b->next->id;
	instance->stack_b->next->id = tmp;
	ft_add_back(&instance->st_instr, SB);
}

void	ss(t_data *instance)
{
	int	tmp;

	if ((!instance->stack_a || !instance->stack_a->next)
		&& (!instance->stack_b || !instance->stack_b->next))
		return ;
	tmp = instance->stack_a->value;
	instance->stack_a->value = instance->stack_a->next->value;
	instance->stack_a->next->value = tmp;
	tmp = instance->stack_a->id;
	instance->stack_a->id = instance->stack_a->next->id;
	instance->stack_a->next->id = tmp;
	tmp = instance->stack_b->value;
	instance->stack_b->value = instance->stack_b->next->value;
	instance->stack_b->next->value = tmp;
	tmp = instance->stack_b->id;
	instance->stack_b->id = instance->stack_b->next->id;
	instance->stack_b->next->id = tmp;
	ft_add_back(&instance->st_instr, SS);
}
