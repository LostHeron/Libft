/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:27:08 by jweber            #+#    #+#             */
/*   Updated: 2025/04/03 13:28:04 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"

int	ft_vector_free(t_vector *ptr_vector)
{
	ptr_vector->del(ptr_vector);
	return (SUCCESS);
}
