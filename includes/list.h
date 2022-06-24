/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:27:33 by ambouren          #+#    #+#             */
/*   Updated: 2022/06/24 09:26:39 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

typedef struct list_s
{
    int value;
    int id;
    struct list_s *next;
} list_t;

list_t *ft_new_cell(int value);

int ft_add_back(list_t **lst, int value);

int ft_add_head(list_t **lst, int value);

void ft_destroy_lst(list_t **lst);

int ft_lstsize(list_t *lst);

int ft_lstmm(list_t *lst, int *min, int *max);

#endif
