/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:30:05 by jweber            #+#    #+#             */
/*   Updated: 2024/11/21 14:08:12 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	ft_countwords(char const *s, char *charset)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(charset, s[i]) != NULL)
			i++;
		if (s[i] && ft_strchr(charset, s[i]) == NULL)
			nb_words++;
		while (s[i] && ft_strchr(charset, s[i]) == NULL)
			i++;
	}
	return (nb_words);
}

/*
#include <stdio.h>

void static	check(char const *s, char c)
{
	int	nb_words;

	printf("s = \"%s\"\n", s);
	printf("c = '%c'\n", c);
	nb_words = ft_countwords(s, c);
	printf("nb_words = '%i'\n", nb_words);
	printf("\n");
}

int	main(void)
{
	check("yo la team", ' ');
	check("     yo   la   team   ", ' ');
	check("      ", ' ');
	check("", ' ');
	check("", ' ');
	check("yolateam", ' ');
	check("     yolateam", ' ');
	check("yolateam    ", ' ');
	check("Yo La Team      ", ' ');
	check("       Yo La Team", ' ');
}
*/
