/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:32:36 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/14 23:55:41 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_data *data)
{
	t_list	*endl;

	write(1, "rra\n", 4);
	if (!data->bla || data->size_a <= 1)
		return ;
	update_index(data->bla, 1);
	endl = data->bla;
	while (endl->next)
		endl = endl->next;
	endl->prev->next = 0;
	endl->next = data->bla;
	endl->next->prev = endl;
	endl->i = 1;
	data->bla = endl;
}

void	op_rrb(t_data *data)
{
	t_list	*endl;

	write(1, "rrb\n", 4);
	if (!data->blb || data->size_b <= 1)
		return ;
	update_index(data->blb, 1);
	endl = data->blb;
	while (endl->next)
		endl = endl->next;
	endl->prev->next = 0;
	endl->next = data->blb;
	endl->next->prev = endl;
	endl->i = 1;
	data->blb = endl;
}

void	op_rras(t_data *data)
{
	t_list	*endl;

	if (!data->bla || data->size_a <= 1)
		return ;
	update_index(data->bla, 1);
	endl = data->bla;
	while (endl->next)
		endl = endl->next;
	endl->prev->next = 0;
	endl->next = data->bla;
	endl->next->prev = endl;
	endl->i = 1;
	data->bla = endl;
}

void	op_rrbs(t_data *data)
{
	t_list	*endl;

	if (!data->blb || data->size_b <= 1)
		return ;
	update_index(data->blb, 1);
	endl = data->blb;
	while (endl->next)
		endl = endl->next;
	endl->prev->next = 0;
	endl->next = data->blb;
	endl->next->prev = endl;
	endl->i = 1;
	data->blb = endl;
}

void	op_rrr(t_data *data)
{
	write(1, "rrr\n", 4);
	op_rras(data);
	op_rrbs(data);
}
