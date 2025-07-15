/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:52:13 by jweber            #+#    #+#             */
/*   Updated: 2025/07/15 17:54:46 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i_big;
	size_t	i_little;

	if (ft_strncmp("", little, 1) == 0)
		return ((char *)big);
	i_big = 0;
	while (big[i_big])
	{
		if (big[i_big] == little[0])
		{
			i_little = 0;
			while (big[i_big + i_little] && little[i_little]
				&& big[i_big + i_little] == little[i_little])
				i_little++;
			if (little[i_little] != '\0')
				i_big++;
			else
				return ((char *)(big + i_big));
		}
		else
			i_big++;
	}
	return (NULL);
}
