/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_less_than.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:53:26 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/13 18:27:38 by ambouren         ###   ########.fr       */
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

int find_value(list_t *lst, int val)
{
	int rotate;

	rotate = 0;
	while (lst)
	{
		if (lst->value == val)
			return (rotate);
		rotate++;
		lst = lst->next;
	}
	return (-1);
}

void push_pos(data_t *instance, int pos)
{
	go_to(instance, pos, A);
	pb(instance);
}

void insert_borne(data_t *instance)
{
	int min;
	int max;

	if (instance->nb_enter == 5)
	{
		max = find_value(instance->stack_a, instance->max);
		if (max >= instance->nb_enter / 2)
			max -= instance->nb_enter;
		push_pos(instance, max);
	}
	min = find_value(instance->stack_a, instance->min);
	if (min > instance->nb_enter / 2)
		min -= ft_lstsize(instance->stack_a);
	push_pos(instance, min);
}

void resolve_less_than_5(data_t *instance)
{
	if (instance->nb_enter < 4)
		return (resolve_less_than_3(instance));
	insert_borne(instance);
	resolve_less_than_3(instance);
	pa(instance);
	pa(instance);
	ra(instance);
}
