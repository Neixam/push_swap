/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:11:21 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/09 13:14:04 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "utils.h"
#include "parsing.h"
#include "resolve.h"
#include <stdio.h>
#include "list.h"

void print_list(list_t *l)
{
	for (; l; l = l->next)
		printf("%d%s", l->value, (l->next) ? ", " : "\n");
}

int main(int ac, char **av)
{
	data_t instance;

	instance = init_data();
	if (ac < 1)
		return (print_error());
	if (parsing(ac, av, &instance))
		return (print_error());
	start_resolve(&instance);
	/*	printf("STACK A:\n");
		print_list(instance.stack_a);
		printf("STACK B:\n");
		print_list(instance.stack_b);
		printf("MAX=%d, MIN=%d, SIZE=%d\n", instance.max, instance.min, instance.nb_enter);
	*/
	ft_destroy_data(&instance);
	return (0);
}
