/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_single.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:30:00 by jweber            #+#    #+#             */
/*   Updated: 2025/01/30 16:55:55 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_SINGLE_H
# define LISTS_SINGLE_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list	*ft_s_lstnew(void *content);
void	ft_s_lstadd_front(t_list **lst, t_list *new);
int		ft_s_lstsize(t_list *lst);
t_list	*ft_s_lstlast(t_list *lst);
void	ft_s_lstadd_back(t_list **lst, t_list *new);
void	ft_s_lstdelone(t_list *lst, void (*del)(void *));
void	ft_s_lstclear(t_list **lst, void (*del)(void *));
void	ft_s_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_s_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
