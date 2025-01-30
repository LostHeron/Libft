/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:01:42 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:49:18 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc_c;
	char			*s_c;
	unsigned char	uc_s;
	size_t			i;

	s_c = (char *)s;
	uc_c = c;
	i = 0;
	while (i < n)
	{
		uc_s = s_c[i];
		if (uc_s == uc_c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

void static	check(const void *s, int c, size_t n)
{
	unsigned long long	res_ft;
	unsigned long long	res_or;

	res_ft = (unsigned long long) ft_memchr(s, c, n);
	res_or = (unsigned long long) memchr(s, c, n);
	printf("addr_init = %llu\n", (unsigned long long) s);
	printf("res_ft = %llu\n", res_ft);
	printf("res_or = %llu\n", res_or);
	if (res_ft != res_or)
		printf("ERREUR !!!!! \n");
	else
		printf("OK OK / / \n");
	printf("\n");
}

int	main(void)
{
	int		arr[] = {202182159, 0, 0};
	void	*s;
	// 202182159 
	// = 00001100_00001101_00001110_00001111
	// = 12_13_14_15
	// but little endian so 15 first then 14 then 13 then 12
	check(arr, 12, 3 * sizeof(int));
	check(arr, -20, 3 * sizeof(int));
	check(arr, 202182159, 3 * sizeof(int));
	printf("la fin \n");
	//s = memchr(NULL, 3, 3);
}
*/
