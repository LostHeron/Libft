/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:29:33 by jweber            #+#    #+#             */
/*   Updated: 2025/10/23 11:13:20 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <stdlib.h>

# define PI 3.14159265358979323846

double	ft_max(double val1, double val2);
double	ft_min(double val1, double val2);
int		ft_power_int(int nb, int power);
double	ft_power(double nb, size_t power);
int		ft_abs(int nb);
double	ft_abs_double(double nb);
long	ft_labs(long nb);
double	ft_cos(double theta);
double	ft_cos_adaptive(double theta, int nb_terms);
double	ft_cos_iterative(double theta);
double	ft_get_nan(void);
float	ft_get_nanf(void);
double	ft_get_inf(void);
float	ft_get_inff(void);
int		ft_is_inf_d(double nb);
int		ft_is_nan_d(double nb);
double	ft_sin(double theta);
double	ft_tan(double theta);
double	ft_sqrt(double val);
double	ft_sqrt_newton(double val);
double	ft_sqrt_binary(double val);

#endif
