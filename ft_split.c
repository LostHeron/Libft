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

static void	free_prev(char **res)//, int i_word)
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

static void	f1(const char *s, char c, int *i, int *j)
{
	while (s[*i] && s[*i] == c)
		(*i)++;
	*j = 0;
	while (s[*i + *j] && s[*i + *j] != c)
		(*j)++;
}

static int	f2(char **res, int i_word, int j)
{
	res[i_word] = malloc((j + 1) * sizeof(char));
	if (res[i_word] == NULL)
	{
		free_prev(res);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i_word;
	int		i;
	int		j;
	char	**res;

	res = ft_calloc(ft_countwords(s, c) + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	i_word = 0;
	while (s[i])
	{
		f1(s, c, &i, &j);
		if (s[i] == '\0')
			return (res);
		if (f2(res, i_word, j) == 1)
			return (NULL);
		j = -1;
		while (s[i + ++j] && s[i + j] != c)
			res[i_word][j] = s[i + j];
		res[i_word][j] = '\0';
		i += j;
		i_word += 1;
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
	free_prev(res);
	printf("\n");
	return ;
}

int	main(void)
{
	check("yo la team", ' ');
	check("      yo       la     team   ", ' ');
	check("           ", ' ');
	check("", ' ');
	check("?", ' ');
	check("  ?  ", ' ');
	check("yo la team      bien        ou quoi         la       ? ", ' ');
}
*/
