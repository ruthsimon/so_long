/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:31:41 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/18 21:29:02 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		len;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL )
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	joined = malloc((len + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		joined[i++] = s2 [j++];
	joined[i] = '\0';
	return (joined);
}

// int main()
// {
//     char a[]= "ruth";
//     char b[]= "simon";

//     char *j;

//     j = ft_strjoin(a,b);
//     printf("the joined string is %s", j);
// }