/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:37:52 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/19 19:19:19 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	head = *lst;
	while (head -> next != NULL)
	{
		head = head->next;
	}
	head -> next = new;
}

// #include <stdio.h>
// void	print_list(t_list *head)
// {
// 	while (head != NULL)
// 	{
// 		printf("%s\n", head->content);
// 		head = head -> next;
// 	}
// }
// int main() 
// {
//     t_list *first = ft_lstnew(strdup("ruth"));
//     t_list *A= ft_lstnew(strdup("simon"));
//     t_list *B = ft_lstnew(strdup("tekle"));
//     t_list *C = ft_lstnew(strdup("hi"));
//      first->next = A;
//      A->next =B;
// 	 print_list(first);
//      ft_lstadd_back(&first, C);
// 	 print_list(first);
// }

// int main() 
// {
// 	t_list *head = NULL;
// 	t_list *C = ft_lstnew(strdup("hi"));

// 	ft_lstadd_back(&head, C);
// 	print_list(head);
// }