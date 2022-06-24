/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:13:18 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 14:10:27 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <unistd.h>

int	descending(list_t *n1, list_t *n2)
{
	return (n1->value > n2->value);
}

int	ascending(list_t *n1, list_t *n2)
{
	return (n1->value < n2->value);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}
