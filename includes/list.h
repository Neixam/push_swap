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
# define LIST_H

typedef struct s_list
{
	int				value;
	int				id;
	struct s_list	*next;
}					t_list;

t_list	*ft_new_cell(int value);

int		ft_add_back(t_list **lst, int value);

int		ft_add_head(t_list **lst, int value);

void	ft_destroy_lst(t_list **lst);

int		ft_lstsize(t_list *lst);

int		ft_lstmm(t_list *lst, int *min, int *max);

#endif
