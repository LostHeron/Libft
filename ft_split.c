/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:25:18 by jweber            #+#    #+#             */
/*   Updated: 2024/11/21 14:23:28 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	free_prev(char **res)//, int i_word)
{
	int	i;

	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return ;
}

char	**ft_split(char const *s, char c)
{
	int		nb_words;
	int		i_word;
	int		i;
	int		j;
	char	**res;

	nb_words = ft_countwords(s, c);
	res = ft_calloc(nb_words + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	i_word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (s[i])
		{
			res[i_word] = malloc((j + 1) * sizeof(char));
			if (res[i_word] == NULL)
			{
				free_prev(res);
				return (NULL);
			}
			j = 0;
			while (s[i + j] && s[i + j] != c)
			{
				res[i_word][j] = s[i + j];
				j++;
			}
			res[i_word][j] = '\0';
			i += j;
			i_word += 1;
		}
	}
	return (res);
}

/*
#include <stdio.h>

void static	check(const char *s, char c)
{
	char	**res;
	int		i;

	printf("s = \"%s\"\n", s);
	printf("s = '%c'\n", c);
	printf("res : \n");
	res = ft_split(s, c);
	if (res == NULL)
	{
		printf("\n\nERREUR in allocation in ft_split\n");
		printf("end of program\n");
		return ;
	}
	i = 0;
	while (res[i] != NULL)
	{
		printf(" - '%s'\n", res[i]);
		i++;
	}
	free_prev(res);//, ft_countwords(s, c));
	printf("\n");
	return ;
}

int	main(void)
{
	check("yo la team", ' ');
	check("      yo       la     team   ", ' ');
	check("           ", ' ');
	check("", ' ');
	//check(NULL, ' ');
	check("?", ' ');
	check("  ?  ", ' ');
	check("yo la team      bien        ou quoi         la       ? ", ' ');
}
*/
