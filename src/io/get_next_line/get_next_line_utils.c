/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:38:40 by jweber            #+#    #+#             */
/*   Updated: 2025/04/03 12:00:18 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int	new_node(t_list **plst, char *str, int len, t_data_list *ptr_data)
{
	t_list	*new;

	new = ft_s_lstnew(str);
	if (new == NULL)
	{
		free(str);
		return (ERROR_MALLOC);
	}
	if (*plst == NULL)
	{
		*plst = new;
		ptr_data->tot_len = len;
		ptr_data->last = new;
	}
	else
	{
		ptr_data->last->next = new;
		ptr_data->tot_len += len;
		ptr_data->last = new;
	}
	return (0);
}

void	change_buff(char *buff, int index)
{
	int	j;

	j = 0;
	while (buff[index + j])
	{
		buff[j] = buff[index + j];
		j++;
	}
	while (buff[j])
	{
		buff[j] = '\0';
		j++;
	}
	return ;
}

void	buff_clear(char *buff)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buff[i] = '\0';
		i++;
	}
	return ;
}

void	lst_clear(t_list **plst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *plst;
	tmp2 = tmp1;
	while (tmp2 != NULL)
	{
		tmp1 = tmp2;
		tmp2 = tmp2->next;
		free(tmp1->content);
		free(tmp1);
	}
	*plst = NULL;
}
