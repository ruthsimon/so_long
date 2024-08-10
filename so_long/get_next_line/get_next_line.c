/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:51:15 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/18 22:32:13 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	line = malloc (sizeof(char) * (i + 2));
	if (!line)
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
	return (remain);
}

int	check_free(int words_read, char *store, char *buffer)
{
	if ((words_read == 0 && store == NULL) || (words_read == -1))
	{
		if (words_read == -1)
			free(store);
		free (buffer);
		return (1);
	}
	else
		return (0);
}

char	*check_loop(char *store, int fd)
{
	int		words_read;
	char	*buffer;

	words_read = -1;
	while (words_read != 0 && (!ft_strchr(store, '\n')))
	{
		buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		if (!buffer)
			return (free(store), NULL);
		words_read = read(fd, buffer, BUFFER_SIZE);
		if (check_free (words_read, store, buffer) == 1)
			return (NULL);
		buffer[words_read] = '\0';
		store = ft_strjoin(store, buffer);
		if (!store)
			return (free(buffer), NULL);
		free(buffer);
	}
	return (store);
}

char	*get_next_line(int fd)
{
	char		*final;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE > 2147483647 || BUFFER_SIZE <= 0)
		return (NULL);
	store = check_loop(store, fd);
	if (!store)
		return (free(store), NULL);
	final = separate(store);
	if (!free_static(final, &store))
		return (NULL);
	store = save_left(store);
	return (final);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd = open ("ruth.txt", O_RDONLY);
// 	char *line;
// 	while ((line = get_next_line(fd))!= NULL)
// 	{
// 		printf("%s",line);
// 		free (line);
// 	}
// 	printf("%s",line);
// 	close (fd);
// }
