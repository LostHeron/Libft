/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:02:28 by jweber            #+#    #+#             */
/*   Updated: 2025/04/23 15:26:07 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

static double	get_value(double theta_square);

double	ft_cos(double theta)
{
	double	res;
	double	theta_square;
	int		sign;
	size_t	nb_pi_in_theta;

	nb_pi_in_theta = (int)(theta / PI);
	if (nb_pi_in_theta % 2 == 0)
		sign = 1;
	else
		sign = -1;
	theta = theta - nb_pi_in_theta * PI;
	theta_square = theta * theta;
	res = get_value(theta_square);
	return (res * sign);
}

static double	get_value(double theta_square)
{
	return (1 - theta_square / 2 \
	+ theta_square * theta_square / 24 \
	- theta_square * theta_square * theta_square / 720 \
	+ theta_square * theta_square * theta_square * theta_square / 40320 \
	- theta_square * theta_square * theta_square * theta_square * \
	theta_square / 3628800 \
	+ theta_square * theta_square * theta_square * theta_square * \
	theta_square * theta_square / 479001600 \
	- theta_square * theta_square * theta_square * theta_square * \
	theta_square * theta_square * theta_square / 87178291200 \
	+ theta_square * theta_square * theta_square * theta_square * \
	theta_square * theta_square * theta_square * theta_square / 20922789888000 \
	- theta_square * theta_square * theta_square * theta_square * \
	theta_square * theta_square * theta_square * theta_square * \
	theta_square / 6402373705728001 \
	+ theta_square * theta_square * theta_square * theta_square * \
	theta_square * theta_square * theta_square * theta_square * \
	theta_square * theta_square / 2432902008176640000);
}

/*
 * The two under functions comes from this blog : 
 * https://austinhenley.com/blog/cosine.html
double cos_taylor_running_yterms(double x, int y)
{
    int div = (int)(x / CONST_PI);
    x = x - (div * CONST_PI);
    char sign = 1;
    if (div % 2 != 0)
        sign = -1;

    double result = 1.0;
    double inter = 1.0;
    double num = x * x;
    for (int i = 1; i <= y; i++)
    {
        double comp = 2.0 * i;
        double den = comp * (comp - 1.0);
        inter *= num / den;
        if (i % 2 == 0)
            result += inter;
        else
            result -= inter;
    }
    return sign * result;
}


#define CONST_2PI 2 * PI
#define modd(x, y) ((x) - (int)((x) / (y)) * (y))
//double cos_taylor_literal_10terms(double x)
double	ft_cos_powered_up_blog(double x)
{
    x = modd(x, CONST_2PI);
    char sign = 1;
    if (x > CONST_PI)
    {
        x -= CONST_PI;
        sign = -1;
    }
    double xx = x * x;

    return sign * (1 - ((xx) / (2)) + \
	((xx * xx) / (24)) - ((xx * xx * xx) / (720)) + \
	((xx * xx * xx * xx) / (40320)) - \
	((xx * xx * xx * xx * xx) / (3628800)) + \
	((xx * xx * xx * xx * xx * xx) / (479001600)) - \
	((xx * xx * xx * xx * xx * xx * xx) / (87178291200)) + \
	((xx * xx * xx * xx * xx * xx * xx * xx) / (20922789888000)) - \
	((xx * xx * xx * xx * xx * xx * xx * xx * xx) / (6402373705728000)) + \
	((xx * xx * xx * xx * xx * xx * xx * xx * xx * xx) / (2432902008176640000)));
}
*/

/*
 *
 * first try of an ft_cos, is ok, but i can not get under 1e-13 precision 
 * from the 'cos' function from the math.h lib
 *
double	ft_cos(double theta)
{
	double	step = 0.005;
	double	cos_theta;
	double	sin_theta;
	double	tmp_cos;
	double	tmp_sin;
	double	current_theta;
	size_t	count;

	cos_theta = 1;
	sin_theta = 0;
	current_theta = 0;
	theta = theta - (int)(theta / (2 * PI)) * 2 * PI;
	count = 0;
	while (current_theta + 2 * step < theta)
	{
		current_theta += step;
		//tmp_cos = cos_theta - sin_theta * (step) - \
		// cos_theta / 2 * ft_power(step, 2)\
		//	+ sin_theta / 6 * ft_power(step, 3) + \
		//	cos_theta / 24 * ft_power(step, 4)\
		//	- sin_theta / 120 * ft_power(step, 5) - \
		//	cos_theta / 720 * ft_power(step, 6)\
		//	+ sin_theta / 5040 * ft_power(step, 7);
		//tmp_sin = sin_theta + cos_theta * (step) - \
		//	sin_theta / 2 * ft_power(step, 2) - \
		//	cos_theta / 6 * ft_power(step, 3) + \
		//	sin_theta / 24 * ft_power(step, 4)\
		//	+ cos_theta / 120 * ft_power(step, 5) - \
		//	sin_theta / 720 * ft_power(step, 6)\
		//	- cos_theta / 5040 * ft_power(step, 7);
		tmp_cos = cos_theta - sin_theta * (step) - cos_theta / 2 * step * step \
			+ sin_theta / 6 * step * step * step + \
			cos_theta / 24 * step * step * step * step \
			- sin_theta / 120 * step * step * step * step * step - \
			cos_theta / 720 * step * step * step * step * step * step \
			+ sin_theta / 5040 * step * step * step * step * step * step * step ;
		tmp_sin = sin_theta + cos_theta * (step) - sin_theta / 2 * step * step\
			- cos_theta / 6 * step * step * step + \
			sin_theta / 24 * step * step * step * step \
			+ cos_theta / 120 * step * step * step * step * step - \
			sin_theta / 720 * step * step * step * step * step * step\
			- cos_theta / 5040 * step * step * step * step * step * step * step ;
		cos_theta = tmp_cos;
		sin_theta = tmp_sin;
		count++;
	}
	step = theta - current_theta;
	tmp_cos = cos_theta - sin_theta * (step) - cos_theta / 2 * step * step\
		+ sin_theta / 6 * step * step * step + \
		cos_theta / 24 * step * step * step * step \
		- sin_theta / 120 * step * step * step * step * step - \
		cos_theta / 720 * step * step * step * step * step * step \
		+ sin_theta / 5040 * step * step * step * step * step * step * step ;
	tmp_sin = sin_theta + cos_theta * (step) - sin_theta / 2 * step * step\
		- cos_theta / 6 * step * step * step + \
		sin_theta / 24 * step * step * step * step \
		+ cos_theta / 120 * step * step * step * step * step - \
		sin_theta / 720 * step * step * step * step * step * step\
		- cos_theta / 5040 * step * step * step * step * step * step * step ;
	cos_theta = tmp_cos;
	sin_theta = tmp_sin;
	return (cos_theta);
}
*/
