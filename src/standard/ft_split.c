/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:25:18 by jweber            #+#    #+#             */
/*   Updated: 2025/10/21 17:02:36 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "ft_string.h"

static int	fill_res_i(const char *s, int i, int len_word, char **res_i);
static void	*free_all(char **args);

char	**ft_split(char const *s, const char *charset)
{
	int		word_i;
	int		i;
	int		len_word;
	char	**res;

	res = ft_calloc(ft_countwords(s, charset) + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	word_i = -1;
	while (s[i])
	{
		while (s[i] && ft_strchr(charset, s[i]) != NULL)
			i++;
		if (s[i] && ft_strchr(charset, s[i]) == NULL)
			word_i++;
		len_word = 0;
		while (s[i + len_word] && ft_strchr(charset, s[i + len_word]) == NULL)
			len_word++;
		if (len_word != 0)
			if (fill_res_i(s, i, len_word, &(res[word_i])) == 1)
				return (free_all(res));
		i = i + len_word;
	}
	return (res);
}

static int	fill_res_i(const char *s, int i, int len_word, char **res_i)
{
	int	k;

	*res_i = ft_malloc((unsigned long)(len_word + 1) * sizeof(char));
	if (*res_i == NULL)
		return (1);
	k = 0;
	while (k < len_word)
	{
		(*res_i)[k] = s[i + k];
		k++;
	}
	(*res_i)[k] = '\0';
	return (0);
}

static void	*free_all(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (NULL);
}

/*
#include <stdio.h>

void static	check(const char *s, char *c)
{
	char	**res;
	int		i;

	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("s = \"%s\"\n", s);
	printf("s = '%s'\n", c);
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
	free_all(res);
	printf("\n");
	return ;
}

int	main(void)
{
	check("yo la \n\nteam\n", " \n\t\r\n\t ");
	check("      yo       la     team   ", " ");
	check("           ", " ");
	check("", " ");
	check("?", " ");
	check("  ?  ", " ");
	check("yo la team      bien        ou quoi         la       ? ", " ");
}
*/
