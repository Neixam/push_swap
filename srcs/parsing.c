/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:44:16 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 10:51:00 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "parsing.h"
#include "utils.h"
#include "list.h"
#include <stdlib.h>

int	ft_atoi(char *s, int *val)
{
	long	ret;
	int		neg;
	int		test;

	neg = 1;
	if (*s == '+' || *s == '-')
		if (*(s++) == '-')
			neg = -1;
	ret = 0;
	test = 0;
	while (*s <= '9' && *s >= '0')
	{
		test = 1;
		if (ret * neg < -2147483648 || ret * neg > 2147483647)
			return (1);
		ret = ret * 10 + *(s++) - '0';
	}
	if (*s || !test)
		return (1);
	*val = ret * neg;
	return (0);
}

int	ft_isdup(t_data *instance)
{
	t_list	*tmp;
	t_list	*a;

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

int	add_all(t_list **stack, char **arg)
{
	int		value;
	int		id;
	t_list	*tmp;

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

int	ft_panic(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		free(arg[i++]);
	free(arg);
	return (1);
}

int	parsing(int ac, char **av, t_data *instance)
{
	int		i;
	char	**arg;

	i = 0;
	while (++i < ac)
	{
		arg = ft_split(av[i], ' ');
		if (!arg)
			return (1);
		if (!*arg || add_all(&instance->stack_a, arg))
			return (ft_panic(arg));
		ft_panic(arg);
	}
	if (ft_isdup(instance))
		return (1);
	return (0);
}
