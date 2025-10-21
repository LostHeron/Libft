/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:52:28 by jweber            #+#    #+#             */
/*   Updated: 2025/10/21 16:45:16 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#define EPS 1e-12

static void	init_high_low(double val, double *low, double *high);

double	ft_sqrt_binary(double val)
{
	double	high;
	double	low;
	double	mid;
	size_t	i;

	init_high_low(val, &low, &high);
	i = 0;
	mid = (high + low) / 2;
	while (i < 100)
	{
		mid = (high + low) / 2;
		if (ft_abs_double(mid * mid - val) < EPS)
			return (mid);
		else if (mid * mid > val)
			high = mid;
		else if (mid * mid < val)
			low = mid;
		i++;
	}
	return (mid);
}

static void	init_high_low(double val, double *low, double *high)
{
	*low = ft_min(1, val);
	*high = ft_max(1, val);
	while (100 * (*low) * (*low) < val)
		*low *= 10;
	while (0.001 * (*high) * (*high) > val)
		*high *= 0.1;
	return ;
}
