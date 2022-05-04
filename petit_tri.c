/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petit_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:02:38 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/14 20:42:25 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_trois(t_data *data)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = data->bla->n;
	n2 = data->bla->next->n;
	n3 = data->bla->next->next->n;
	if ((n1 < n2 && n1 < n3) && n2 > n3)
	{
		op_rra(data);
		op_sa(data);
	}
	else if ((n1 > n2 && n2 < n3) && n1 < n3)
		op_sa(data);
	else if ((n1 > n2 && n1 > n3) && n2 > n3)
	{
		op_sa(data);
		op_rra(data);
	}
	else if ((n1 > n2 && n1 > n3) && n2 < n3)
		op_ra(data);
	else
		op_rra(data);
}

void	put_min(t_data *data, int i)
{
	t_list	*l;
	int		x;

	l = data->bla;
	if (i > (data->size_a / 2))
	{
		x = data->size_a - i + 1;
		while (x)
		{
			op_rra(data);
			x--;
		}
		op_pb(data);
	}
	else
	{
		x = i - 1;
		while (x)
		{
			op_ra(data);
			x--;
		}
		op_pb(data);
	}
}

void	tri_insert(t_data *data)
{
	int		min;
	int		i;
	t_list	*la;

	while (check_order_list(data->bla) && data->size_a > 3)
	{
		la = data->bla;
		min = 2147483647;
		while (la)
		{
			if (min >= la->n)
			{
				i = la->i;
				min = la->n;
			}
			la = la->next;
		}
		put_min(data, i);
	}
	if (check_order_list(data->bla))
		tri_trois(data);
	while (data->blb)
		op_pa(data);
}
