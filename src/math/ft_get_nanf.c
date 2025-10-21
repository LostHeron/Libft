/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nanf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:15:30 by jweber            #+#    #+#             */
/*   Updated: 2025/07/16 14:19:28 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_math.h"

float	ft_get_nanf(void)
{
	uint32_t	value;
	float		*p_res;

	value = 0b01111111110000000000000000000000;
	p_res = (float *)&value;
	return (*p_res);
}
