/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:39:46 by rsimon            #+#    #+#             */
/*   Updated: 2024/02/19 17:13:22 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*separate(char *store)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (store == NULL)
		return (NULL);
	while (store[i] != '\n' && store[i] != '\0')
		i++;
	if (store[i] == '\0')
		return (store);
	line = malloc(sizeof (char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (store[i] != '\n' && store[i] != '\0')
		line[j++] = store[i++];
	line[j] = '\n';
	line[j + 1] = '\0';
	return (line);
}

char	*save_left(char *store)
{
	int		i;
	int		j;
	char	*remain;

	i = 0;
	j = 0;
	while (store[i] != '\n' && store[i] != '\0')
		i++;
	if (store[i] == '\0')
		return (NULL);
	if (store[i] == '\n' && store[i + 1] == '\0')
		return (free(store), NULL);
	i++;
	while (store[i + j] != '\0')
		j++;
	remain = malloc (sizeof(char) * (j + 1));
	if (!remain)
		return (free(store), NULL);
	j = 0;
	while (store[i] != '\0')
		remain[j++] = store[i++];
	remain[j] = '\0';
	free(store);
	store = remain;
	return (remain);
}

int	check_free(int words_read, int fd, char *store[], char *buffer)
{
	if ((words_read == 0 && store[fd] == NULL) || (words_read == -1))
	{
		if (words_read == -1)
			free(store[fd]);
		free (buffer);
		return (1);
	}
	else
		return (0);
}

char	*checker(char *store[], int fd)
{
	char	*buffer;
	int		words_read;

	words_read = -1;
	while (words_read != 0 && (!ft_strchr(store[fd], '\n')))
	{
		buffer = malloc(sizeof(char) * ((size_t) BUFFER_SIZE + 1));
		if (!buffer)
		{
			free(store[fd]);
			store[fd] = NULL;
			return (NULL);
		}
		words_read = read(fd, buffer, BUFFER_SIZE);
		if (check_free(words_read, fd, store, buffer) == 1)
		{
			return ((store[fd] = NULL), NULL);
		}
		buffer[words_read] = '\0';
		store[fd] = ft_strjoin(store[fd], buffer);
		if (!store[fd])
			return (free(buffer), NULL);
		free(buffer);
	}
	return (store[fd]);
}

char	*get_next_line(int fd)
{
	char		*final;
	static char	*store[10240];

	if (fd < 0 || fd >= 10240 || BUFFER_SIZE > 2147483647 || BUFFER_SIZE <= 0)
		return (NULL);
	store[fd] = checker(store, fd);
	final = separate(store[fd]);
	if (!free_static(final, &store[fd]))
		return (NULL);
	store[fd] = save_left(store[fd]);
	return (final);
}

// #include <stdio.h>
// int main()
// {
// 	int fd = open ("ruth.txt", O_RDONLY);
// 	int fd1 = open ("ruth1.txt", O_RDONLY);
// 	int fd2 = open ("ruth2.txt", O_RDONLY);
// 	char *str;
// 	char *str1;
// 	char *str2;
// 	for (int i=0; i < 3;i++)
// 	{
// 		str = get_next_line(fd);
// 		printf("file1: %s\n", str);
// 		free(str);
// 		str1 = get_next_line(fd1);
// 		printf("file2: %s\n", str1);
// 		free(str1);
// 		str2 = get_next_line(fd2);
// 		printf("file3: %s\n", str2);
// 		printf("==============next-iteration==========\n");
// 		free(str2);
// 	}
// 	close(fd);
// 	close(fd1);
// 	close(fd2);
// }
