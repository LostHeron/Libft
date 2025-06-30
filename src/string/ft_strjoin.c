/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:24:10 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 13:23:15 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_standard.h"

static char	*case_none_null(char const *s1, char const *s2);
static char	*case_first_null(char const *s2);
static char	*case_second_null(char const *s1);

char	*ft_strjoin_free_first(char const *s1, char const *s2)
{
	char	*res;

	if (s1 == NULL && s2 == NULL)
	{
		res = ft_malloc(1 * sizeof(char));
		return (res);
	}
	else if (s1 == NULL)
	{
		return (case_first_null(s2));
	}
	else if (s2 == NULL)
	{
		return (case_second_null(s1));
	}
	else
	{
		return (case_none_null(s1, s2));
	}
}

static char	*case_first_null(char const *s2)
{
	size_t	s2_len;
	size_t	i;
	char	*res;

	s2_len = ft_strlen(s2);
	res = ft_malloc((s2_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < s2_len)
	{
		res[i] = s2[i];
		i++;
	}
	return (res);
}

static char	*case_second_null(char const *s1)
{
	size_t	s1_len;
	size_t	i;
	char	*res;

	s1_len = ft_strlen(s1);
	res = ft_malloc((s1_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	*case_none_null(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*res;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = ft_malloc((s1_len + s2_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		res[i] = s2[i - s1_len];
		i++;
	}
	res[i] = '\0';
	return (res);
}
