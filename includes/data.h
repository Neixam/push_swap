/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:41:23 by ambouren          #+#    #+#             */
/*   Updated: 2022/04/29 18:46:26 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DATA_H__
# define __DATA_H__
# include "libft.h"

typedef struct	s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		nb_enter;
	int		max;
	int		min;
}				t_data;

t_data	init_data(void);




#endif
