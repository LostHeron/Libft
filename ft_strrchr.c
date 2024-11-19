/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:26:47 by jweber            #+#    #+#             */
/*   Updated: 2024/11/19 15:43:03 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_c;
	size_t	i;

	c_c = c;
	i = ft_strlen(s);
	while (i != 0)
	{
		if (s[i] == c_c)
			return ((char *)(s + i));
		i--;
	}
	if (s[i] == c_c)
		return ((char *)(s + i));
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

void static	check(char *s, int to_find)
{
	unsigned long long	addr_init;
	unsigned long long	addr_res_or;
	unsigned long long	addr_res_ft;

	printf("we try to find '%c' in '%s' \n", to_find, s);
	addr_init = (unsigned long long) s;
	printf("addr_init = %llu\n", addr_init);
	addr_res_or = (unsigned long long) strrchr(s, to_find);
	printf("addr_res_or = %llu\n", addr_res_or);
	addr_res_ft = (unsigned long long) ft_strrchr(s, to_find);
	printf("addr_res_ft = %llu\n", addr_res_ft);
	printf("\n");
}

int	main(void)
{
	check("OnEstIciEheh", 'O');
	check("OnEstIciEheh", '\0');
	check("OnEstIciEheh", 'E');
}
*/
