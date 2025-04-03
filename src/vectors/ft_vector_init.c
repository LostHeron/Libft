/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:50:15 by jweber            #+#    #+#             */
/*   Updated: 2025/04/03 14:44:49 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "ft_standard.h"

int	ft_vector_init(t_vector *ptr_vector,
					size_t capacity, size_t data_size, void (*del)())
{
	if (ptr_vector == NULL)
		return (1);
	ptr_vector->data = ft_malloc(data_size * capacity);
	if (ptr_vector->data == NULL)
		return (ERROR_MALLOC);
	ptr_vector->capacity = capacity;
	ptr_vector->data_size = data_size;
	ptr_vector->del = del;
	ptr_vector->size = 0;
	return (0);
}

/*
//create a vectof of (char *)
#include <stdio.h>
#include "ft_string.h"

static void	my_free(t_vector *vector);
static void	print_vec(t_vector vec);

int	main(void)
{
	t_vector	char_ptr_vector;
	int			ret;

	ret = ft_vector_init(&char_ptr_vector, 2, sizeof(char *), &my_free);
	if (ret != 0)
		printf("vector initialisation : Failure\n");
	else
		printf("vector initialisation : Success\n");
	char *elem1 = ft_strdup("bonjour");
	ret = ft_vector_add_single(&char_ptr_vector, &elem1);
	if (ret != 0)
		printf("could not add elem to vector\n");
	else
		printf("element added successfully\n");
	char *elem2 = ft_strdup("coucou");
	ret = ft_vector_add_single(&char_ptr_vector, &elem2);
	if (ret != 0)
		printf("could not add elem to vector\n");
	else
		printf("element added successfully\n");
	char *elem3 = ft_strdup("eheh");
	ret = ft_vector_add_single(&char_ptr_vector, &elem3);
	if (ret != 0)
		printf("could not add elem to vector\n");
	else
		printf("element added successfully\n");
	print_vec(char_ptr_vector);
	ft_vector_free(&char_ptr_vector);
}

static void	print_vec(t_vector vec)
{
	size_t	i;

	i = 0;
	while (i < vec.size)
	{
		printf("elem[%zu] : '%s'\n", i, ((char **)vec.data)[i]);
		i++;
	}
}

static void	my_free(t_vector *vector)
{
	size_t	i;

	i = 0;
	while (i < vector->size)
	{
		free(((char **)vector->data)[i]);
		i++;
	}
	free(vector->data);
	vector->data = NULL;
	vector->size = 0;
	vector->capacity = 0;
	vector->del = NULL;
}
*/
