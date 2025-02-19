/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:31:12 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:55:08 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_single.h"

void	ft_s_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp_node;

	tmp_node = *lst;
	*lst = new;
	(*lst)->next = tmp_node;
	return ;
}

/*
#include <stdio.h>

static void	ft_print_lst(t_list *lst)
{
	while (lst != NULL)
	{
		printf("content = %s\n", (char *) lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	*l1;
	t_list	*l2;

	l1 = ft_lstnew("yo la team");
	l2 = ft_lstnew("COMMENT VA ?");
	printf("list avant addfront : \n");
	ft_print_lst(l1);
	ft_lstadd_front(&l1, l2);
	printf("list APRES addfront : \n");
	ft_print_lst(l1);
}
*/
