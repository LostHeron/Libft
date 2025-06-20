/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:38:48 by jweber            #+#    #+#             */
/*   Updated: 2025/04/10 17:39:47 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"

void	ft_vector_copy(t_vector *dest, t_vector *src)
{
	dest->data = src->data;
	dest->size = src->size;
	dest->capacity = src->capacity;
	dest->data_size = src->data_size;
	dest->del = src->del;
	return ;
}
