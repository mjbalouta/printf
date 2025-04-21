/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:56:23 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/04/19 11:56:23 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>
#include <stdio.h>
#include <limits.h>

int	ft_printf(const char *format, ...)
{
	va_list args;
	int		i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				ft_printchar(va_arg(args, int));
			if (format[i] == 's')
				ft_printstring(va_arg(args, char *));
			//if (format[i] == 'p')
			//	ft_printaddress(va_arg(args, void *));
			if (format[i] == 'd' || format[i] == 'i')
				ft_printdecimal(va_arg(args, int));
			if (format[i] == 'u')
				ft_printunsigned(va_arg(args, unsigned int));
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

int main(void)
{
	// char string[] = "maria joao";
	// char c = 'c';
	// int	a = INT_MIN;
	// int b = INT_MAX;
	int e = -5;
	// unsigned int d = 4;
	// ft_printf("custom: a %s estuda\n", string);
	// printf("original: a %s estuda\n", string);
	// ft_printf("custom: %c e %i\n", c, b);
	// printf("original: %c e %i\n", c, b);
	// ft_printf("custom: %d\n", a);
	// printf("original: %d\n", a);
	// ft_printf("custom: %i\n", b);
	// printf("original: %i\n", b);
	ft_printf("custom: %u\n", e);
	printf("original: %u\n", e);
	// ft_printf("custom: %u\n", d);
	// printf("original: %u\n", d);
}