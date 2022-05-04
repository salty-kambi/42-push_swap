/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:21:12 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/13 19:19:03 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(t_list *bl, int n)
{
	t_list		*l;
	static int	i;

	l = malloc(sizeof(t_list));
	if (!l)
		l_error(bl);
	i++;
	l->i = i;
	l->n = n;
	l->next = 0;
	l->prev = 0;
	return (l);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*bl;

	bl = *alst;
	if (!new)
		l_error(bl);
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	while ((*alst)->next)
		*alst = (*alst)->next;
	(*alst)->next = new;
	new->prev = *alst;
	*alst = bl;
}

void	ft_lstswap(t_list *a, t_list*b)
{
	int	t;

	t = a->n;
	a->n = b->n;
	b->n = t;
	t = a->i;
	a->i = b->i;
	b->i = t;
}

void	ft_lstclear(t_list *lst)
{
	t_list	*t;

	while (lst)
	{
		t = lst->next;
		free(lst);
		lst = t;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
