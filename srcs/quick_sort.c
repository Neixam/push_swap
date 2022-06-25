/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:39:41 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 09:59:39 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolve.h"
#include "operation.h"

void	opti_balance(t_data *instance, int rot, int aob, int len)
{
	if (rot >= len / 2)
		rot -= len;
	while (rot)
	{
		if (rot > 0)
		{
			if (aob == A)
				rra(instance);
			else
				rrb(instance);
			rot--;
		}
		else
		{
			if (aob == A)
				ra(instance);
			else
				rb(instance);
			rot++;
		}
	}
}

void	sort_less_than_3(t_data *instance, int len)
{
	if (len == 1)
		return ;
	if (len == 3 && ft_lstsize(instance->stack_a) == 3)
		return (resolve_less_than_3(instance));
	if (len == 2)
		return (sa(instance));
	if (instance->stack_a->value > instance->stack_a->next->value)
		sa(instance);
	if (!is_sort(instance, A, ascending, 3))
	{
		pb(instance);
		sa(instance);
		pa(instance);
		if (instance->stack_a->value > instance->stack_a->next->value)
			sa(instance);
	}
}

void	refresh_med(t_list *lst, int len)
{
	t_list	*tmp;
	t_list	*head;
	int		i;
	int		j;

	head = lst;
	i = 0;
	while (lst && i < len)
	{
		lst->id = 0;
		tmp = head;
		j = 0;
		while (tmp && j < len)
		{
			if (lst->value > tmp->value)
				lst->id++;
			tmp = tmp->next;
			j++;
		}
		lst = lst->next;
		i++;
	}
}

void	quick_sort_a(t_data *instance, int len)
{
	int	i;
	int	rot;

	if (is_sort(instance, A, ascending, len))
		return ;
	if (len <= 3)
		return (sort_less_than_3(instance, len));
	refresh_med(instance->stack_a, len);
	i = 0;
	rot = 0;
	while (i++ < len)
	{
		if (instance->stack_a->id < len / 2 + len % 2)
			pb(instance);
		else if (++rot)
			ra(instance);
	}
	if (ft_lstsize(instance->stack_a) != rot)
		opti_balance(instance, rot, A, ft_lstsize(instance->stack_a));
	quick_sort_a(instance, rot);
	quick_sort_b(instance, len - rot);
}
