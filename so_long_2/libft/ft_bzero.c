/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:09:47 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/09 00:09:36 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int main ()
// {
//     char  arr[]= "ruthsimontekle";
//     ft_bzero(arr, 5);
//     printf("%s",arr);
// }

// int main()
// {
//     int arr[] = {554654, 4, 2, 3};
//     int i = 0;    
//   ft_bzero(arr, sizeof(int) * 2);

//   while (i < 4)
//   {
//     printf("%d...", arr[i++]);
//   }
//   return (0);
// }
