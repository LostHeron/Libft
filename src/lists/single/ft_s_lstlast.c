/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:41:13 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:55:08 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_single.h"
#include <stdlib.h>

t_list	*ft_s_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
		return (lst);
	}
	else
		return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;
	t_list	*l4;

	l1 = ft_lstnew("yo");
	l2 = ft_lstnew("la");
	l3 = ft_lstnew("team");
	l1->next = l2;
	l2->next = l3;

	l4 = ft_lstlast(l1);
	printf("last string = '%s'\n", (char *) l4->content);
}
*/
