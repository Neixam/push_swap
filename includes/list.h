/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:27:33 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/08 21:45:40 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIST_H__
#define __LIST_H__

typedef struct list_s
{
    int value;
    struct list_s *next;
} list_t;

list_t *ft_new_cell(int value);

int ft_add_back(list_t **lst, int value);

int ft_add_head(list_t **lst, int value);

void ft_destroy_lst(list_t **lst);

#endif