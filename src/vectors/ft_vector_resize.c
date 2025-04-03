/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:53:38 by jweber            #+#    #+#             */
/*   Updated: 2025/04/03 14:09:35 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "ft_standard.h"
#include "ft_memory.h"
#include <stdio.h>

int	ft_vector_resize(t_vector *ptr_vec, size_t new_capacity)
{
	void	*new_data;

	printf("on vient resize !\n");
	if (ptr_vec == NULL)
		return (FAILURE);
	new_data = ft_malloc(ptr_vec->data_size * new_capacity);
	if (new_data == NULL)
		return (ERROR_MALLOC);
	ft_memcpy(new_data, ptr_vec->data, ptr_vec->data_size * ptr_vec->size);
	free(ptr_vec->data);
	ptr_vec->data = new_data;
	ptr_vec->capacity = new_capacity;
	return (SUCCESS);
}
