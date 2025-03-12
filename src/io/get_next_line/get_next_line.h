/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:16:48 by jweber            #+#    #+#             */
/*   Updated: 2025/02/20 11:06:48 by jweber           ###   ########.fr       */
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

# define MALLOC_FAIL -3
# define READ_FAIL -1

# include "ft_lists_single.h"

typedef struct s_data_list
{
	int		check_eol;
	int		tot_len;
	t_list	*last;
}	t_data_list;

int		case_empty_buff(int fd, t_list **plst,
			char *buff, t_data_list *ptr_data);
void	buff_clear(char *buff);
void	lst_clear(t_list **plst);
int		add_node_change_buff(t_list **plst, char *buff, t_data_list *ptr_data);
int		new_node(t_list **plst, char *str, int len, t_data_list *ptr_data);
void	change_buff(char *buff, int index);
void	*get_string(t_list **plst, t_data_list *ptr_data, int *p_err_code);
int		buff_not_empty(int fd, t_list **plst, char *buf, t_data_list *ptr_data);

#endif
