/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:53:39 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 09:26:32 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

int print_error(void);

size_t ft_strlen(const char *s1);

char *ft_strdup(const char *s1);

char **ft_split(char const *s, char c);

int ft_isblank(int c);

long ft_abs(int n);

void ft_putstr(char *s);

#endif
