/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:47:09 by jweber            #+#    #+#             */
/*   Updated: 2024/12/02 13:47:29 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putunbr_fd_recu(unsigned int n, int fd, int *i);

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	i;

	i = 0;
	return (ft_putunbr_fd_recu(n, fd, &i));
}

static int	ft_putunbr_fd_recu(unsigned int n, int fd, int *i)
{
	if (n > 9)
	{
		if (ft_putunbr_fd_recu(n / 10, fd, i) < 0)
			return (-1);
	}
	(*i)++;
	if (ft_putchar_fd(n % 10 + '0', fd) < 0)
		return (-1);
	else
		return (*i);
}
