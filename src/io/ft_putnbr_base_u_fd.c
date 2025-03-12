/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:36:02 by jweber            #+#    #+#             */
/*   Updated: 2024/12/17 11:38:13 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"

static int	check_base(char *base);
static int	intermediate(unsigned int nbr, char *base, int *i, int fd);

int	ft_putnbr_base_u_fd(unsigned int nbr, char *base, int fd)
{
	int	count;
	int	val;

	count = 0;
	val = intermediate(nbr, base, &count, fd);
	if (val < 0)
		return (-1);
	else
		return (val);
}

static int	intermediate(unsigned int nbr, char *base, int *i, int fd)
{
	unsigned int	nb_base;
	int				val;

	if (check_base(base))
		return (-1);
	nb_base = ft_strlen(base);
	if (nb_base <= 1)
		return (-1);
	if (nbr > nb_base - 1)
	{
		if (intermediate(nbr / nb_base, base, i, fd) < 0)
			return (-1);
	}
	(*i)++;
	val = ft_putchar_fd(*(base + nbr % nb_base), fd);
	if (val < 0)
		return (-1);
	else
		return (*i);
}

static int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (*(base + i) == '\0')
		return (1);
	while (*(base + i))
	{
		j = 0;
		while (j < i)
		{
			if (*(base + i) == *(base + j))
				return (1);
			j++;
		}
		if (*(base + i) == '+' || *(base + i) == '-')
			return (1);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base);

void	ft_putnbr_sev_base(int nbr)
{
	char	*basehexa;
	char	*basebinaire;
	char	*baseoctal;
	char	*basedecimal;

	basehexa = "0123456789abcdef";
	basebinaire = "01";
	baseoctal = "01234567";
	basedecimal = "0123456789";
	printf("NBR = %i\n", nbr);
	printf("BASE HEXA\n");
	ft_putnbr_base(nbr, basehexa);
	printf("\n");
	printf("BASE BINAIRE\n");
	ft_putnbr_base(nbr, basebinaire);
	printf("\n");
	printf("BASE OCTAL\n");
	ft_putnbr_base(nbr, baseoctal);
	printf("\n");
	printf("BASE DECIMAL\n");
	ft_putnbr_base(nbr, basedecimal);
	printf("\n\n\n");
}

int	main(void)
{
	int	nbr;

	nbr = 2095243182;
	ft_putnbr_sev_base(nbr);
	nbr = 2147483647;
	ft_putnbr_sev_base(nbr);
	nbr = -2147483648;
	ft_putnbr_sev_base(nbr);
	nbr = -1047483648;
	ft_putnbr_sev_base(nbr);
	nbr = 1047483648;
	ft_putnbr_sev_base(nbr);
	nbr = 8;
	ft_putnbr_sev_base(nbr);
	nbr = -8;
	ft_putnbr_sev_base(nbr);
	nbr = 0;
	ft_putnbr_sev_base(nbr);
	nbr = 10;
	ft_putnbr_sev_base(nbr);
	nbr = 9;
	ft_putnbr_sev_base(nbr);
}
*/
