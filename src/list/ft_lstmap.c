/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:20:43 by jweber            #+#    #+#             */
/*   Updated: 2024/11/25 12:37:27 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*my_ft_lstclear(t_list **p_res, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;
	void	*res_f;

	res = NULL;
	while (lst != NULL)
	{
		if (lst->content != NULL)
			res_f = f(lst->content);
		else
			res_f = NULL;
		if (res_f == NULL)
			return (my_ft_lstclear(&res, del));
		tmp = ft_lstnew(res_f);
		if (tmp == NULL)
		{
			del(res_f);
			ft_lstclear(&res, del);
			return (res);
		}
		ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	return (res);
}

static void	*my_ft_lstclear(t_list **p_res, void (*del)(void *))
{
	ft_lstclear(p_res, del);
	return (NULL);
}

/*
#include <stdio.h>

static void	*f1(void *s)
{
	int		s_len;
	int		i;
	void	*res;
	char	*res_c;

	s_len = ft_strlen((char *) s);
	res = malloc((s_len + 1) * sizeof(char));
	ft_memcpy(res, s, (s_len + 1) * sizeof(char));
	res_c = res;
	i = 0;
	while (res_c[i])
	{
		if (i % 3 == 0)
			res_c[i] = 'A';
		i++;
	}
	return (res);
}

static void	print_list(t_list *l1)
{
	while (l1 != NULL)
	{
		printf("- %s\n", (char *) l1->content);
		l1 = l1->next;
	}
}

int	main(void)
{
	t_list	*l;
	t_list	*l2;

	l = ft_lstnew(malloc(50 * sizeof(char)));
	if (l == NULL)
		return (1);
	ft_strlcpy(l->content, "yo la team", 50 * sizeof(char));
	l->next = ft_lstnew(malloc(50 * sizeof(char)));
	if (l->next == NULL)
		return (1);
	ft_strlcpy(l->next->content, "comment va ?", 50 * sizeof(char));
	l->next->next = ft_lstnew(malloc(50 * sizeof(char)));
	if (l->next->next == NULL)
		return (1);
	ft_strlcpy(l->next->next->content, "ca se passe ou?", 50 * sizeof(char));
	l2 = ft_lstmap(l, &f1, &free);
	if (l2 == NULL)
	{
		printf("on rentre ici ou on doit free la list l\n");
		ft_lstclear(&l, &free);
		return (1);
	}
	printf("l = \n");
	print_list(l);
	printf("l2 = \n");
	print_list(l2);
	ft_lstclear(&l, &free);
	ft_lstclear(&l2, &free);
	return (0);
}
*/
