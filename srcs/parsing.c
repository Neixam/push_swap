/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:44:16 by ambouren          #+#    #+#             */
/*   Updated: 2022/04/29 18:59:48 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "parsing.h"
#include "utils.h"

int	parsing(int	ac, char **av, t_data *instance)
{
	int		i;
	char	**arg;

	i = 1;
	arg = NULL;
	while (i < ac)
	{
		if (arg)
			free(arg);
		arg = ft_split(av[i], " ");
		if (!arg)
			return (print_error());
		if (add_all(&instance->stack_a, arg))
		{
			free(arg);
			return (print_error());
		}
	}
	instance->nb_enter = ft_lstsize(instance->stack_a);
	instance->max = ft_lstmax(instance->stack_a);
	instance->min = ft_lstmin(instance->stack_a);
	return (0);
}
