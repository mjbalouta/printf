/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:58:22 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/04/19 22:58:22 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printdecimal(int num, int count_letters)
{
	char	*ptr;
	int		i;

	ptr = ft_itoa(num);
	i = 0;
	while (ptr[i])
	{
		write (1, &ptr[i], 1);
		i++;
	}
	count_letters += i;
	return (count_letters);
}

int	ft_printunsigned(unsigned int a, int count_letters)
{
	char	*ptr;
	int		i;
	
	//DOESN'T HANDLE NEGATIVE NUMBERS
	i = 0;
	ptr = ft_itoa(a);
	while (ptr[i])
	{
		write (1, &ptr[i], 1);
		i++;
	}
	count_letters += i;
	return (count_letters);
}

int	ft_printhexa(long num, int count_letters, int lowcase)
{
	char	*base;
	char	array[16];
	int		i;
	int		hexa;

	base = "0123456789ABCDEF";
	i = 0;
	if (num < 0)
		num = (num + (1LL << 32));
	if (num == 0)
		write (1, "0", 1);
	while (num > 0)
	{
		hexa = (num % 16);
		if (lowcase == 1 && hexa >= 10)
			array[i] = base[hexa] + 32;
		else
			array[i] = base[hexa];
		i++;
		count_letters++;
		num = num / 16;
	}
	while (--i >= 0)
		write (1, &array[i], 1);
	return (count_letters);
}

int	ft_printaddress(void *p, int count_letters)
{
	long i;
	//COUNT LETTERS ???
	i = (long)p;
	write (1, "0x", 2);
	count_letters = (ft_printhexa(i, count_letters, 1)) / 2;
	return (count_letters);
}