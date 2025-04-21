/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:56:14 by mjoao-fr          #+#    #+#             */
/*   Updated: 2025/04/19 11:56:14 by mjoao-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <stdarg.h>

int     ft_printf(const char *format, ...);

void    ft_printstring(char *string);

void	ft_printchar(int c);

void	ft_printdecimal(int a);

void	ft_printunsigned(unsigned int a);