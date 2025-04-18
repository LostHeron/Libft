/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:40:10 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 13:22:22 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_standard.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	int		i;
	char	*res;

	s_len = ft_strlen(s);
	res = ft_malloc((s_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
#include <stdio.h>

static void	check(char const *s, char (*f)(unsigned int, char))
{
	char	*res;

	printf("s = %s\n", s);
	res = ft_strmapi(s, f);
	printf("res = %s\n", res);
}

static char	f1(unsigned int a, char c)
{
	return (a + 'A');
}

static char	f2(unsigned int a, char c)
{
	return (a + c);
}

static char	f3(unsigned int a, char c)
{
	if (a % 2 == 0)
		return ('A');
	else
		return (c);
}

int	main(void)
{
	check("YoLaTeam", &f1);
	check("YoLaTeam", &f2);
	check("YoLaTeam", &f3);
	check("", &f1);
	check("yolateam", NULL);
}
*/
