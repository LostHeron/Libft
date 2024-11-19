/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:22:16 by jweber            #+#    #+#             */
/*   Updated: 2024/11/19 09:26:50 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s_t;

	i = 0;
	s_t = s;
	while (i < n)
	{
		s_t[i] = 0;
		i++;
	}
	return ;
}

/*
#include <stdio.h>
#include <string.h>

void	ft_print_array(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%i, ", arr[i]);
		i++;
	}
	printf("\n");
	return ;
}

int	main(void)
{
	int str_ft[] = {INT_MAX, INT_MAX, INT_MAX};
	int	str_or[] = {INT_MAX, INT_MAX, INT_MAX};

	int	bzero_value = -1;
	
	printf("my bzero function :\n");
	printf("avant bzero\n");
	ft_print_array(str_ft, 3);
	ft_bzero(str_ft, bzero_value);
	printf("apres bzero\n");
	ft_print_array(str_ft, 3);
	printf("\n");

	printf("offcial function\n");
	printf("avant bzero\n");
	ft_print_array(str_or, 3);
	bzero(str_or, bzero_value);
	printf("apres bzero\n");
	ft_print_array(str_or, 3);
	printf("\n");

	printf("comparing values : \n");
	ft_print_array(str_ft, 3);
	ft_print_array(str_or, 3);

}
*/
