/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:39:59 by jweber            #+#    #+#             */
/*   Updated: 2025/04/23 16:10:25 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <sys/types.h>

static double	get_value(double theta);

double	ft_sin(double theta)
{
	double	res;
	ssize_t	nb_pi_in_theta;

	nb_pi_in_theta = (int)(theta / PI);
	theta = theta - nb_pi_in_theta * PI;
	res = get_value(theta);
	if (nb_pi_in_theta % 2 == 0)
		return (res);
	else
		return (-res);
}

static double	get_value(double theta)
{
	double	theta_square;

	theta_square = theta * theta;
	return (theta - theta * theta_square / 6
		+ theta * theta_square * theta_square / 120
		- theta * theta_square * theta_square * theta_square / 5040
		+ theta * theta_square * theta_square * theta_square
		* theta_square / 362880
		- theta * theta_square * theta_square * theta_square * theta_square
		* theta_square / 39916800
		+ theta * theta_square * theta_square * theta_square * theta_square
		* theta_square * theta_square / 6227020800
		- theta * theta_square * theta_square * theta_square * theta_square
		* theta_square * theta_square * theta_square / 1307674368000
		+ theta * theta_square * theta_square * theta_square * theta_square
		* theta_square * theta_square * theta_square * theta_square
		/ 355687428096000
		- theta * theta_square * theta_square * theta_square * theta_square
		* theta_square * theta_square * theta_square * theta_square
		* theta_square / 121645100408832000);
}
