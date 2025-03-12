/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:33:01 by jweber            #+#    #+#             */
/*   Updated: 2025/02/04 14:04:28 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <stdarg.h>

int	print_percent(va_list *ptr, int *count, int fd)
{
	int	val;

	(void) *ptr;
	val = ft_putchar_fd('%', fd);
	if (val < 0)
		return (-1);
	else
	{
		(*count) += val - 2;
		return (val);
	}
	return (0);
}

int	print_x_lower(va_list *ptr, int *count, int fd)
{
	int	a;
	int	val;

	(void) count;
	a = va_arg(*ptr, int);
	val = ft_putnbr_base_u_fd(a, "0123456789abcdef", fd);
	if (val < 0)
		return (-1);
	else
	{
		*count += val - 2;
		return (val);
	}
}

int	print_x_upper(va_list *ptr, int *count, int fd)
{
	int	a;
	int	val;

	a = va_arg(*ptr, int);
	val = ft_putnbr_base_u_fd(a, "0123456789ABCDEF", fd);
	if (val < 0)
		return (-1);
	else
	{
		(*count) += val - 2;
		return (val);
	}
	return (0);
}
