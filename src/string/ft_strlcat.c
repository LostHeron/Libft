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
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
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
