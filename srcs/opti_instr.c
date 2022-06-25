/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 09:31:38 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 10:21:03 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include <stdlib.h>
#include "utils.h"

void	delete_instr(t_list **instrs, t_list **todel)
{
	t_list	*tmp;

	if (!*todel)
		return ;
	if (*todel == *instrs)
	{
		*instrs = (*todel)->next;
		free(*todel);
		(*todel) = (*instrs);
		return ;
	}
	tmp = *instrs;
	while (tmp && tmp->next)
	{
		if (tmp->next == *todel)
		{
			tmp->next = tmp->next->next;
			free(*todel);
			(*todel) = tmp;
			return ;
		}
		tmp = tmp->next;
	}
}

void	opti_ss(t_list **instrs, t_list **pos, int flag)
{
	t_list	*tmp;
	int		aob;

	if ((flag & 3) == A)
		aob = B;
	else
		aob = A;
	tmp = (*pos)->next;
	while (tmp && !is_statement_in(tmp->value, aob)
		&& !is_rotate_in(tmp->value, aob))
		tmp = tmp->next;
	if (tmp && ((is_statement(tmp->value) & 3) == aob)
		&& ((is_statement(tmp->value) >> 4) == (flag >> 4)))
	{
		(*pos)->value = flag >> 4;
		delete_instr(instrs, &tmp);
	}
}

void	opti_instr_next(t_list **instrs)
{
	t_list	*tmp;

	tmp = *instrs;
	while (tmp)
	{
		if (is_rotate(tmp->value))
			opti_double(instrs, &tmp, is_rotate(tmp->value));
		else if ((is_statement(tmp->value) >> 4) == SS)
			opti_ss(instrs, &tmp, is_statement(tmp->value));
		tmp = tmp->next;
	}
}

void	opti_instr(t_list **instrs)
{
	t_list	*tmp;

	tmp = *instrs;
	while (tmp)
	{
		if (is_rotate(tmp->value))
			opti_rotate(instrs, &tmp, is_rotate(tmp->value));
		tmp = tmp->next;
	}
	tmp = *instrs;
	while (tmp)
	{
		if ((is_statement(tmp->value) >> 4) == SS)
			opti_swap(instrs, &tmp, is_statement(tmp->value));
		else if ((is_statement(tmp->value) >> 4) != SS)
			opti_push(instrs, &tmp, is_statement(tmp->value));
		tmp = tmp->next;
	}
	opti_instr_next(instrs);
}

void	print_instr(t_list *l)
{
	static char	*to_string[]
		= {
		"sa\n",
		"sb\n",
		"ss\n",
		"pa\n",
		"pb\n",
		"ra\n",
		"rb\n",
		"rr\n",
		"rra\n",
		"rrb\n",
		"rrr\n",
	};

	while (l)
	{
		ft_putstr(to_string[l->value]);
		l = l->next;
	}
}
