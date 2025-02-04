/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:01:08 by jweber            #+#    #+#             */
/*   Updated: 2025/02/04 13:53:01 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static int	iter(int fd, const char *s,
				va_list *pptr, int (*f[128])(va_list *, int *, int fd));
static void	init_function_array(int (*f[128])(va_list *ptr, int *count, int fd));
int	print_c(va_list *ptr, int *count, int fd);
int	print_p(va_list *ptr, int *count, int fd);
int	print_i(va_list *ptr, int *count, int fd);
int	print_p(va_list *ptr, int *count, int fd);
int	print_s(va_list *ptr, int *count, int fd);
int	print_u(va_list *ptr, int *count, int fd);
int	print_percent(va_list *ptr, int *count, int fd);
int	print_x_lower(va_list *ptr, int *count, int fd);
int	print_x_upper(va_list *ptr, int *count, int fd);

int	ft_printf_fd(int fd, const char *s, ...)
{
	va_list		ptr;
	int			(*f[128])(va_list *ptr, int *count, int fd);
	int			val;

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

static int	iter(int fd, const char *s,
				va_list *pptr, int (*f[128])(va_list *, int *, int fd))
{
	int	i;
	int	i_prev;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		i_prev = i;
		while (s[i] && s[i] != '%')
			i++;
		if (!(i == i_prev))
			write(fd, s + i_prev, i - i_prev);
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

static void	init_function_array(int (*f[128])(va_list *ptr, int *count, int fd))
{
	int	i;

	i = 0;
	while (i < 128)
	{
		f[i] = NULL;
		i++;
	}
}

