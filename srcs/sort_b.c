/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:39:41 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 09:59:39 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolve.h"
#include "operation.h"

void	push_len_a(t_data *instance, int len)
{
	while (len--)
		pa(instance);
}

void	insert_good(t_data *instance, int *rot)
{
	int	len;
	int	i;

	if (!instance->stack_a)
		return (pa(instance));
	len = ft_lstsize(instance->stack_a);
	i = len / 2;
	while (i-- && instance->stack_a->value < instance->stack_b->value)
	{
		ra(instance);
		(*rot)++;
	}
	while (i++ < len && instance->stack_a->value < instance->stack_b->value)
	{
		rra(instance);
		(*rot)--;
	}
	pa(instance);
}

void	do_sort_b(t_data *instance, int len, int *rot, int *rot2)
{
	int	i;

	i = 0;
	while (i++ < len)
	{
		if (instance->stack_b->id >= len / 2 + len % 2)
			insert_good(instance, rot2);
		else if (++(*rot))
			rb(instance);
	}
}

void	quick_sort_b(t_data *instance, int len)
{
	int	rot;
	int	rot2;

	if (is_sort(instance, B, descending, len))
		return (push_len_a(instance, len));
	if (len <= 3)
		return (push_less_than_3(instance, len));
	refresh_med(instance->stack_b, len);
	rot = 0;
	rot2 = 0;
	do_sort_b(instance, len, &rot, &rot2);
	if (ft_lstsize(instance->stack_b) != rot)
		opti_balance(instance, rot, B, ft_lstsize(instance->stack_b));
	opti_balance(instance, rot2, A, ft_lstsize(instance->stack_a));
	quick_sort_a(instance, len - rot);
	quick_sort_b(instance, rot);
}
