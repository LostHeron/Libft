/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:52:53 by jweber            #+#    #+#             */
/*   Updated: 2025/10/21 17:08:52 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <unistd.h>

ssize_t	ft_putendl_fd(const char *s, int fd)
{
	ssize_t tmp;
	ssize_t val;

	tmp = ft_putstr_fd(s, fd);
	if (tmp < 0)
		return (tmp);
	val = tmp;
	tmp = ft_putchar_fd('\n', fd);
	if (tmp < 0)
		return (tmp);
	val += tmp;
	return (val);
}
