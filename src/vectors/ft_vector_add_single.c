/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add_single.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:31:33 by jweber            #+#    #+#             */
/*   Updated: 2025/04/03 14:09:06 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "ft_memory.h"

int	ft_vector_add_single(t_vector *ptr_vector, void *elem)
{
	int	ret;

	if (ptr_vector == NULL)
		return (FAILURE);
	if (ptr_vector->size == ptr_vector->capacity)
	{
		ret = ft_vector_resize(ptr_vector, ptr_vector->capacity << 1);
		if (ret != 0)
			return (ret);
	}
	ft_memcpy(ptr_vector->data + ptr_vector->data_size * ptr_vector->size,
		elem,
		ptr_vector->data_size);
	ptr_vector->size++;
	return (SUCCESS);
}
