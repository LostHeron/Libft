/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:33:14 by jweber            #+#    #+#             */
/*   Updated: 2025/02/04 14:02:36 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putunbr_fd(unsigned int n, int fd);
int	ft_putendl_fd(char *s, int fd);
int	ft_putnbr_base_u_fd(unsigned int nbr, char *base, int fd);
int	ft_putnbr_base_ull_fd(unsigned long long nbr, char *base, int fd);
int	ft_printf_fd(int fd, const char *s, ...);

#endif
