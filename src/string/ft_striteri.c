/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:31:38 by jweber            #+#    #+#             */
/*   Updated: 2025/10/21 17:00:59 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f((unsigned int)i, s + i);
		i++;
	}
	return ;
}

/*
#include <stdio.h>

void	replace_space_underscore(unsigned int c, char *s)
{
	if (*s == ' ')
		*s = '_';
	return ;
}

static void	check(char *s, void (*f)(unsigned int, char *))
{
	printf("AVANT transfo : \n");
	printf("s = %s\n", s);
	ft_striteri(s, f);
	printf("APRES transfo : \n");
	printf("s = %s\n", s);
}

int	main(void)
{
	char str[] = "Yo la team";

	check(str, &replace_space_underscore);
	return (0);
}
*/
