/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:27:53 by jweber            #+#    #+#             */
/*   Updated: 2024/11/19 13:49:56 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l_dst;
	size_t	l_src;
	size_t	i;

	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (size <= l_dst)
		return (size + l_src);
	i = 0;
	while (src[i] && l_dst + i < size - 1)
	{
		dst[l_dst + i] = src[i];
		i++;
	}
	dst[l_dst + i] = '\0';
	return (l_dst + l_src);
}

/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	*src1;
	char	*src2;
	int		supplement;
	char	*buf_or;
	char	*buf_ft;
	size_t	res_or;
	size_t	res_ft;

	src1 = "Chien";
	src2 = "CommentEstCeQueTuVas";
	supplement = 100;
	buf_or = malloc((ft_strlen(src1) + supplement) * sizeof(char));
	buf_ft = malloc((ft_strlen(src1) + supplement) * sizeof(char));
	strlcpy(buf_or, src1, ft_strlen(src1) + supplement);
	strlcpy(buf_ft, src1, ft_strlen(src1) + supplement);
	printf("buf_or = %s\n", buf_or);
	printf("buf_ft = %s\n", buf_ft);
	res_or = strlcat(buf_or, src2, ft_strlen(src1) + 10);
	printf("res_or = %zu\n", res_or);
	printf("buf_or = %s\n", buf_or);
	res_ft = ft_strlcat(buf_ft, src2, ft_strlen(src1) + 10);
	printf("res_ft = %zu\n", res_ft);
	printf("buf_ft = %s\n", buf_ft);
}
*/
