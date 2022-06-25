/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:44:32 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 14:10:48 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "list.h"

void	ft_destroy_data(t_data *data)
{
	ft_destroy_lst(&data->stack_a);
	ft_destroy_lst(&data->stack_b);
	ft_destroy_lst(&data->st_instr);
}

t_data	init_data(void)
{
	t_data	ret;

	ret.stack_a = 0;
	ret.stack_b = 0;
	ret.st_instr = 0;
	ret.nb_enter = 0;
	ret.max = 0;
	ret.min = 0;
	return (ret);
}
