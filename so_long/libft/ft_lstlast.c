/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:29:32 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/19 19:02:04 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst-> next;
	}
	return (lst);
}

// int main() 
// {
//     t_list *first = ft_lstnew(strdup("ruth"));
//     t_list *A= ft_lstnew(strdup("simon"));
//     t_list *B = ft_lstnew(strdup("tekle"));
//     t_list *C = ft_lstnew(strdup("hi"));
//      first->next = A;
//      A->next =B;
// 	 //print_list(first);
//      ft_lstadd_back(&first, C);
// 	 //print_list(first);
// 	 ft_lstlast(first);
// }
