/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:50:48 by jweber            #+#    #+#             */
/*   Updated: 2025/10/23 10:54:10 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

void	fill_str(unsigned long long nb, char *str, size_t i);

#define BIT_PER_BYTE 8

ssize_t	print_binary(int fd, unsigned long long *a, size_t size_of_var)
{
	unsigned long	nb;
	char		str[256];

	if (size_of_var > sizeof(unsigned long long))
		size_of_var = sizeof(unsigned long long);
	nb = *a;
	fill_str(nb, str, size_of_var * BIT_PER_BYTE - 1);
	str[size_of_var * BIT_PER_BYTE] = '\n';
	return (write(fd, str, size_of_var * BIT_PER_BYTE + 1));
}

void	fill_str(unsigned long long nb, char *str, size_t i)
{
	if (i >= 1)
	{
		fill_str(nb / 2, str, i - 1);
	}
	str[i] = nb % 2 + '0';
	return ;
}
