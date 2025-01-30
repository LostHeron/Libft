/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:17:14 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:52:04 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_big;
	size_t	i_little;

	if (ft_strncmp("", little, 1) == 0)
		return ((char *)big);
	i_big = 0;
	while (big[i_big] && i_big < len)
	{
		if (big[i_big] == little[0])
		{
			i_little = 0;
			while (big[i_big + i_little] && little[i_little]
				&& big[i_big + i_little] == little[i_little]
				&& i_big + i_little < len)
				i_little++;
			if (little[i_little] != '\0')
				i_big++;
			else
				return ((char *)(big + i_big));
		}
		else
			i_big++;
	}
	return (NULL);
}

/*
#include <bsd/string.h>
#include <stdio.h>

void static	check(const char *big, const char *little, size_t len)
{
	unsigned long long	addr_or;
	unsigned long long	addr_ft;

	printf("init_addr = %llu\n", (unsigned long long) big);
	addr_ft = (unsigned long long) ft_strnstr(big, little, len);
	addr_or = (unsigned long long) strnstr(big, little, len);
	printf("addr_or = %llu\n", addr_or);
	printf("addr_ft = %llu\n", addr_ft);
	if (addr_or != addr_ft)
		printf("ERREUR !!!\n");
	else
		printf("OK OK / / \n");
	printf("\n");
}

int	main(void)
{
	check("yolateam", "la", 10);
	check("yolateam", "", 10);
	check("yolateam", "yo", 10);
	check("yolateam", "yod", 10);
	check("yolateam", "team", 10);
	check("yolateam", "team", 10);
	check("yolateam", "team", 8);
	check("yolateam", "team", 7);
	check("yolateam", "yo", 2);
	check("yolateam", "team", -1);
	check("aaabcabcd", "aabc", -1);
	check("aaabcabcd", "abcd", 9);
}
*/
