/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:48:21 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/19 19:16:58 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// int main()
// {
//     int fd;

//     fd = open("test1.txt", O_WRONLY | O_TRUNC | O_CREAT, 0777);
//     if (fd == -1)
//         fprintf(stderr, "Couldn't open file");
//     ft_putendl_fd("afg", fd);

//     close(fd);
//     return (0);
// }