/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 01:04:17 by rsimon            #+#    #+#             */
/*   Updated: 2023/08/31 23:37:44 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	print_char(char c);
int	print_string(char *s);
int	print_pointer(unsigned long long int nbr);
int	print_dec(int deci);
int	print_unsigned(unsigned int num);
int	print_hexlow(unsigned int num);
int	print_hexupp(unsigned int num);
int	ft_printf(const char *str, ...);

#endif
