/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_standard.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:40:03 by jweber            #+#    #+#             */
/*   Updated: 2025/06/19 16:35:27 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STANDARD_H
# define FT_STANDARD_H

# include <stdlib.h>

int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_countwords(char const *s, char *charset);
char	**ft_split(char const *s, char *charset);
char	*ft_split_free(char **str);
char	*ft_itoa(int n);
void	*ft_malloc(unsigned long size);

#endif
