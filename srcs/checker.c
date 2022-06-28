/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:11:15 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 14:09:52 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "operation.h"
#include "resolve.h"
#include "utils.h"
#include "get_next_line.h"
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	init_instr(t_instrs instrs[11])
{
	instrs[SA] = sa;
	instrs[SB] = sb;
	instrs[SS] = ss;
	instrs[PA] = pa;
	instrs[PB] = pb;
	instrs[RA] = ra;
	instrs[RB] = rb;
	instrs[RR] = rr;
	instrs[RRA] = rra;
	instrs[RRB] = rrb;
	instrs[RRR] = rrr;
}

t_instr	parse_instr(char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		return (SA);
	if (!ft_strcmp(line, "sb\n"))
		return (SB);
	if (!ft_strcmp(line, "ss\n"))
		return (SS);
	if (!ft_strcmp(line, "pa\n"))
		return (PA);
	if (!ft_strcmp(line, "pb\n"))
		return (PB);
	if (!ft_strcmp(line, "ra\n"))
		return (RA);
	if (!ft_strcmp(line, "rb\n"))
		return (RB);
	if (!ft_strcmp(line, "rr\n"))
		return (RR);
	if (!ft_strcmp(line, "rra\n"))
		return (RRA);
	if (!ft_strcmp(line, "rrb\n"))
		return (RRB);
	if (!ft_strcmp(line, "rrr\n"))
		return (RRR);
	return (-1);
}

int	read_instr(t_data *instance)
{
	char		*line;
	t_instrs	instrs[11];
	int			ret;

	init_instr(instrs);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (0);
		ret = parse_instr(line);
		free(line);
		if (ret == -1)
			return (1);
		instrs[ret](instance);
	}
}

int	main(int ac, char **av)
{
	t_data	instance;

	instance = init_data();
	if (ac <= 1)
		return (0);
	if (parsing(ac, av, &instance))
	{
		ft_destroy_data(&instance);
		return (print_error());
	}
	if (read_instr(&instance))
	{
		ft_destroy_data(&instance);
		return (print_error());
	}
	if (ft_lstsize(instance.stack_a) != instance.nb_enter
		|| !is_sort(&instance, A, ascending, instance.nb_enter))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	ft_destroy_data(&instance);
	return (0);
}
