/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:31:38 by jweber            #+#    #+#             */
/*   Updated: 2024/11/22 12:47:14 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
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
