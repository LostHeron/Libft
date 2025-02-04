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

/*
#include "lists_double_circular.h"
#include <stdio.h>
#include <stdlib.h>

void	my_print(void *a);
void	*my_free(void *a);

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

	printf("stack 1 : \n");
	ft_dc_stack_print(stack1, &my_print);
	printf("stack 2 : \n");
	ft_dc_stack_print(stack2, &my_print);
	ft_dc_stack_add(&stack2, ft_dc_stack_rem(&stack1));
	ft_dc_stack_add(&stack2, ft_dc_stack_rem(&stack1));
	ft_dc_stack_add(&stack2, ft_dc_stack_rem(&stack1));
	ft_dc_stack_add(&stack2, ft_dc_stack_rem(&stack1));
	ft_dc_stack_add(&stack2, ft_dc_stack_rem(&stack1));
	ft_dc_stack_add(&stack2, ft_dc_stack_rem(&stack1));
	ft_dc_stack_add(&stack2, ft_dc_stack_rem(&stack1));
	ft_dc_stack_add(&stack1, ft_dc_stack_rem(&stack1));
	ft_dc_stack_add(&stack1, ft_dc_stack_rem(&stack2));
	printf("stack 1 : \n");
	ft_dc_stack_print(stack1, &my_print);
	printf("stack 2 : \n");
	ft_dc_stack_print(stack2, &my_print);
	// clearing the stacks;
	ft_dc_stack_clear(&stack1, &my_free);
	ft_dc_stack_clear(&stack2, &my_free);
}

void *my_free(void *a)
{
	free(a);
	return (NULL);
}

void	my_print(void *a)
{
	printf("%i\n", *((int *)a));
}
*/
