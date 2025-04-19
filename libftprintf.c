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
				ft_printchar((char)(va_arg(args, int)));
			if (format[i] == 's')
				ft_printstring(va_arg(args, char *));
			//if (format[i] == 'p')
			//	ft_printaddress(va_arg(args, void *));
			if (format[i] == 'd' || format[i] == 'i')
				ft_printdecimal(va_arg(args, int));
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
	char string[] = "maria joao";
	char c = 'c';
	int	a = INT_MIN;
	int b = INT_MAX;
	ft_printf("a %s estuda\n", string);
	ft_printf("%c\n", c);
	ft_printf("%d\n", a);
	ft_printf("%i\n", b);
}