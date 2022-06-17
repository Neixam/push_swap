/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:13:18 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/14 13:15:52 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int descending(list_t *n1, list_t *n2)
{
    return (n1->value > n2->value);
}

int ascending(list_t *n1, list_t *n2)
{
    return (n1->value < n2->value);
}