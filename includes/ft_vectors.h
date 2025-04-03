/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:49:03 by jweber            #+#    #+#             */
/*   Updated: 2025/04/03 14:08:54 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTORS_H
# define FT_VECTORS_H

# include <stdlib.h>

# ifndef ERROR_MALLOC
#  define ERROR_MALLOC -3
# endif

# ifndef FAILURE
#  define FAILURE 1
# endif

# ifndef SUCCESS
#  define SUCCESS 0
# endif

typedef struct s_vector
{
	void	*data;
	size_t	size;
	size_t	data_size;
	size_t	capacity;
	void	(*del)(struct s_vector *ptr_vector);
}			t_vector;

int	ft_vector_add_single(t_vector *ptr_vector, void *elem);
int	ft_vector_free(t_vector *ptr_vector);
int	ft_vector_init(t_vector *ptr_vector,
		size_t capacity, size_t data_size, void (*del)());
int	ft_vector_resize(t_vector *ptr_vec, size_t new_capacity);

#endif
