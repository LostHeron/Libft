/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:49:03 by jweber            #+#    #+#             */
/*   Updated: 2025/06/30 13:59:06 by jweber           ###   ########.fr       */
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

/* -> data : a void pointer to the array of data which should be cast
 * when using the library
 * -> size : the number of current element there is in the array
 * -> capacity : (should never be used, only here for internal usage)
 * the total possible element currently possible to put inside the struct
 * -> data_size : (should never be used, only here for internal usage)
 * the size each element take in the array
 * -> del : a pointer to a function taking a pointer to the structure, 
 * and returning void, which should be used to free the memory required by
 * the structure.
*/
typedef struct s_vector
{
	void	*data;
	size_t	size;
	size_t	capacity;
	size_t	data_size;
	void	(*del)(struct s_vector *ptr_vector);
}			t_vector;

int		ft_vector_add_single(t_vector *ptr_vector, void *elem);
int		ft_vector_add_multi(t_vector *ptr_vec, void *elem, size_t nb_elem);
int		ft_vector_free(t_vector *ptr_vector);
int		ft_vector_init(t_vector *ptr_vector,
			size_t capacity, size_t data_size, void (*del)());
int		ft_vector_resize(t_vector *ptr_vec, size_t new_capacity);
void	ft_vector_copy(t_vector *dest, t_vector *src);

#endif
