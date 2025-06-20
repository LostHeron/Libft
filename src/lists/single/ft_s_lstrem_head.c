/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_lstrem_head.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:30:33 by jweber            #+#    #+#             */
/*   Updated: 2025/06/19 11:32:07 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_single.h"
#include <stdlib.h>

void	ft_s_lstrem_head(t_list **p_lst, void (*del)(void *))
{
	t_list	*tmp;

	if (*p_lst == NULL)
		return ;
	tmp = *p_lst;
	*p_lst = (*p_lst)->next;
	ft_s_lstdelone(tmp, del);
}
