/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:47:56 by jweber            #+#    #+#             */
/*   Updated: 2024/11/19 10:03:46 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_c;
	char	*src_c;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	dest_c = dest;
	src_c = (char *) src;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	//char	*src = "yo mon gars";
	char	tbchange_or[] = "iiiiiiiiiii";
	int		n_value = 11 + 50;
	char	tbchange_ft[] = "iiiiiiiiiii";

	printf("official function\n");
	printf("avant change : \n");
	printf("%s\n", tbchange_or);
	//ft_memcpy(tbchange_or, src, n_value);
	memcpy(NULL, NULL, n_value);
	printf("apres change : \n");
	printf("%s\n", tbchange_or);
	printf("\n");

	printf("my function\n");
	printf("avant change : \n");
	printf("%s\n", tbchange_ft);
	// ft_memcpy(tbchange_ft, src, n_value);
	memcpy(NULL, NULL, n_value);
	printf("apres change : \n");
	printf("%s\n", tbchange_ft);
	printf("\n");
}
*/
