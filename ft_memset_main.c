/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:30:21 by jweber            #+#    #+#             */
/*   Updated: 2024/11/07 09:40:49 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char msgft[] = "coucou toi mec";
	char a = '\0';
	char msgor[] = "coucou toi mec";
	char b = '\0';

	/* testing normal behaviour */
	printf("ft_memset :\n");
	ft_memset(msgft, 65, 12);
	printf("%s\n", msgft);
	printf("memset :\n");
	memset(msgor, 65, 12);
	printf("%s\n", msgor);

	/* testing with size greater than array */
	printf("ft_memset :\n");
	ft_memset(msgft, 65, 100);
	printf("%s\n", msgft);
	printf("memset :\n");
	memset(msgor, 65, 100);
	printf("%s\n", msgor);

	/* testing with NULL pointer */
	printf("ft_memset :\n");
	ft_memset(NULL, 65, 100);
	printf("%s\n", msgft);
	printf("memset :\n");
	memset(NULL, 65, 100);
	printf("%s\n", msgor);
}
