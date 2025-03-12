/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:22:31 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:51:59 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	uc1;
	unsigned char	uc2;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		uc1 = s1[i];
		uc2 = s2[i];
		if (uc1 != uc2)
			return (uc1 - uc2);
		i++;
	}
	uc1 = s1[i];
	uc2 = s2[i];
	return (uc1 - uc2);
}

/*
#include <stdio.h>
#include <string.h>

void static	check(const char *s1, const char *s2, size_t n)
{
	int	res_ft;
	int	res_or;

	printf("Comparaison : '%s' avec '%s' sur '%zu' charactere\n", s1, s2, n);
	res_ft = ft_strncmp(s1, s2, n);
	printf("res_ft = %i\n", res_ft);
	res_or = strncmp(s1, s2, n);
	printf("res_or = %i\n", res_or);
	if (res_ft != res_or)
		printf("ERREUR !!!\n");
	else
		printf("-> OK OK \n");
	printf("\n");
	return ;
}

int	main(void)
{
	check("Yo la team", "Yo la team", 10);
	check("Yo la team", "Yo la team", 2);
	check("", "", 2);
	//check(NULL, NULL, 2);
	check("YoLaPasTeam", "YoLaTeam", 4);
	check("YoLaPasTeam", "YoLaTeam", 6);
	check("zyx", "abc", 3);
	check("zyx", "abc", 0);
	check("\x12\xff\x65\x12\xbd\xde\xad", "\x12\xff\x65\x12\xbd\xde\xad", 0);
	check("\x12\xff\x65\x12\xbd\xde\xad", "\x12\x02", 2);
}
*/
