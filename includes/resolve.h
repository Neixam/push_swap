/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 07:40:14 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/11 19:13:37 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RESOLVE_H__
#define __RESOLVE_H__
#include "data.h"

void	start_resolve(data_t *instance);

void	resolve_less_than_3(data_t *instance);

void	resolve_less_than_5(data_t *instance);

void	push_pos(data_t *instance, int pos);

void	radix_sort(data_t *instance);

void	insert_sort500(data_t *instance);

int		is_sort(data_t *instance);


#endif
