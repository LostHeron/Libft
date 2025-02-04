/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dc_stack_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:26:05 by jweber            #+#    #+#             */
/*   Updated: 2025/01/31 13:30:16 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"

void	ft_dc_stack_print(t_stack stack, void (*aff)(void *))
{
	int		i;
	t_node	*tmp;

	tmp = stack.head;
	i = 0;
	while (i < stack.size)
	{
		aff(tmp->content);
		tmp = tmp->next;
		i++;
	}
}
