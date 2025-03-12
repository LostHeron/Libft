/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:18:28 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 13:22:30 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_standard.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*res;
	size_t	malloc_size;

	s_len = ft_strlen(s);
	if (!(start > s_len - 1 || s_len == 0))
	{
		if (s_len - start < len)
			malloc_size = s_len - start;
		else
			malloc_size = len;
		res = ft_malloc((malloc_size + 1) * sizeof(char));
		if (res == NULL)
			return (NULL);
		i = -1;
		while (s[start + ++i] && i < malloc_size)
			res[i] = s[start + i];
		res[i] = '\0';
	}
	else
		return (ft_calloc(1, sizeof(char)));
	return (res);
}

/*
#include <stdio.h>

static void	check(char const *s, unsigned int start, size_t len)
{
	char	*res;

	printf("ON RESET TEST \n");
	printf("start = %u\n", start);
	printf("len = %zu\n", len);
	printf("s = %s\n", s);
	res = ft_substr(s, start, len);
	printf("res = %s\n", res);
	free(res);
	printf("\n");
}

int	main(void)
{
	check("YoLaTam", 0, 20);
	check("yoLaTeam", 2, 20);
	check("yoLaTeam", 2, 20);
	check("yoLaTeam", 2, 2);
	check("", 2, 2);
	check("yoLaTeam", 2, 2);
	check("01234", 10, 10);
	check("hola", 4294967295, 0);
	check("0123456789", 9, 10);
	check("", 1, 1);
}
*/
