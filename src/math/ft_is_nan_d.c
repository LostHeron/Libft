/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_nan_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:55:13 by jweber            #+#    #+#             */
/*   Updated: 2025/10/23 11:26:23 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#define TRUE 1
#define FALSE 0

int	ft_is_inf_d(double nb)
{
	unsigned long long	*ptr_nb;
	unsigned long long	nb_unsigned;
	unsigned long long	mantissa;
	unsigned long long	exponent;

	ptr_nb = (unsigned long long *)&nb;
	nb_unsigned = *ptr_nb;
	exponent
		= 0b0111111111110000000000000000000000000000000000000000000000000000LLU;
	mantissa
		= 0b0000000000001111111111111111111111111111111111111111111111111111LLU;
	exponent = nb_unsigned & exponent;
	mantissa = nb_unsigned & mantissa;
	if (exponent
		== 0b0111111111110000000000000000000000000000000000000000000000000000LLU
	)
	{
		if (mantissa != 0)
			return (TRUE);
	}
	return (FALSE);
}
