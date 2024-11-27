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

static int	ft_get_size(int n);
static char	*ft_itoa_pos(int n);
static char	*ft_itoa_neg(int n);

char	*ft_itoa(int n)
{
	if (n < 0)
		return (ft_itoa_neg(n));
	else
		return (ft_itoa_pos(n));
}

static char	*ft_itoa_pos(int n)
{
	int		size;
	int		n_c;
	int		i;
	char	*res;

	size = ft_get_size(n);
	res = malloc((size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	n_c = n;
	while (i < size)
	{
		res[size - 1 - i] = ((char)(n_c % 10)) + '0';
		n_c = n_c / 10;
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	*ft_itoa_neg(int n)
{
	int		size;
	int		n_c;
	int		i;
	char	*res;

	size = ft_get_size(n) + 1;
	res = malloc((size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[0] = '-';
	i = 0;
	n_c = n;
	while (i < size - 1)
	{
		res[size - 1 - i] = (((char)(-(n_c % 10))) + '0');
		n_c = n_c / 10;
		i++;
	}
	res[size] = '\0';
	return (res);
}

static int	ft_get_size(int n)
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

/*
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
	free(res);
	printf("\n");
}

int	main(void)
{
	check(15434);
	check(-15434);
	check(2147483647);
	check(-2147483647);
	check(-2147483648);
	check(0);
	check(10);
	check(-10);
	check(9);
	check(-9);
}
*/
