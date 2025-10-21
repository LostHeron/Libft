/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:02:21 by jweber            #+#    #+#             */
/*   Updated: 2024/11/05 13:08:05 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%i\n", ft_isdigit('0'));
	printf("%i\n", isdigit('0'));
	printf("%i\n", ft_isdigit('A'));
	printf("%i\n", isdigit('A'));
}
*/
