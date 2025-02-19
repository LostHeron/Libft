/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:16:48 by jweber            #+#    #+#             */
/*   Updated: 2024/12/16 16:46:13 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# if BUFFER_SIZE <= 0
#  error BUFFER_SIZE must be greater than 0
# endif

# include "lists_single.h"

typedef struct s_data_list
{
	int		check_eol;
	int		tot_len;
	t_list	*last;
}	t_data_list;

char	*get_next_line(int fd);
void	*while_read(int fd, t_list **plst, char *buff, t_data_list *ptr_data);
void	buff_clear(char *buff);
void	*lst_clear(t_list **plst);
void	*add_node_change_buff(t_list **plst, char *buff, t_data_list *ptr_data);
void	*new_node(t_list **plst, char *str, int len, t_data_list *ptr_data);
void	change_buff(char *buff, int index);
void	*get_string(t_list **plst, t_data_list *ptr_data);
char	*buff_not_empty(int fd, t_list **plst, char *buf, t_data_list *ptrdata);

#endif
