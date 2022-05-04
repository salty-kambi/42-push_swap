/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:19:33 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/14 21:20:38 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sas(t_data *data)
{
	if (data->bla && data->bla->next)
		ft_lstswap(data->bla, data->bla->next);
}

void	op_sbs(t_data *data)
{
	if (data->blb && data->blb->next)
		ft_lstswap(data->blb, data->blb->next);
}

void	op_sss(t_data *data)
{
	if (data->bla && data->bla->next)
		ft_lstswap(data->bla, data->bla->next);
	if (data->blb && data->blb->next)
		ft_lstswap(data->blb, data->blb->next);
}

void	op_pas(t_data *data)
{
	t_list	*t;

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

void	op_pbs(t_data *data)
{
	t_list	*t;

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
