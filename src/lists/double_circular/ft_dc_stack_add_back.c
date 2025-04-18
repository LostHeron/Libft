/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dc_lstnew_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:26:43 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 17:28:33 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_double_circular.h"
#include <stdlib.h>

int	ft_dc_stack_add_back(t_stack *stack, t_node *node)
{
	t_node	*old_last;
	t_node	*first;

	if (node == NULL)
		return (1);
	if (stack->size == 0)
	{
		stack->size = 1;
		stack->head = node;
		node->prev = node;
		node->next = node;
		return (0);
	}
	else
	{
		first = stack->head;
		old_last = stack->head->prev;
		stack->size++;
		first->prev = node;
		node->next = first;
		node->prev = old_last;
		old_last->next = node;
		return (0);
	}
}
