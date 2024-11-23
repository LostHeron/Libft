/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:52:20 by jweber            #+#    #+#             */
/*   Updated: 2024/11/23 19:00:23 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = *lst;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = new;
		}
	}
	return ;
}

/*
#include <stdio.h>

static void	print_lst(t_list *lst)
{
	while (lst != NULL)
	{
		printf("- %s\n", (char *) lst->content);
		lst = lst->next;
	}
	return ;
}

int	main(void)
{
	t_list *l1;

	l1 = NULL;
	ft_lstadd_back(&l1, ft_lstnew("yo"));
	ft_lstadd_back(&l1, ft_lstnew("la"));
	ft_lstadd_back(&l1, ft_lstnew("team"));
	printf("printing list \n");
	print_lst(l1);
	printf("\n");
}
*/
