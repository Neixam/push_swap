/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:40:14 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/23 20:32:33 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RESOLVE_H__
#define __RESOLVE_H__

#include "data.h"

void start_resolve(data_t *instance);

void resolve_less_than_3(data_t *instance);

void resolve_less_than_5(data_t *instance);

void push_pos(data_t *instance, int pos);

void radix_sort(data_t *instance);

int is_sort(data_t *instance, int aob, int (*cmp)(list_t *, list_t *), int len);

int descending(list_t *n1, list_t *n2);

int ascending(list_t *n1, list_t *n2);

void go_to(data_t *instance, int pos, int aob);

int find_value(list_t *lst, int val);

void quick_sort_a(data_t *instance, int len);

void quick_sort_b(data_t *instance, int len);

void opti_balance(data_t *instance, int rot, int aob, int len);

void push_less_than_3(data_t *instance, int len);

#endif
