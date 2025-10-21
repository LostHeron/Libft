/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_newton.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:27:17 by jweber            #+#    #+#             */
/*   Updated: 2025/10/21 16:47:27 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_math.h"

#define EPS 1e-12

static size_t	get_nb_digits(double val);

double	ft_sqrt_newton(double val)
{
	double	start_x;
	double	a;
	double	b;
	size_t	i;
	size_t	nb_digits;

	if (ft_abs_double(val - 0) < EPS)
	{
		return (0);
	}
	else if (val < 0)
	{
		return (ft_get_nan());
	}
	nb_digits = get_nb_digits(val);
	start_x = val / ft_power(10, nb_digits / 2);
	i = 0;
	while (i < 100)
	{
		a = 2 * start_x;
		b = start_x * start_x - val - a * start_x;
		start_x = -b / a;
		i++;
	}
	return (start_x);
}

static size_t	get_nb_digits(double val)
{
	size_t	i;

	i = 0;
	while (val > 9)
	{
		val = val / 10;
		i++;
	}
	return (i);
}
