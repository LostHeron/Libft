/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:22:29 by jweber            #+#    #+#             */
/*   Updated: 2025/10/21 17:24:33 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

ssize_t	print_c(va_list *ptr, int *count, int fd)
{
	int		c;
	ssize_t	val;

	c = va_arg(*ptr, int);
	val = ft_putchar_fd((char)c, fd);
	if (val < 0)
		return (-1);
	else
	{
		(*count) += val - 2;
		return (val);
	}
}

ssize_t	print_i(va_list *ptr, int *count, int fd)
{
	int		c;
	ssize_t	val;

	c = va_arg(*ptr, int);
	val = ft_putnbr_fd(c, fd);
	if (val < 0)
		return (-1);
	else
	{
		*count += val - 2;
		return (val);
	}
}

ssize_t	print_p(va_list *ptr, int *count, int fd)
{
	unsigned long long	a;
	ssize_t				val;

	a = (unsigned long long) va_arg(*ptr, void *);
	if (a == 0)
	{
		val = ft_putstr_fd("(nil)", fd);
		if (val < 0)
			return (-1);
		*count += val - 2;
		return (*count);
	}
	val = ft_putstr_fd("0x", fd);
	if (val < 0)
		return (-1);
	else
		*count += val;
	val = ft_putnbr_base_ull_fd(a, "0123456789abcdef", fd);
	if (val < 0)
		return (-1);
	else
		*count += val - 2;
	return (val);
}

ssize_t	print_s(va_list *ptr, int *count, int fd)
{
	char	*str;
	ssize_t	val;

	str = va_arg(*ptr, char *);
	if (str == NULL)
	{
		val = ft_putstr_fd("(null)", fd);
		if (val < 0)
			return (-1);
		else
		{
			*count += val - 2;
			return (val);
		}
	}
	val = ft_putstr_fd(str, fd);
	if (val < 0)
		return (-1);
	else
	{
		*count += val - 2;
		return (val);
	}
}

ssize_t	print_u(va_list *ptr, int *count, int fd)
{
	int		c;
	ssize_t	val;

	c = va_arg(*ptr, int);
	val = ft_putunbr_fd((unsigned int)c, fd);
	if (val < 0)
		return (-1);
	else
	{
		*count += val - 2;
		return (val);
	}
	return (1);
}
