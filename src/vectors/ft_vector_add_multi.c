/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add_multi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:51:49 by jweber            #+#    #+#             */
/*   Updated: 2025/06/30 14:24:29 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "ft_memory.h"

int	ft_vector_add_multi(t_vector *ptr_vec, void *elem, size_t nb_elem)
{
	int	ret;

	if (ptr_vec->size + nb_elem > ptr_vec->capacity)
	{
		if (ptr_vec->size + nb_elem >= ptr_vec->capacity << 1)
			ret = ft_vector_resize(ptr_vec, (ptr_vec->size + nb_elem) << 1);
		else
			ret = ft_vector_resize(ptr_vec, ptr_vec->capacity << 1);
		if (ret != 0)
			return (ret);
	}
	ft_memcpy(ptr_vec->data + ptr_vec->data_size * ptr_vec->size,
		elem,
		ptr_vec->data_size * nb_elem);
	ptr_vec->size += nb_elem;
	return (SUCCESS);
}
