/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:10:52 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/13 18:21:25 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long ft_abs(int i)
{
    if (i < 0)
        return (-((long)i));
    return (i);
}