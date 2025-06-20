/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_second.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:13:00 by jweber            #+#    #+#             */
/*   Updated: 2025/06/20 17:14:30 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_standard.h"

char	*ft_strjoin_free_second(char const *s1, char const *s2)
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
	free((void *)s2);
	return (res);
}
