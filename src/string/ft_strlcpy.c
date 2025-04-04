/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:11:44 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:51:42 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

/*
#include <string.h>
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	const char *src = "CommentEstCeQueCaVaToi?";
	char *ici = "yo";
	int	string_size = 0;

	char	*dst_or = malloc(string_size * sizeof(char));
	size_t	l_dst_or;
	char	*dst_ft = malloc(string_size * sizeof(char));
	size_t	l_dst_ft;

	// dst_or = NULL;
	// dst_ft = NULL;

	printf("ici = %s\n", ici);

	l_dst_or = strlcpy(dst_or, src, string_size);
	printf("l_dst_or = %zu\n", l_dst_or);
	printf("dst_or = %s\n", dst_or);

	l_dst_ft = ft_strlcpy(dst_ft, src, string_size);
	printf("l_dst_ft = %zu\n", l_dst_ft);
	printf("dst_ft = %s\n", dst_ft);
}
*/
