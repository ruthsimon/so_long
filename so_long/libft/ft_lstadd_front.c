/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:11:41 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/17 22:07:22 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int main() 
// {
//     t_list *head= malloc( sizeof(t_list));
//     head = NULL;
//     t_list *first = malloc (sizeof(t_list));
//     first->content = "ruth";
//     first-> next = NULL;
//     t_list *second = malloc (sizeof(t_list));
//     second-> content = "simon";
//     second->next = NULL;
//     head = &first;
//     ft_lstadd_front(head, second); 
// }