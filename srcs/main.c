/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:11:21 by ambouren          #+#    #+#             */
/*   Updated: 2022/04/29 18:44:11 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

int	main(int ac, char **av)
{
	t_data	instance;

	instance = init_data();
	if (ac < 1)
		return (print_error());
	if (parsing(ac, av, &instance))
		return (print_error());
	return (0);
}
