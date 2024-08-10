/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:33:43 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/18 21:03:45 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*other;
	t_list	*save;

	if (!lst || !del)
		return ;
	other = *lst;
	if (other == NULL)
		return ;
	while (other != NULL)
	{
		save = other->next;
		del(other->content);
		free(other);
		other = save;
	}
	*lst = NULL;
}
