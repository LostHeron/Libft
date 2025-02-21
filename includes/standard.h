/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:40:03 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 13:18:51 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STANDARD_H
# define STANDARD_H

# include <stdlib.h>

int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_countwords(char const *s, char *charset);
char	**ft_split(char const *s, char *charset);
char	*ft_itoa(int n);
void	*ft_malloc(unsigned long size);

#endif
