/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:44:16 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/18 11:00:06 by ambouren         ###   ########.fr       */
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

	neg = 1;
	if (*s == '+' || *s == '-')
		if (*(s++) == '-')
			neg = -1;
	if ((*s <= 'z' && *s >= 'a') || (*s <= 'Z' && *s >= 'A'))
		return (1);
	ret = 0;
	while (*s <= '9' && *s >= '0')
	{
		if ((neg < 0 && ret * neg < -2147483648) ||
			(neg > 0 && ret > 2147483647))
			return (1);
		ret = ret * 10 + *(s++) - '0';
	}
	if ((*s <= 'z' && *s >= 'a') || (*s <= 'Z' && *s >= 'A'))
		return (1);
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
	int id;
	list_t *tmp;

	while (*arg)
	{
		if (ft_atoi(*(arg++), &value))
			return (1);
		if (ft_add_back(stack, value))
			return (1);
		tmp = *stack;
		id = 0;
		while (tmp)
		{
			if (tmp->value > value)
				tmp->id++;
			else if (tmp->value == value)
				tmp->id = id;
			else
				id++;
			tmp = tmp->next;
		}
	}
	return (0);
}

int parsing(int ac, char **av, data_t *instance)
{
	int i;
	int j;
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
		j = 0;
		while (arg[j])
			free(arg[j++]);
		free(arg);
	}
	if (ft_isdup(instance))
		return (1);
	return (0);
}
