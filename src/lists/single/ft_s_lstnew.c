/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:06:15 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 13:24:44 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_single.h"
#include "ft_standard.h"
#include <stdlib.h>

t_list	*ft_s_lstnew(void *content)
{
	t_list	*new_node;

	new_node = ft_malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*my_list;
	t_list	*tmp_list;

	my_list = ft_lstnew("yo la team");
	tmp_list = my_list;
	while (tmp_list != NULL)
	{
		printf("content = %s\n", (char *)tmp_list->content);
		tmp_list = tmp_list->next;
	}
}
*/
