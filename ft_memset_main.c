/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:30:21 by jweber            #+#    #+#             */
/*   Updated: 2024/11/07 09:40:49 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char *msgft = "coucou toi mec";
	char *msgor = "coucou toi mec";

	ft_memset(msgft, 65, 2);
	memset(msgor, 65, 2);
	printf("%s\n", msgft);
	printf("%s\n", msgor);
}
