/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:41:23 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/18 10:32:28 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DATA_H__
#define __DATA_H__
#include "list.h"

typedef struct data_s
{
	list_t *stack_a;
	list_t *stack_b;
	list_t *st_instr;
	int nb_enter;
	int max;
	int min;
} data_t;

data_t init_data(void);

void ft_destroy_data(data_t *data);

int creat_radix_tab(data_t *data);

#endif
