/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:35:15 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 13:23:45 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_standard.h"

char	*ft_strdup(const char *s)
{
	size_t	l_s;
	size_t	i;
	char	*s_c;

	l_s = ft_strlen(s);
	s_c = ft_malloc((l_s + 1) * sizeof(char));
	if (s_c == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_c[i] = s[i];
		i++;
	}
	s_c[i] = '\0';
	return (s_c);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*a;

	a = ft_strdup("yo la team");
	printf("a = %s\n", a);
	a = ft_strdup(NULL);
	printf("a = %s\n", a);
}
*/
