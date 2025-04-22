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

//COUNT_LETTERS ESTÁ ERRADO

int	ft_printf(const char *format, ...)
{
	va_list args;
	int		i;
	int		count_letters;
	int		lowcase;

	va_start(args, format);
	i = 0;
	count_letters = 0;
	while (format[i])
	{
		lowcase = 0;
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count_letters = ft_printchar(va_arg(args, int), count_letters);
			else if (format[i] == 's')
				count_letters = ft_printstring(va_arg(args, char *), count_letters);
			else if (format[i] == 'p')
				count_letters = ft_printaddress(va_arg(args, void *), count_letters);
			else if (format[i] == 'd' || format[i] == 'i')
				count_letters = ft_printdecimal(va_arg(args, long), count_letters);
			else if (format[i] == 'u')
				count_letters = ft_printunsigned(va_arg(args, unsigned int), count_letters);
			else if (format[i] == 'x')
			{
				lowcase = 1;
				count_letters = ft_printhexa(va_arg(args, long), count_letters, lowcase);
			}
			else if (format[i] == 'X')
				count_letters = ft_printhexa(va_arg(args, long), count_letters, lowcase);
			else if (format[i] == '%')
			{
				count_letters++;
				write (1, "%", 1);
			}
		}
		else
		{
			write(1, &format[i], 1);
			count_letters++;
		}
		i++;
	}
	va_end(args);
	return (count_letters);
}

int main(void)
{
	char string[] = "maria joao";
	char c = 'c';
	int	a = INT_MIN;
	int b = INT_MAX;
	int e = -5;
	unsigned int d = 26;
	int	result;
	int original;
	char str[] = "a %%maria";
	int *ptr = &a;
	
	printf("%%s TEST:\n");
	result = ft_printf("c: a %s estuda\n", string);
	original = printf("o: a %s estuda\n", string);
	printf("printed %d characters.\n", result);
	printf("printed %d characters.\n", original);
	
	printf("\n%%c TEST:\n");
	result = ft_printf("c: %c e %i\n", c, b);
	original = printf("o: %c e %i\n", c, b);
	printf("printed %d characters.\n", result);
	printf("printed %d characters.\n", original);
	
	printf("\n%%d TEST:\n");
	result = ft_printf("c: %d\n", a);
	original = printf("o: %d\n", a);
	printf("printed %d characters.\n", result);
	printf("printed %d characters.\n", original);
	
	printf("\n%%i TEST:\n");
	result = ft_printf("c: %i\n", b);
	original = printf("o: %i\n", b);
	printf("printed %d characters.\n", result);
	printf("printed %d characters.\n", original);

	printf("\n%%u TEST:\n");
	result = ft_printf("c: %u\n", e);
	original = printf("o: %u\n", e);
	printf("printed %d characters.\n", result);
	printf("printed %d characters.\n", original);
	result = ft_printf("c: %u\n", d);
	original = printf("o: %u\n", d);
	printf("printed %d characters.\n", result);
	printf("printed %d characters.\n", original);

	printf("\n%%X AND %%x TEST:\n");
	result = ft_printf("c: %x\n", d);
	original = printf("o: %x\n", d);
	printf("printed %d characters.\n", result);
	printf("printed %d characters.\n", original);
	result = ft_printf("c: %X\n", d);
	original = printf("o: %X\n", d);
	printf("printed %d characters.\n", result);
	printf("printed %d characters.\n", original);
	
	printf("\n%% TEST:\n");
	result = ft_printf("c: %s\n", str);
	printf("o: %s\n", str);
	printf("printed %d characters.\n", result);
	printf("printed %d characters.\n", original);

	printf("\n%%p TEST:\n");
	result = ft_printf("c: %p\n", ptr);
	printf("o: %p\n", ptr);
	printf("printed %d characters.\n", result);
	printf("printed %d characters.\n", original);

}