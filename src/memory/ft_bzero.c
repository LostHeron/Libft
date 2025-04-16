/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:22:16 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:48:52 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	ft_bzero(void *s, size_t n)
{
	size_t				i;
	size_t				incr;
	unsigned long long	*s_c;
	size_t				nb_tot;
	size_t				nb_zeroed;

	s_c = (unsigned long long *) s;
	i = 0;
	nb_zeroed = 0;
	if (n >= 8)
	{
		nb_tot = n - 8;
		incr = sizeof(unsigned long long);
		while (nb_zeroed < nb_tot)
		{
			*(s_c + i) = 0;
			i++;
			nb_zeroed += incr;
		}
	}
	while (nb_zeroed < n)
	{
		*(((char *)s_c) + nb_zeroed) = 0;
		nb_zeroed += 1;
	}
}

/*
my_first bzero function :
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
*/

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
