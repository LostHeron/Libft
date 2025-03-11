/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists_double_circular.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:05:33 by jweber            #+#    #+#             */
/*   Updated: 2025/03/11 17:39:17 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_DOUBLE_CIRCULAR_H
# define LISTS_DOUBLE_CIRCULAR_H

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	char	*name;
	t_node	*head;
}			t_stack;

t_node	*ft_dc_node_new(void *content);
int		ft_dc_stack_add(t_stack *stack, t_node *node);
int		ft_dc_stack_add_back(t_stack *stack, t_node *node);
t_node	*ft_dc_stack_rem(t_stack *pstack);
t_node	*ft_dc_stack_clear(t_stack *pa, void *(*f)(void *));
void	ft_dc_stack_print(t_stack stack, void (*f)(void *));

#endif
