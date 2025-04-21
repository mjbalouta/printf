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

void	ft_printdecimal(int a, int count_letters)
{
	ft_putnbr_fd(a, 1);
	count_letters++;
}

void	ft_printunsigned(unsigned int a, int count_letters)
{
		write(1, &a, 4);
		count_letters++;
}