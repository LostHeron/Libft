/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:39:00 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:54:59 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_single.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
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
	return ;
}

static void	f1(void *s)
{
	int		i;
	char	*s_c;

	s_c = s;
	i = 0;
	while (s_c[i])
	{
		if (i % 2 == 0)
			s_c[i] = 'A';
		i++;
	}
	return ;
}

int	main(void)
{
	t_list	*l;

	l = ft_lstnew(malloc(50 * sizeof(char)));
	ft_strlcpy(l->content, "yo la team", 50 * sizeof(char));
	l->next = ft_lstnew(malloc(50 * sizeof(char)));
	ft_strlcpy(l->next->content, "comment ca va ?", 50 * sizeof(char));
	l->next->next = ft_lstnew(malloc(50 * sizeof(char)));
	ft_strlcpy(l->next->next->content, "ici ca va !", 50 * sizeof(char));
	printf("AVANT : \n");
	print_list(l);
	ft_lstiter(l, &f1);
	printf("APRES : \n");
	print_list(l);
	ft_lstclear(&l, &free);
}
*/
