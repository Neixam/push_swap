/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:40:14 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 09:26:23 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVE_H
# define RESOLVE_H

# include "data.h"

void	start_resolve(t_data *instance);

void	resolve_less_than_3(t_data *instance);

void	resolve_less_than_5(t_data *instance);

void	push_pos(t_data *instance, int pos);

void	radix_sort(t_data *instance);

int		is_sort(t_data *instance, int aob,
			int (*cmp)(t_list *, t_list *), int len);

int		descending(t_list *n1, t_list *n2);

int		ascending(t_list *n1, t_list *n2);

void	go_to(t_data *instance, int pos, int aob);

int		find_value(t_list *lst, int val);

void	quick_sort_a(t_data *instance, int len);

void	quick_sort_b(t_data *instance, int len);

void	opti_balance(t_data *instance, int rot, int aob, int len);

void	refresh_med(t_list *lst, int len);

void	push_less_than_3(t_data *instance, int len);

#endif
