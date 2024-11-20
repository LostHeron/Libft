/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:23:14 by jweber            #+#    #+#             */
/*   Updated: 2024/11/20 14:54:17 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_c;
	unsigned char	*s2_c;
	size_t			i;

	s1_c = (unsigned char *) s1;
	s2_c = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1)
	{
		if (s1_c[i] != s2_c[i])
			return (s1_c[i] - s2_c[i]);
		i++;
	}
	return (s1_c[i] - s2_c[i]);
}

/*
#include <string.h>
#include <stdio.h>

void static	check(const void *s1, const void *s2, size_t n)
{
	int	res_or;
	int	res_ft;

	res_or = ft_memcmp(s1, s2, n);
	res_ft = memcmp(s1, s2, n);
	printf("res_or = %i\n", res_or);
	printf("res_ft = %i\n", res_ft);
	if (res_or != res_ft)
		printf("ERREUR !!!!\n");
	else
		printf("OK OK / / \n");
	printf("\n");
}

int	main(void)
{
	int arr1[2];
	int arr2[2];

	arr1[0] = 2145620124;
	arr1[1] = -2145620124;
	arr2[0] = -2145620124;
	arr2[1] = -2145620124;
	check("YoLaTeam", "YoLaTeam", 8);
	check("YoLaTea", "YoLaTeam", 8);
	check("YoLaTeam", "YoLaTea", 8);
	check(arr1, arr2, 8);
	check("", "", 0);
	check("coucou", "yo mec", 0);
	check("coucouLaBasToi", "coucouYoMec", 5);
	check("coucouLaBasToi", "coucouYoMec", 6);
	check("coucouLaBasToi", "coucouYoMec", 7);
	check("coucouLaBasToi", "coucouYoMec", 8);
	check("coucouLaBasToi", "coucouYoMec", -1);
	check("coucouL", "coucouY", -1);
	check("coucouL", "coucouY", 6);
}
*/
