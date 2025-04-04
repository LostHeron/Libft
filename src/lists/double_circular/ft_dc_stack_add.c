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

int	ft_dc_stack_add(t_stack *stack, t_node *node)
{
	t_node	*old_last;
	t_node	*old_first;

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
		stack->size++;
		old_first = stack->head;
		old_last = stack->head->prev;
		stack->head = node;
		node->next = old_first;
		node->prev = old_last;
		old_last->next = node;
		old_first->prev = node;
		return (0);
	}
}
