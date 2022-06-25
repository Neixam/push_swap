/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:41:23 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 09:27:17 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "list.h"

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*st_instr;
	int		nb_enter;
	int		max;
	int		min;
}			t_data;

t_data	init_data(void);

void	ft_destroy_data(t_data *data);

#endif
