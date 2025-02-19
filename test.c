/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:08:29 by jweber            #+#    #+#             */
/*   Updated: 2025/02/17 11:54:06 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "io.h"
#include "src/io/get_next_line/get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.c", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf_fd(1, "-> %s", line);
		free(line);
	}
}
