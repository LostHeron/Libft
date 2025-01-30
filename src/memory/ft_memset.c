/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:31:49 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:49:49 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*s_c;

	s_c = s;
	i = 0;
	while (i < n)
	{
		*(s_c + i) = c;
		i++;
	}
	return ((void *) s);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char s[] = "ldkjfmqjf";
	ft_memset(NULL, 0, 3);
}
*/
