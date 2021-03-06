/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 22:01:20 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/13 19:44:58 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "list.h"
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*(s++))
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ret)
		return (0);
	i = -1;
	while (((char *)s1)[++i])
		ret[i] = ((char *)s1)[i];
	ret[i] = 0;
	return (ret);
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	ft_isblank(int c)
{
	return (c == '\n' || c == '\t' || c == ' '
		|| c == '\r' || c == '\f' || c == '\v');
}

int	ft_lstmm(t_list *lst, int *min, int *max)
{
	if (!lst)
		return (1);
	*min = lst->value;
	*max = lst->value;
	while (lst)
	{
		if (lst->value < *min)
			*min = lst->value;
		if (lst->value > *max)
			*max = lst->value;
		lst = lst->next;
	}
	return (0);
}
