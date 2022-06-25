/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:46:05 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 10:28:39 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolve.h"
#include "list.h"
#include "operation.h"
#include "utils.h"
#include <stdlib.h>

int	is_resolve(t_data *instance)
{
	if (instance->nb_enter <= 1)
		return (1);
	return (is_sort(instance, A, ascending, instance->nb_enter));
}

void	push_all_a(t_data *instance)
{
	while (instance->stack_b)
		pa(instance);
}

void	push_all_last(t_data *instance)
{
	int	max;

	if (is_sort(instance, B, descending, 5))
		return (push_all_a(instance));
	max = 3;
	while (max-- && ft_lstsize(instance->stack_b) > 3)
	{
		if (instance->stack_b->id >= 3)
			pa(instance);
		else
			rb(instance);
	}
	while (max++ < 3 && ft_lstsize(instance->stack_b) > 3)
	{
		if (instance->stack_b->id >= 3)
			pa(instance);
		else
			rrb(instance);
	}
	if (!is_sort(instance, A, ascending, 2))
		sa(instance);
	if (is_sort(instance, B, descending, 3))
		return (push_all_a(instance));
	push_less_than_3(instance, 3);
}

void	init_quick_sort(t_data *instance)
{
	int	i;
	int	rot;
	int	len;

	i = 0;
	rot = 0;
	len = instance->nb_enter - 5;
	while (i++ < instance->nb_enter)
	{
		if (instance->stack_a->id < 5)
		{
			pb(instance);
			rb(instance);
		}
		else if (instance->stack_a->id - 5 < len / 2 + len % 2)
			pb(instance);
		else if (++rot)
			ra(instance);
	}
	quick_sort_a(instance, rot);
	quick_sort_b(instance, len - rot);
	push_all_last(instance);
}

void	start_resolve(t_data *instance)
{
	if (is_resolve(instance))
		return ;
	if (instance->nb_enter <= 5)
		resolve_less_than_5(instance);
	else
		init_quick_sort(instance);
	opti_instr(&instance->st_instr);
	print_instr(instance->st_instr);
}
