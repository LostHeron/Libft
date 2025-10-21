/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:26:31 by jweber            #+#    #+#             */
/*   Updated: 2025/04/23 15:34:45 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <stdlib.h>

int	ft_power_int(int nb, int power)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	while (i < power)
	{
		res = res * nb;
		i++;
	}
	return (res);
}

double	ft_power(double nb, size_t power)
{
	size_t	i;
	double	res;

	res = 1;
	i = 0;
	while (i < power)
	{
		res = res * nb;
		i++;
	}
	return (res);
}
