/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:01:54 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:45:40 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) | ft_isalpha(c));
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%i\n", ft_isalnum('A'));
	printf("%i\n", isalnum('A'));
	printf("%i\n", ft_isalnum('0'));
	printf("%i\n", isalnum('0'));
	printf("%i\n", ft_isalnum('+'));
	printf("%i\n", isalnum('+'));
	printf("%i\n", (2|1));
}
*/
