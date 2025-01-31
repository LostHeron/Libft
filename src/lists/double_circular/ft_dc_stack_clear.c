/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dc_stack_clear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:33:00 by jweber            #+#    #+#             */
/*   Updated: 2025/01/31 13:37:57 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"

t_node	*ft_dc_stack_clear(t_stack *pa, void *(*f)(void *))
{
	int		i;
	t_node	*tmp1;
	t_node	*tmp2;

	i = 0;
	tmp1 = pa->head;
	while (i < pa->size)
	{
		tmp2 = tmp1->next;
		if (f != NULL)
			f(tmp1->content);
		free(tmp1);
		tmp1 = tmp2;
	}
	pa->size = 0;
	pa->head = NULL;
	return (NULL);
}
