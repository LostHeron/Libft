/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:16:23 by jweber            #+#    #+#             */
/*   Updated: 2024/12/16 16:46:07 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	t_list		*lst;
	int			i;
	t_data_list	data;

	data.last = NULL;
	data.tot_len = 0;
	data.check_eol = 0;
	i = 0;
	lst = NULL;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
	{
		i++;
		data.check_eol = 1;
	}
	if (i == 0)
		return (while_read(fd, &lst, buff, &data));
	else
		return (buff_not_empty(fd, &lst, buff, &data));
}

void	*while_read(int fd, t_list **plst, char *buff, t_data_list *ptr_data)
{
	int			nb_read;

	nb_read = 1;
	while (nb_read > 0 && ptr_data->check_eol == 0)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read < 0)
		{
			buff_clear(buff);
			return (lst_clear(plst));
		}
		if (add_node_change_buff(plst, buff, ptr_data) == NULL)
			return (lst_clear(plst));
	}
	return (get_string(plst, ptr_data));
}

char	*buff_not_empty(int fd, t_list **plst, char *buf, t_data_list *ptr_data)
{
	if (ptr_data->check_eol == 1)
	{
		if (add_node_change_buff(plst, buf, ptr_data) == NULL)
			return (lst_clear(plst));
		return (get_string(plst, ptr_data));
	}
	else
	{
		if (add_node_change_buff(plst, buf, ptr_data) == NULL)
			return (lst_clear(plst));
		return (while_read(fd, plst, buf, ptr_data));
	}
}

void	*get_string(t_list **plst, t_data_list *ptr_data)
{
	char	*str;
	t_list	*tmp;
	int		i;
	int		j;

	str = malloc((ptr_data->tot_len + 1) * sizeof(char));
	if (str == NULL)
		return (lst_clear(plst));
	i = 0;
	tmp = *plst;
	while (tmp != NULL)
	{
		j = 0;
		while (((char *)tmp->content)[j])
		{
			str[i] = ((char *)tmp->content)[j];
			j++;
			i++;
		}
		tmp = tmp->next;
	}
	str[i] = '\0';
	lst_clear(plst);
	return (str);
}

void	*add_node_change_buff(t_list **plst, char *buff, t_data_list *ptr_data)
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
		return (*plst);
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	j = -1;
	while (++j < i)
		str[j] = buff[j];
	str[j] = '\0';
	if (new_node(plst, str, i, ptr_data) == NULL)
		return (NULL);
	change_buff(buff, i);
	return (str);
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
