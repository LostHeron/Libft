/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:24:25 by jweber            #+#    #+#             */
/*   Updated: 2025/10/23 14:47:01 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#define FAILURE 1
#define SUCCESS 0

/* this function is a modified version of strlen which return success and a
 * modified len value, only if the size of the string is lesser or equal
 * than 'len_max'
 * if the len of the string is greater than 'len_max' it return a non-zero value
 * indicating there was an error !
 * by address.
 * parameter 
*/
int	ft_strlen_safe(const char *s, size_t *ptr_len, size_t len_max)
{
	size_t	i;

	i = 0;
	*ptr_len = 0;
	while (s[i] && i < len_max)
	{
		i++;
	}
	if (s[i] != '\0')
		return (FAILURE);
	*ptr_len = i;
	return (SUCCESS);
}
