/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:09:29 by jweber            #+#    #+#             */
/*   Updated: 2025/10/22 17:35:19 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_math.h"
#include "ft_standard.h"

#define ATOF_MAX_LEN 4096

#define SUCCESS 0
#define FAILURE 1

#define TRUE 1
#define FALSE 0

static int		check_content(const char *str);
static int		check_len(const char *str, int *ptr_len);
static double	get_integer_part(const char *str);
static double	get_fractional_part(const char *str, int len);

/* this is a simplified version of strtod,
 * it return 0 if the conversion succeeded
 * or a non zero-integer otherwise,
 * the value is changed by passing a pointer to the value to be changed
 * it does not handle exponential notation (123.123e10) is not accepted
 * only allows some whitespace, followed by one '+' or one '-' sign
 * and followed by N digit, then an optional '.' and some other digits
 * the digits must end the string : '123a' is considered as an error
 * it only accept base 10 digit from the following : '123456789'
 * this might be changed latter, it is a first version !
*/
int	ft_atof_safe(const char *str, double *ptr_val)
{
	double	integer_part;
	double	fractional_part;
	int		len;
	int		sign;
	int		i;

	if (check_len(str, &len) != SUCCESS)
		return (ATOF_SAFE_TOO_LARGE_INPUT);
	if (check_content(str) != SUCCESS)
		return (ATOF_SAFE_WRONG_INPUT);
	integer_part = get_integer_part(str);
	fractional_part = get_fractional_part(str, len);
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	else
		sign = +1;
	*ptr_val = (integer_part + fractional_part) * sign;
	if (ft_is_inf_d(*ptr_val) == TRUE)
		return (ATOF_SAFE_OVERFLOW);
	return (SUCCESS);
}

/* This function assure that the len of the given 
 * string remain in a safe len inferior to ATOF_MAX_LEN
*/
static int	check_len(const char *str, int *ptr_len)
{
	int	i;

	i = 0;
	while (str[i] && i < ATOF_MAX_LEN)
	{
		i++;
	}
	if (str[i] != '\0')
		return (FAILURE);
	*ptr_len = i;
	return (SUCCESS);
}

/* Check that the format of the given string is :
 *	- begin with optional whitespace from ft_isspace
 *	- followed by an optional '+' or '-'
 *	- followed by many digits or one '.'
 *	- if there is an '.' it is followed by optional digits
 *	- and must not have any char after the digits !
*/
static int	check_content(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (FAILURE);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (FAILURE);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (FAILURE);
	return (SUCCESS);
}

static double	get_integer_part(const char *str)
{
	int		i;
	double	res;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str [i] == '-')
		i++;
	res = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

static double	get_fractional_part(const char *str, int len)
{
	int		i;
	double	res;

	i = len - 1;
	while (i >= 0 && str[i] != '.')
		i--;
	if (i < 0)
		return (0);
	res = 0;
	i = len - 1;
	while (i >= 0 && ft_isdigit(str[i]))
	{
		res = (res + str[i] - '0') / 10;
		i--;
	}
	return (res);
}
