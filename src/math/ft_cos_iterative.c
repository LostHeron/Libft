/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos_iterative.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:11:11 by jweber            #+#    #+#             */
/*   Updated: 2025/04/23 19:18:47 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

static double	get_cos(double theta, double step);
static double	get_next_sin(double cos_theta, double sin_theta, double step);
static double	get_next_cos(double cos_theta, double sin_theta, double step);

/*
 *
 * first try of an ft_cos, is ok, but i can not get under 1e-13 precision 
 * from the 'cos' function from the math.h lib as a reference 
 * assuming 1e-15 of precision
 *
*/
double	ft_cos_iterative(double theta)
{
	double	step;
	double	res;
	ssize_t	nb_pi_in_theta;

	nb_pi_in_theta = (int)(theta / PI);
	theta = theta - nb_pi_in_theta * PI;
	step = 0.05;
	res = get_cos(theta, step);
	if (nb_pi_in_theta % 2 == 0)
		return (res);
	else
		return (-res);
}

static double	get_cos(double theta, double step)
{
	double	current_theta;
	double	cos_theta;
	double	sin_theta;
	double	tmp_cos;
	double	tmp_sin;

	current_theta = 0;
	cos_theta = 1;
	sin_theta = 0;
	while (current_theta + 2 * step < theta)
	{
		current_theta += step;
		tmp_cos = get_next_cos(cos_theta, sin_theta, step);
		tmp_sin = get_next_sin(cos_theta, sin_theta, step);
		cos_theta = tmp_cos;
		sin_theta = tmp_sin;
	}
	step = theta - current_theta;
	tmp_cos = get_next_cos(cos_theta, sin_theta, step);
	tmp_sin = get_next_sin(cos_theta, sin_theta, step);
	cos_theta = tmp_cos;
	sin_theta = tmp_sin;
	return (cos_theta);
}

static double	get_next_cos(double cos_theta, double sin_theta, double step)
{
	return (cos_theta \
	- sin_theta * (step) \
	- cos_theta / 2 * ft_power(step, 2) \
	+ sin_theta / 6 * ft_power(step, 3) \
	+ cos_theta / 24 * ft_power(step, 4) \
	- sin_theta / 120 * ft_power(step, 5) \
	- cos_theta / 720 * ft_power(step, 6) \
	+ sin_theta / 5040 * ft_power(step, 7) \
	+ cos_theta / 40320 * ft_power(step, 8) \
	- sin_theta / 362880 * ft_power(step, 9) \
	- cos_theta / 3628800 * ft_power(step, 10));
}

static double	get_next_sin(double cos_theta, double sin_theta, double step)
{
	return (sin_theta \
	+ cos_theta * (step) \
	- sin_theta / 2 * ft_power(step, 2) \
	- cos_theta / 6 * ft_power(step, 3) \
	+ sin_theta / 24 * ft_power(step, 4) \
	+ cos_theta / 120 * ft_power(step, 5) \
	- sin_theta / 720 * ft_power(step, 6) \
	- cos_theta / 5040 * ft_power(step, 7) \
	+ sin_theta / 40320 * ft_power(step, 8) \
	+ cos_theta / 362880 * ft_power(step, 9) \
	- cos_theta / 3628800 * ft_power(step, 10));
}
