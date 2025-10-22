/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:33:01 by jweber            #+#    #+#             */
/*   Updated: 2025/10/21 17:19:39 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <stdarg.h>
#include <unistd.h>

ssize_t	print_percent(va_list *ptr, ssize_t *count, int fd)
{
	ssize_t	val;

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

ssize_t	print_x_lower(va_list *ptr, ssize_t *count, int fd)
{
	int		a;
	ssize_t	val;

	(void) count;
	a = va_arg(*ptr, int);
	val = ft_putnbr_base_u_fd((unsigned int) a, "0123456789abcdef", fd);
	if (val < 0)
		return (-1);
	else
	{
		*count += val - 2;
		return (val);
	}
}

ssize_t	print_x_upper(va_list *ptr, ssize_t *count, int fd)
{
	int		a;
	ssize_t	val;

	a = va_arg(*ptr, int);
	val = ft_putnbr_base_u_fd((unsigned int)a, "0123456789ABCDEF", fd);
	if (val < 0)
		return (-1);
	else
	{
		(*count) += val - 2;
		return (val);
	}
	return (0);
}
