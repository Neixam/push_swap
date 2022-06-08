/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:44:16 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/08 23:29:38 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "parsing.h"
#include "utils.h"
#include "list.h"
#include <stdlib.h>

int ft_atoi(char *s, int *val)
{
	long ret;
	int neg;

	while (ft_isblank(*s))
		s++;
	neg = 1;
	if (*s == '+' || *s == '-')
		if (*(s++) == '-')
			neg = -1;
	ret = 0;
	while (*s <= '9' && *s >= '0')
	{
		if ((neg < 0 && ret * neg < -2147483648) ||
			(neg > 0 && ret > 2147483647))
			return (1);
		ret = ret * 10 + *(s++) - '0';
	}
	*val = ret * neg;
	return (0);
}

int ft_isdup(data_t *instance)
{
	list_t *tmp;
	list_t *a;

	a = instance->stack_a;
	instance->min = instance->stack_a->value;
	instance->max = instance->stack_a->value;
	while (a)
	{
		if (a->value > instance->max)
			instance->max = a->value;
		if (a->value < instance->min)
			instance->min = a->value;
		tmp = a->next;
		while (tmp)
		{
			if (tmp->value == a->value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
		instance->nb_enter++;
	}
	return (0);
}

int add_all(list_t **stack, char **arg)
{
	int value;

	while (*arg)
	{
		if (ft_atoi(*(arg++), &value))
			return (1);
		if (ft_add_back(stack, value))
			return (1);
	}
	return (0);
}

int parsing(int ac, char **av, data_t *instance)
{
	int i;
	char **arg;

	i = 0;
	while (++i < ac)
	{
		arg = ft_split(av[i], ' ');
		if (!arg)
			return (1);
		if (add_all(&instance->stack_a, arg))
		{
			free(arg);
			return (1);
		}
		free(arg);
	}
	if (ft_isdup(instance))
		return (1);
	return (0);
}
