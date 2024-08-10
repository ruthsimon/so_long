/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:00:05 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/19 20:49:06 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// Example function to print the index and character
// void transform_char(unsigned int index, char *c) {
//     *c = *c + index;
// }

// int main() {
//     char input_string[] = "Hello, World!";
//     printf("Original string: %s\n", input_string);

//     ft_striteri(input_string, &transform_char);
//     printf("New string: %s\n", input_string);

//     return 0;
// }