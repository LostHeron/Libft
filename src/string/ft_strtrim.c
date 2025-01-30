/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:40:18 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:52:16 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static int	in_charset(char c, char const *set);
static int	nb_left(char const *s1, char const *set);
static int	nb_right(char const *s1, char const *set, int s1_len);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s1_len;
	int		nb_char_l;
	int		nb_char_r;
	int		i;
	char	*res;

	s1_len = ft_strlen(s1);
	nb_char_l = nb_left(s1, set);
	nb_char_r = nb_right(s1, set, s1_len);
	if (s1_len - nb_char_r - nb_char_l <= 0)
		return (ft_calloc(1, sizeof(char)));
	res = malloc((s1_len - nb_char_r - nb_char_l + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (nb_char_l + i < s1_len - nb_char_r)
	{
		res[i] = s1[nb_char_l + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	in_charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	nb_left(char const *s1, char const *set)
{
	int	nb_char_l;

	nb_char_l = 0;
	while (s1[nb_char_l]
		&& in_charset(s1[nb_char_l], set) == 0)
	{
		nb_char_l++;
	}
	return (nb_char_l);
}

static int	nb_right(char const *s1, char const *set, int s1_len)
{
	int	nb_char_r;

	nb_char_r = 0;
	while (nb_char_r < s1_len
		&& in_charset(s1[s1_len - 1 - nb_char_r], set) == 0)
		nb_char_r++;
	return (nb_char_r);
}

/*
#include <stdio.h>

static void check(char const *s1, char const *set)
{
	char	*res;

	printf("s1 = '%s'\n", s1);
	printf("set = '%s'\n", set);
	res = ft_strtrim(s1, set);
	printf("res = '%s'\n", res);
	free(res);
	printf("\n");
}

int	main(void)
{
	check("         yo la team        ", " ");
	check("+++yo la team+++", "+");
	check("+++++++++yo+la+team++++++++", "+");
	check("+++++++++++++++++++++++yo+la+team+++++++++++++++++++++++", "+");
	check("++++++++++++++++++yo+la+team++++++++++++++++++++++", "+");
	check(" +//!!yo+la+team ", " /+!");
	check(" +//!!  yo+la+team ", " /+!");
	check(" +//y !!  yo+la+team ", " /+!");
	check("", " /+!");
	check(" +//y !!  yo+la+team ", "");
	check("", "");
}
*/
