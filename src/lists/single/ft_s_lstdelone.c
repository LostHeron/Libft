/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:08:59 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:55:08 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_single.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
	return ;
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*l1;
	char	*str;

	str = malloc(50);
	ft_strlcpy(str, "yo la team", 50);
	l1 = ft_lstnew(str);
	printf("l1->content = '%s'\n", (char *) l1->content);
	ft_lstdelone(l1, &free);
}
*/
