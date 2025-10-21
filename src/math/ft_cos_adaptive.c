/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos_adaptive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:03:06 by jweber            #+#    #+#             */
/*   Updated: 2025/04/23 15:34:57 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

static double	get_value(double ts, double fact, int nb_terms);

double	ft_cos_adaptive(double theta, int nb_terms)
{
	double	res;
	double	fact;
	double	theta_square;
	int		nb_pi_in_theta;

	nb_pi_in_theta = (int)(theta / PI);
	theta = theta - nb_pi_in_theta * PI;
	res = 1;
	fact = 1;
	theta_square = theta * theta;
	res = get_value(theta_square, fact, nb_terms);
	if (nb_pi_in_theta % 2 == 0)
		return (res * 1);
	else
		return (res * -1);
}

static double	get_value(double ts, double fact, int nb_terms)
{
	size_t	i;
	double	n_term;
	double	res;

	i = 0;
	n_term = 1;
	res = 1;
	while (i < (size_t) nb_terms - 1)
	{
		fact = fact * (2 * (double) i + 1) * (2 * (double) i + 2);
		n_term *= ts;
		if (i % 2 == 0)
			res = res - n_term / fact;
		else
			res = res + n_term / fact;
		i++;
	}
	return (res);
}
