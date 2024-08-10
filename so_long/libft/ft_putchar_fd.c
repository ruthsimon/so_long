/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:48:17 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/17 19:29:55 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// int main()
// {
//     int fd;

//     fd = open("test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0777);
//     if (fd == -1)
//         fprintf(stderr, "Couldn't open file");
//     ft_putchar_fd('a', fd);

//     close(fd);
//     return (0);
// }