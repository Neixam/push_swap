/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:32:19 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/14 12:50:10 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __OPERATION_H__
#define __OPERATION_H__
#include "data.h"
#define SWAP(x, y) (y == A) ? sa(x) : sb(x)
#define ROT(x, y) (y == A) ? ra(x) : rb(x)
#define RROT(x, y) (y == A) ? rra(x) : rrb(x)
#define PUSH(x, y) (y == A) ? pa(x) : pb(x)

void sa(data_t *instance);
void sb(data_t *instance);
void ss(data_t *instance);

void pa(data_t *instance);
void pb(data_t *instance);

void ra(data_t *instance);
void rb(data_t *instance);
void rr(data_t *instance);

void rra(data_t *instance);
void rrb(data_t *instance);
void rrr(data_t *instance);

#endif