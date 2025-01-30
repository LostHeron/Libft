/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:57:13 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:50:31 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "standard.h"
#include "memory.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb != 0 && SIZE_MAX / nmemb < size)
		return (NULL);
	res = malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}
