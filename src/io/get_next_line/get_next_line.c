/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:16:23 by jweber            #+#    #+#             */
/*   Updated: 2025/02/20 11:16:10 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "io.h"
#include "string.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd, int *p_err_code)
{
	static char	buff[BUFFER_SIZE + 1];
	t_list		*lst;
	int			i;
	t_data_list	data;

	data.last = NULL;
	data.tot_len = 0;
	data.check_eol = 0;
	*p_err_code = 0;
	i = 0;
	lst = NULL;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i++] == '\n')
		data.check_eol = 1;
	if (i == 0)
	{
		*p_err_code = case_empty_buff(fd, &lst, buff, &data);
		return (get_string(&lst, &data, p_err_code));
	}
	else
	{
		*p_err_code = buff_not_empty(fd, &lst, buff, &data);
		return (get_string(&lst, &data, p_err_code));
	}
}

int	case_empty_buff(int fd, t_list **plst,
			char *buff, t_data_list *ptr_data)
{
	int			nb_read;

	nb_read = 1;
	while (nb_read > 0 && ptr_data->check_eol == 0)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read < 0)
		{
			buff_clear(buff);
			lst_clear(plst);
			return (READ_FAIL);
		}
		if (add_node_change_buff(plst, buff, ptr_data) < 0)
		{
			lst_clear(plst);
			return (MALLOC_FAIL);
		}
	}
	return (0);
}

int	buff_not_empty(int fd, t_list **plst, char *buf, t_data_list *ptr_data)
{
	if (ptr_data->check_eol == 1)
	{
		if (add_node_change_buff(plst, buf, ptr_data) < 0)
		{
			lst_clear(plst);
			return (MALLOC_FAIL);
		}
		return (0);
	}
	else
	{
		if (add_node_change_buff(plst, buf, ptr_data) < 0)
		{
			lst_clear(plst);
			return (MALLOC_FAIL);
		}
		return (case_empty_buff(fd, plst, buf, ptr_data));
	}
}

void	*get_string(t_list **plst, t_data_list *ptr_data, int *p_err_code)
{
	char	*str;
	t_list	*tmp;
	int		i;
	int		len_tmp;

	if (*plst == NULL)
		return (NULL);
	str = malloc((ptr_data->tot_len + 1) * sizeof(char));
	if (str == NULL)
	{
		lst_clear(plst);
		*p_err_code = MALLOC_FAIL;
		return (NULL);
	}
	i = 0;
	tmp = *plst;
	while (tmp != NULL)
	{
		len_tmp = ft_strlen((char *)tmp->content);
		ft_strcpy(str + i, (char *)tmp->content);
		i += len_tmp;
		tmp = tmp->next;
	}
	lst_clear(plst);
	return (str);
}

int	add_node_change_buff(t_list **plst, char *buff, t_data_list *ptr_data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
	{
		ptr_data->check_eol = 1;
		i++;
	}
	if (i == 0)
		return (0);
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (MALLOC_FAIL);
	j = -1;
	while (++j < i)
		str[j] = buff[j];
	str[j] = '\0';
	if (new_node(plst, str, i, ptr_data) < 0)
		return (MALLOC_FAIL);
	change_buff(buff, i);
	return (0);
}

/*
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			printf("could not open file\n");
			return (1);
		}
	}
	else
	{
		printf("wrong usage \n");
		return (1);
	}
	line = get_next_line(fd);
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
	}
}
*/
