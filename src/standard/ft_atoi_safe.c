/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:33:33 by jweber            #+#    #+#             */
/*   Updated: 2025/08/29 14:41:50 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_standard.h"

static int	process_before_digits(const char *str, int *p_i, int *p_sign);

#define STRLEN_MAX 4096

/* This function is an atoi like function, except that it passe the integer
 * to get by reference and the return value is used to check if the string
 * passed as parameters is erroneous, or if the value passed will overflow
*/
int	ft_atoi_safe(const char *str, int *p_value)
{
	int	i;
	int	ret;
	int	sign;

	ret = process_before_digits(str, &i, &sign);
	if (ret != 0)
		return (ret);
	if (sign >= 0)
		return (ft_atoi_safe_positive());
	else
		return (ft_atoi_safe_negative());
}

static int	process_before_digits(const char *str, int *p_i, int *p_sign)
{
	*p_i = 0;
	while (*p_i < STRLEN_MAX && str[*p_i] != '\0' && ft_isspace(str[*p_i]) == 1)
		(*p_i)++;
	if ((*p_i) >= STRLEN_MAX)
		return (ATOI_SAFE_TOO_LARGE_INPUT);
	if (str[*p_i] == '\0')
		return (ATOI_SAFE_WRONG_INPUT);
	*p_sign = 1;
	if (str[*p_i] == '+' || str[*p_i] == '-')
	{
		if (str[*p_i] == '-')
			*p_sign = -1;
		(*p_i)++;
	}
	if ((*p_i) >= STRLEN_MAX)
		return (ATOI_SAFE_TOO_LARGE_INPUT);
	if (str[*p_i] == '\0')
		return (ATOI_SAFE_WRONG_INPUT);
	return (0);
}

int	ft_atoi_safe_positive(const char *str, int *p_value, int i, int sign)
{
	*p_value = 0;
	while (i < STRLEN_MAX && '0' <= str[i] && str[i] <= '9')
	{
		// two operation to perform here : 
		// multiplication of *p_value by 10, 
		// then addition of *p_value with str[i] + '0'
		// before each operation we need to check no overflow happens !
		// so here to the logic is :
		// INT_MAX / 10 > *p_value -> overflow 
		*p_value = *p_value * 10 + str[i] - '0';
		i++;
	}
	if (i >= STRLEN_MAX)
		return (ATOI_SAFE_TOO_LARGE_INPUT);
	if (str[i] == '\0')
		return (ATOI_SAFE_WRONG_INPUT);
	return (0);
}
