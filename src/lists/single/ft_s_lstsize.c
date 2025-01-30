/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:58:44 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:55:33 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_single.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list *l1;
	t_list *l2;
	t_list *l3;
	int		i;

	l1 = ft_lstnew("yo");
	l2 = ft_lstnew("la");
	l3 = ft_lstnew("team");
	l1->next = l2;
	l2->next = l3;

	i = ft_lstsize(l1);
	printf("i = %i\n", i);

	t_list *l4;
	i = ft_lstsize(l4);
	printf("add l4 = %p\n", l4);
	printf("i = %i\n", i);
}
*/
