/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:28:59 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/15 15:45:52 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_data *data)
{
	t_list	*la;
	t_list	*t;

	write(1, "ra\n", 3);
	if (!data->bla || data->size_a <= 1)
		return ;
	la = data->bla;
	t = data->bla->next;
	while (la->next)
		la = la->next;
	data->bla->next->prev = 0;
	update_index(data->bla->next, -1);
	data->bla->next = 0;
	data->bla->prev = la;
	la->next = data->bla;
	data->bla->i = la->i + 1;
	data->bla = t;
}

void	op_rb(t_data *data)
{
	t_list	*lb;
	t_list	*t;

	write(1, "rb\n", 3);
	if (!data->blb || data->size_b <= 1)
		return ;
	lb = data->blb;
	t = data->blb->next;
	while (lb->next)
		lb = lb->next;
	data->blb->next->prev = 0;
	update_index(data->blb->next, -1);
	data->blb->next = 0;
	data->blb->prev = lb;
	lb->next = data->blb;
	data->blb->i = lb->i + 1;
	data->blb = t;
}

void	op_ras(t_data *data)
{
	t_list	*la;
	t_list	*t;

	if (!data->bla || data->size_a <= 1)
		return ;
	la = data->bla;
	t = data->bla->next;
	while (la->next)
		la = la->next;
	data->bla->next->prev = 0;
	update_index(data->bla->next, -1);
	data->bla->next = 0;
	data->bla->prev = la;
	la->next = data->bla;
	data->bla->i = la->i + 1;
	data->bla = t;
}

void	op_rbs(t_data *data)
{
	t_list	*lb;
	t_list	*t;

	if (!data->blb || data->size_b <= 1)
		return ;
	lb = data->blb;
	t = data->blb->next;
	while (lb->next)
		lb = lb->next;
	data->blb->next->prev = 0;
	update_index(data->blb->next, -1);
	data->blb->next = 0;
	data->blb->prev = lb;
	lb->next = data->blb;
	data->blb->i = lb->i + 1;
	data->blb = t;
}

void	op_rr(t_data *data)
{
	write(1, "rr\n", 3);
	op_ras(data);
	op_rbs(data);
}
