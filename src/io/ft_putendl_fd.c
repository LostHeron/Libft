/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:52:53 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:47:40 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

int	ft_putendl_fd(const char *s, int fd)
{
	int	tmp;
	int	val;

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
