/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:40:14 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/13 17:23:06 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RESOLVE_H__
#define __RESOLVE_H__
#define A 354
#define B 212
#include "data.h"

void start_resolve(data_t *instance);

void resolve_less_than_3(data_t *instance);

void resolve_less_than_5(data_t *instance);

void push_pos(data_t *instance, int pos);

void radix_sort(data_t *instance);

int is_sort(data_t *instance);

void go_to(data_t *instance, int pos, int aob);

int find_value(list_t *lst, int val);

#endif
