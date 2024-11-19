/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:57:27 by jweber            #+#    #+#             */
/*   Updated: 2024/11/06 13:36:18 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <ctype.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~ testing ft_isalpha \n");
	printf("ft_isalpha('a') = %i\n", ft_isalpha('a'));
	printf("ft_isalpha('A') = %i\n", ft_isalpha('A'));
	printf("ft_isalpha('z') = %i\n", ft_isalpha('z'));
	printf("ft_isalpha('Z') = %i\n", ft_isalpha('Z'));
	printf("ft_isalpha('8') = %i\n", ft_isalpha('8'));
	printf("isalpha('a') = %i\n", isalpha('a'));
	printf("isalpha('A') = %i\n", isalpha('A'));
	printf("isalpha('z') = %i\n", isalpha('z'));
	printf("isalpha('Z') = %i\n", isalpha('Z'));
	printf("isalpha('8') = %i\n", isalpha('8'));
	printf("~~~~~~~~~~~~~~~~~~~~ testing ft_isdigit \n");
	printf("ft_isdigit('0') = %i\n", ft_isdigit('0'));
	printf("ft_isdigit('9') = %i\n", ft_isdigit('9'));
	printf("ft_isdigit('A') = %i\n", ft_isdigit('A'));
	printf("isdigit('0') = %i\n", isdigit('0'));
	printf("isdigit('9') = %i\n", isdigit('9'));
	printf("isdigit('A') = %i\n", isdigit('A'));
	printf("~~~~~~~~~~~~~~~~~~~~ testing ft_isalnum\n");
	printf("ft_isalnum('0') = %i\n", ft_isalnum('0'));
	printf("ft_isalnum('9') = %i\n", ft_isalnum('9'));
	printf("ft_isalnum('a') = %i\n", ft_isalnum('a'));
	printf("ft_isalnum('z') = %i\n", ft_isalnum('z'));
	printf("ft_isalnum('+') = %i\n", ft_isalnum('+'));
	printf("isalnum('0') = %i\n", isalnum('0'));
	printf("isalnum('9') = %i\n", isalnum('9'));
	printf("isalnum('a') = %i\n", isalnum('a'));
	printf("isalnum('z') = %i\n", isalnum('z'));
	printf("isalnum('+') = %i\n", isalnum('+'));
	printf("~~~~~~~~~~~~~~~~~~~~ testing ft_isascii\n");
	printf("ft_isascii('A') = %i\n", ft_isascii('A'));
	printf("ft_isascii(0) = %i\n", ft_isascii(0));
	printf("ft_isascii(127) = %i\n", ft_isascii(127));
	printf("ft_isascii(128) = %i\n", ft_isascii(128));
	printf("isascii('A') = %i\n", isascii('A'));
	printf("isascii(0) = %i\n", isascii(0));
	printf("isascii(127) = %i\n", isascii(127));
	printf("isascii(128) = %i\n", isascii(128));
	printf("~~~~~~~~~~~~~~~~~~~~ testing ft_isprint\n");
	printf("ft_isprint('A') = %i\n", ft_isprint('A'));
	printf("ft_isprint(' ') = %i\n", ft_isprint(' '));
	printf("ft_isprint('~') = %i\n", ft_isprint('~'));
	printf("ft_isprint('\a') = %i\n", ft_isprint('\a'));
	printf("ft_isprint('\b') = %i\n", ft_isprint('\b'));
	printf("isprint('A') = %i\n", isprint('A'));
	printf("isprint(' ') = %i\n", isprint(' '));
	printf("isprint('~') = %i\n", isprint('~'));
	printf("isprint('\a') = %i\n", isprint('\a'));
	printf("isprint('\b') = %i\n", isprint('\b'));
	printf("~~~~~~~~~~~~~~~~~~~~ testing ft_strlen\n");
	printf("ft_strlen(\"coucou toi\" = %zu\n", ft_strlen("coucou_toi\n"));
	printf("strlen(\"coucou toi\" = %zu\n", strlen("coucou_toi\n"));
	printf("~~~~~~~~~~~~~~~~~~~~ testing memset\n");
	char my_s[] = "coucou";
	ft_memset(my_s, '2', 2);
	int mon_array[] = {12, 13, 14, 15, 15};
	ft_memset(mon_array, '2', 2);
	printf("~~~~~~~~~~~~~~~~~~~~ testing putnbr\n");
	ft_putstr_fd("ft_putnbr_fd(\"2147483647LL\", 2) = ", 2);
	ft_putnbr_fd(2147483647LL, 2);
	ft_putstr_fd("\nft_putnbr_fd(\"-2147483648LL\", 2) = ", 2);
	ft_putnbr_fd(-2147483648LL, 2);
	ft_putstr_fd("\nft_putnbr_fd(\"-2147483647LL\", 2) = ", 2);
	ft_putnbr_fd(-2147483647LL, 2);
	ft_putnbr_fd(-2147483647ll, 2);
	ft_putstr_fd("\nft_putnbr_fd(\"0\", 1) = ", 1);
	ft_putnbr_fd(0, 1);
	ft_putstr_fd("\nft_putnbr_fd(\"-9\", 1) = ", 1);
	ft_putnbr_fd(-9, 1);
	ft_putstr_fd("\nft_putnbr_fd(\"9\", 1) = ", 1);
	ft_putnbr_fd(9, 1);
	ft_putstr_fd("\nft_putnbr_fd(\"-10\", 1) = ", 1);
	ft_putnbr_fd(-10, 1);
	ft_putstr_fd("\nft_putnbr_fd(\"10\", 1) = ", 1);
	ft_putnbr_fd(10, 1);
}
