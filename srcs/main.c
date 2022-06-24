/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:11:21 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 14:13:46 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "utils.h"
#include "parsing.h"
#include "resolve.h"
#include "list.h"

int	main(int ac, char **av)
{
	data_t	instance;

	instance = init_data();
	if (ac < 1)
		return (print_error());
	if (parsing(ac, av, &instance))
	{
		ft_destroy_data(&instance);
		return (print_error());
	}
	start_resolve(&instance);
	ft_destroy_data(&instance);
	return (0);
}
