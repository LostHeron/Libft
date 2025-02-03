/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:30:26 by jweber            #+#    #+#             */
/*   Updated: 2025/01/31 13:38:19 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include <stdio.h>

void	my_print(void *a);

int	main(void)
{
	int		*a;
	t_node	*node;
	t_stack	stack1;
	t_stack	stack2;

	// init of stack1: 
	stack1.size = 0;
	stack1.head = NULL;
	// init of stack2
	stack2.size = 0;
	stack2.head = NULL;

	a = malloc(1 * sizeof(int));
	*a = 4;
	node = ft_dc_node_new(a);
	ft_dc_stack_add(&stack1, node);

	a = malloc(1 * sizeof(int));
	*a = 5;
	node = ft_dc_node_new(a);
	ft_dc_stack_add(&stack1, node);

	a = malloc(1 * sizeof(int));
	*a = 6;
	node = ft_dc_node_new(a);
	ft_dc_stack_add(&stack1, node);

	ft_dc_stack_print(stack1, &my_print);
}

void	my_print(void *a)
{
	printf("%i\n", *((int *)a));
}
