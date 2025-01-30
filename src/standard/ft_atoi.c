/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:45:57 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:50:10 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "standard.h"

static long	calc_next_b(long *b, int sign, char c);

int	ft_atoi(const char *nptr)
{
	long	b;
	long	i;
	long	sign;

	b = 0;
	i = 0;
	sign = 1;
	while (('\t' <= nptr[i] && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		if (calc_next_b(&b, sign, nptr[i]) == 1)
			return ((int) b);
		i++;
	}
	return ((int) b);
}

static long	calc_next_b(long *b, int sign, char c)
{
	long	b_prev;

	b_prev = *b;
	if (sign == -1)
	{
		*b = *b * 10 - (c - '0');
		if (*b > b_prev)
		{
			*b = LONG_MIN;
			return (1);
		}
	}
	else
	{
		*b = *b * 10 + (c - '0');
		if (*b < b_prev)
		{
			*b = LONG_MAX;
			return (1);
		}
	}
	return (0);
}

/*
#include <stdlib.h>
#include <stdio.h>

void static	check(const char *s)
{
	int	res_ft;
	int	res_or;

	res_ft = ft_atoi(s);
	res_or = atoi(s);
	printf("res_ft = %i\n", res_ft);
	printf("res_or = %i\n", res_or);
	if (res_ft != res_or)
		printf("ERREUR !!!!\n");
	else
		printf("OK OK / / \n");
	printf("\n");
}

int	main(void)
{
	check("0");
	check("-0");
	check("9");
	check("-9");
	check("10");
	check("-10");
	check("  \t\r  \r -10");
	check("  \t\r  \r --10");
	check("  \t\r  \r +10");
	check("  \t\r  \r ++10");
	check("1346840684053168");
	check("-1346840684053168");
	check("13468406840531686546843483313543783835384");
	check("-13468406840531686546843483313543783835384");
	check("2147483647");
	check("-2147483648");
	check("\010 9");
	printf("%s\n", "\010 9");
}
*/
