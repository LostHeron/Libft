/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:30:05 by jweber            #+#    #+#             */
/*   Updated: 2025/10/21 17:02:52 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_standard.h"

size_t ft_countwords(char const *s, char *charset)
{
	size_t	i;
	size_t	nb_words;

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
