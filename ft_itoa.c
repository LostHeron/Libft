/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:14:27 by jweber            #+#    #+#             */
/*   Updated: 2024/11/21 15:59:33 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_size(int n)
{
	int	n_c;
	int	i;

	n_c = n;
	i = 0;
	while (!(-9 <= n_c && n_c <= 9))
	{
		n_c = n_c / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int		size;
	int		n_c;
	int		i;
	char	*res;

	size = 0;
	size += ft_get_size(n);
	if (n < 0)
		size++;
	printf("Allocation size = %i\n", size + 1);
	res = malloc((size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	i = 0;
	n_c = n;
	while (i < size + !(n_c < 0))
	{
		printf("size - 1 - i = %i\n", size - 1 - i);
		printf("n %% 10 = %i\n", n_c % 10);
		printf("'0' = %i\n", '0');
		printf("n %% 10 + '0' = %i\n", n_c % 10 + '0');
		printf("n %% 10 + '0' = '%c'\n", n_c % 10 + '0');
		printf("res[size - 1 - i] = (char) n_c %% 10 + '0' => res[%i] = '%c', %i\n", size - 1 - i, (char) n_c % 10 + '0', (char) n_c % 10 + '0');
		res[size - 1 - i] = ((char) (n_c % 10)) + '0';
		n_c = n_c / 10;
		i++;
	}
	printf("apres while\n");
	res[i] = '\0';
	return (res);
}

#include <stdio.h>

void static	check(int n)
{
	int		size;
	char	*res;

	printf("n = %i\n", n);
	size = ft_get_size(n);
	printf("size = %i\n", size);
	res = ft_itoa(n);
	printf("res = %s\n", res);
	printf("\n");
}

int	main(void)
{
	check(15434);
	check(-15434);
}
