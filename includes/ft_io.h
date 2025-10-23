/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:33:14 by jweber            #+#    #+#             */
/*   Updated: 2025/10/23 10:52:32 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <sys/types.h>
# include <stdarg.h>

ssize_t	print_binary(int fd, unsigned long long *a, size_t size_of_var);
ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putstr_fd(const char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putunbr_fd(unsigned int n, int fd);
ssize_t	ft_putendl_fd(const char *s, int fd);
ssize_t	ft_putnbr_base_u_fd(unsigned int nbr, const char *base, int fd);
ssize_t	ft_putnbr_base_ull_fd(unsigned long long nbr, const char *base, int fd);
ssize_t	print_c(va_list *ptr, ssize_t *count, int fd);
ssize_t	print_i(va_list *ptr, ssize_t *count, int fd);
ssize_t	print_p(va_list *ptr, ssize_t *count, int fd);
ssize_t	print_s(va_list *ptr, ssize_t *count, int fd);
ssize_t	print_u(va_list *ptr, ssize_t *count, int fd);
ssize_t	print_percent(va_list *ptr, ssize_t *count, int fd);
ssize_t	print_x_lower(va_list *ptr, ssize_t *count, int fd);
ssize_t	print_x_upper(va_list *ptr, ssize_t *count, int fd);
ssize_t	ft_printf_fd(int fd, const char *s, ...);
/*
 * values of *err_code :
 *	- '0'	: correct behaviour
 *	- '-1'	: read error
 *	- '-3'	: malloc error
*/
char	*get_next_line(int fd, int *err_code);

#endif
