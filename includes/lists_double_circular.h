/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_double_circular.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:05:33 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 17:18:13 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_DOUBLE_CIRCULAR_H
# define LISTS_DOUBLE_CIRCULAR_H

# include <stdlib.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
}			t_stack;

#endif
