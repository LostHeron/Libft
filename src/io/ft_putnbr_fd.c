/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:52:00 by jweber            #+#    #+#             */
/*   Updated: 2024/12/02 10:10:41 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_fd_recu(int n, int fd, int *i);

int	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	val;

	i = 0;
	val = ft_putnbr_fd_recu(n, fd, &i);
	if (val < 0)
		return (-1);
	else
		return (i);
}

static int	ft_putnbr_fd_recu(int n, int fd, int *i)
{
	if (n == INT_MIN)
	{
		*i = 11;
		if (write(fd, "-2147483648", 11) < 0)
			*i = -1;
		return (*i);
	}
	if (n < 0)
	{
		(*i)++;
		if (ft_putchar_fd('-', fd) < 0)
			return (-1);
		return (ft_putnbr_fd_recu(-n, fd, i));
	}
	if (n > 9)
	{
		if (ft_putnbr_fd_recu(n / 10, fd, i) < 0)
			return (-1);
	}
	(*i)++;
	if (ft_putchar_fd(n % 10 + '0', fd) < 0)
		return (-1);
	return (*i);
}
