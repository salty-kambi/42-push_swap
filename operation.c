/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:56:08 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/13 12:49:27 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_data *data)
{
	write(1, "sa\n", 3);
	if (data->bla && data->bla->next)
		ft_lstswap(data->bla, data->bla->next);
}

void	op_sb(t_data *data)
{
	write(1, "sb\n", 3);
	if (data->blb && data->blb->next)
		ft_lstswap(data->blb, data->blb->next);
}

void	op_ss(t_data *data)
{
	write(1, "ss\n", 3);
	if (data->bla && data->bla->next)
		ft_lstswap(data->bla, data->bla->next);
	if (data->blb && data->blb->next)
		ft_lstswap(data->blb, data->blb->next);
}

void	op_pa(t_data *data)
{
	t_list	*t;

	write(1, "pa\n", 3);
	if (!data->blb)
		return ;
	data->size_a++;
	data->size_b--;
	t = data->blb->next;
	if (data->blb->next)
		data->blb->next->prev = 0;
	update_index(data->blb->next, -1);
	data->blb->next = data->bla;
	if (data->bla)
		data->bla->prev = data->blb;
	update_index(data->bla, 1);
	data->bla = data->blb;
	data->blb = t;
}

void	op_pb(t_data *data)
{
	t_list	*t;

	write(1, "pb\n", 3);
	if (!data->bla)
		return ;
	data->size_a--;
	data->size_b++;
	t = data->bla->next;
	if (data->bla->next)
		data->bla->next->prev = 0;
	update_index(data->bla->next, -1);
	data->bla->next = data->blb;
	if (data->blb)
		data->blb->prev = data->bla;
	update_index(data->blb, 1);
	data->blb = data->bla;
	data->bla = t;
}
