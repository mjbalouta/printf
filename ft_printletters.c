/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printletters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:58:30 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/04/19 22:58:30 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_printstring(char *str, int count_letters)
{
    ft_putstr_fd(str, 1);
	count_letters++;
}
void	ft_printchar(int c, int count_letters)
{
	write(1, &c, 1);
	count_letters++;
}