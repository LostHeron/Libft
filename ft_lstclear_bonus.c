/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:15:18 by jweber            #+#    #+#             */
/*   Updated: 2024/11/25 09:30:17 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_recursive(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		free_recursive(lst->next, del);
		if (lst->content != NULL)
			del(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	free_recursive(*lst, del);
	*lst = NULL;
}

/*
#include <stdio.h>

static void	print_list(t_list *l)
{
	while (l != NULL)
	{
		printf("- %s\n", (char *) l->content);
		l = l->next;
	}
}

int	main(void)
{
	t_list	*l;

	l = ft_lstnew(malloc(50 * sizeof(char *)));
	ft_strlcpy(l->content, "yo la team", 50);
	l->next = ft_lstnew(malloc(50 * sizeof(char *)));
	ft_strlcpy(l->next->content, "comment ça va ?", 50);
	l->next->next = ft_lstnew(malloc(50 * sizeof(char *)));
	ft_strlcpy(l->next->next->content, "ici ca va bien!", 50);
	print_list(l);
	ft_lstclear(&l, &free);
}
*/
