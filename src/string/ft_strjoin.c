/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:24:10 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 13:23:15 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "standard.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*res;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = ft_malloc((s1_len + s2_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		res[i] = s1[i];
	i--;
	while (++i < s1_len + s2_len)
		res[i] = s2[i - s1_len];
	res[i] = '\0';
	return (res);
}

/*
#include <stdio.h>

static void	check(char const *s1, char const *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	printf("res = %s\n", res);
	printf("\n");
	free(res);
}

int	main(void)
{
	check("Yo", "LaTeam");
	check("", "");
	check("qspifjqsdf", "");
	check("qspifjqsdf", "ehehmongars");

	void	*a;
	a = NULL;
	check(a + 1, "yo");
}
*/
