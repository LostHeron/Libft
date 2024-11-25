/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:08:59 by jweber            #+#    #+#             */
/*   Updated: 2024/11/23 19:13:11 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst->content != NULL)
	{
		del(lst->content);
		lst->content = NULL;
	}
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
