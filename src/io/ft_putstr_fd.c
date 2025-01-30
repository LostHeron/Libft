/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:47:24 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:48:05 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	val;

	val = write(fd, s, ft_strlen(s));
	if (val < 0)
		return (-1);
	else
		return (val);
}
