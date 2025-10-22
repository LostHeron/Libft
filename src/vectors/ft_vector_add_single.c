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

int	ft_vector_add_single(t_vector *ptr_vec, void *elem)
{
	int	ret;

	if (ptr_vec->size == ptr_vec->capacity)
	{
		ret = ft_vector_resize(ptr_vec, ptr_vec->capacity << 1);
		if (ret != 0)
			return (ret);
	}
	ft_memcpy((char *)ptr_vec->data + ptr_vec->data_size * ptr_vec->size,
		elem,
		ptr_vec->data_size);
	ptr_vec->size++;
	return (SUCCESS);
}
