/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:15:34 by jweber            #+#    #+#             */
/*   Updated: 2025/05/15 13:26:04 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_standard.h"

char	*ft_strndup(const char *s, ssize_t n)
{
	size_t	l_s;
	size_t	new_n;
	size_t	i;
	char	*s_c;

	if (n < 0)
		return (NULL);
	l_s = ft_strlen(s);
	new_n = (size_t) n;
	if (l_s < new_n)
		s_c = ft_malloc((l_s + 1) * sizeof(char));
	else
		s_c = ft_malloc((n + 1) * sizeof(char));
	if (s_c == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < new_n)
	{
		s_c[i] = s[i];
		i++;
	}
	s_c[i] = '\0';
	return (s_c);
}
