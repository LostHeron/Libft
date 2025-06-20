/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_lstrem_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:21:58 by jweber            #+#    #+#             */
/*   Updated: 2025/06/19 11:30:15 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_single.h"
#include <stdlib.h>

void	ft_s_lstrem_last(t_list **p_lst, void (*del)(void *))
{
	t_list	*tmp;

	if (*p_lst == NULL)
		return ;
	else if ((*p_lst)->next == NULL)
	{
		ft_s_lstdelone(*p_lst, del);
		*p_lst = NULL;
		return ;
	}
	else
	{
		tmp = *p_lst;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		ft_s_lstdelone(tmp->next, del);
		tmp->next = NULL;
		return ;
	}
}
