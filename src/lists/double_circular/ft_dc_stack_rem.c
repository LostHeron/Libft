/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dc_stack_rem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:47:51 by jweber            #+#    #+#             */
/*   Updated: 2025/01/31 12:15:20 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"

static t_node	*case_size_greater_2(t_stack *pstack, t_node *removed_node);

t_node	*ft_dc_stack_rem(t_stack *pstack)
{
	t_node	*removed_node;

	removed_node = NULL;
	if (pstack->size <= 0)
		return (NULL);
	else if (pstack->size == 1)
	{
		removed_node = pstack->head;
		pstack->head = NULL;
		pstack->size = 0;
		removed_node->next = NULL;
		removed_node->prev = NULL;
		return (removed_node);
	}
	else
	{
		removed_node = pstack->head;
		return (case_size_greater_2(pstack, removed_node));
	}
}

static t_node	*case_size_greater_2(t_stack *pstack, t_node *removed_node)
{
	t_node	*last_node;
	t_node	*new_head;

	removed_node = pstack->head;
	new_head = removed_node->next;
	last_node = removed_node->prev;
	pstack->head = new_head;
	last_node->next = new_head;
	new_head->prev = last_node;
	removed_node->next = NULL;
	removed_node->prev = NULL;
	return (removed_node);
}
