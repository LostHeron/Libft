/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:22:19 by jweber            #+#    #+#             */
/*   Updated: 2024/11/19 10:51:33 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned long long	add_dest;
	unsigned long long	add_src;
	char				*dest_c;
	char				*src_c;

	if (dest == NULL && src == NULL)
		return (NULL);
	add_dest = (unsigned long long) dest;
	add_src = (unsigned long long) src;
	dest_c = (char *) dest;
	src_c = (char *) src;
	i = -1;
	if (add_src < add_dest && add_dest <= add_src + n)
		while (++i < n)
			dest_c[n - 1 - i] = src_c[n - 1 - i];
	else
		while (++i < n)
			dest_c[i] = src_c[i];
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char src[100] = "CommentEstCeQueTuVas?";
	char *dest;

	dest = src + 7;
	printf("avant modif : \n");
	printf("%s\n", src);
	ft_memmove(dest, src, 21);
	printf("apres modif : \n");
	printf("%s\n", src);
}
*/
