/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_standard.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:40:03 by jweber            #+#    #+#             */
/*   Updated: 2025/08/29 13:47:53 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STANDARD_H
# define FT_STANDARD_H

# include <stdlib.h>

enum	e_atoi_safe
{
	ATOI_SAFE_OVERFLOW = 1,
	ATOI_SAFE_UNDERFLOW,
	ATOI_SAFE_WRONG_INPUT,
	ATOI_SAFE_TOO_LARGE_INPUT,
};

int		ft_atoi_safe(const char *str, int *p_value);

int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_countwords(char const *s, char *charset);
char	**ft_split(char const *s, char *charset);
char	*ft_split_free(char **str);
char	*ft_itoa(int n);
void	*ft_malloc(unsigned long size);

#endif
