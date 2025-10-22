/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:01:08 by jweber            #+#    #+#             */
/*   Updated: 2025/10/21 17:27:40 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_io.h"

static ssize_t	iter(int fd, const char *s,
				va_list *pptr, ssize_t (*f[128])(va_list *, ssize_t *, int fd));
static void	init_function_array(ssize_t	(*f[128])(va_list *ptr,
					ssize_t *count, int fd));

ssize_t	ft_printf_fd(int fd, const char *s, ...)
{
	va_list		ptr;
	ssize_t		(*f[128])(va_list *ptr, ssize_t	*count, int fd);
	ssize_t		val;

	if (s == NULL)
		return (-1);
	init_function_array(f);
	f['c'] = &print_c;
	f['s'] = &print_s;
	f['p'] = &print_p;
	f['d'] = &print_i;
	f['i'] = &print_i;
	f['u'] = &print_u;
	f['x'] = &print_x_lower;
	f['X'] = &print_x_upper;
	f['%'] = &print_percent;
	va_start(ptr, s);
	val = iter(fd, s, &ptr, f);
	va_end(ptr);
	return (val);
}

static ssize_t	iter(int fd, const char *s,
				va_list *pptr, ssize_t (*f[128])(va_list *, ssize_t *, int fd))
{
	ssize_t	i;
	ssize_t	i_prev;
	ssize_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		i_prev = i;
		while (s[i] && s[i] != '%')
			i++;
		if (!(i == i_prev))
			write(fd, s + i_prev, (size_t)(i - i_prev));
		if (s[i])
			i++;
		if (f[(int) s[i]] != NULL)
		{
			if (f[(int) s[i]](pptr, &count, fd) < 0)
				return (-1);
			i++;
		}
	}
	return (i + count);
}

static void	init_function_array(ssize_t	(*f[128])(va_list *ptr,
				ssize_t *count, int fd))
{
	int	i;

	i = 0;
	while (i < 128)
	{
		f[i] = NULL;
		i++;
	}
}
