/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:16:40 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/17 22:32:18 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// int main()
// {
// 	t_list	*head;
// 	t_list	*first;
// 	t_list	*second;

// 	head = ft_lstnew(ft_strdup("Hi"));

// 	first = ft_lstnew(ft_strdup("Ruth"));
// 	head->next = first;

// 	second = ft_lstnew(ft_strdup("it's Moosa"));
// 	first->next = second;

// 	printf("%d", ft_lstsize(head));

// 	return (0);
// }