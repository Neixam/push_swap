/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:44:32 by ambouren          #+#    #+#             */
/*   Updated: 2022/04/29 18:47:36 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

t_data	init_data(void)
{
	t_data	ret;

	ret.stack_a = NULL;
	ret.stack_b = NULL;
	ret.nb_enter = 0;
	ret.max = 0;
	ret.min = 0;
	return (ret);
}
