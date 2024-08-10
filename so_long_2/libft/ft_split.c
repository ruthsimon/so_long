/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:06:58 by rsimon            #+#    #+#             */
/*   Updated: 2024/03/18 15:51:13 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s[x] == c)
		x++;
	while (s[x])
	{
		if ((s[x] == c && s[x + 1] != c) || s[x + 1] == '\0')
		{
			y++;
		}
		x++;
	}
	return (y);
}

static int	free_siem(char **arr, int k)
{
	if (arr[k - 1] == NULL)
	{
		while (k > 0)
		{
			free(arr[k - 1]);
			k--;
		}
		return (1);
	}
	return (0);
}

static int	array_filler(char **arr, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] == c)
			i++;
		else
		{
			while ((s[i + j] != c) && s[i + j])
				j++;
			arr[k++] = (char *)malloc(sizeof(char) * (j + 1));
			if (free_siem(arr, k) == 1)
				return (1);
			ft_strlcpy(arr[k - 1], s + i, (j + 1));
		}
		i = i + j;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		words;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
		words = 0;
	else
		words = count_words(s, c);
	buffer = (char **)malloc(sizeof(char *) * (words + 1));
	if (buffer == NULL)
		return (NULL);
	if (array_filler(buffer, s, c) == 1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[words] = NULL;
	return (buffer);
}

// int main ()
// {

// 	// char *str = "World";
// 	char **buffer = ft_split("", 0);
// 	int i = 0;
// 	while (buffer[i])
// 	{
// 		printf("%s", buffer[i]);
// 	}
// 	return (0);
// }

// int main ()
// {
//     char x[]= "___ruth_simon_tekle_kahsay";
//     char c= '_';
//     char **result = ft_split(x, c);
// 	int i = 0;
// 	while (result[i] != NULL)
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
//     //printf("it is %i", y);
// 	return (0);
// }