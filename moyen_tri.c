/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moyen_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:17:01 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/16 14:44:30 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_radix(t_data *data)
{
	int	j;
	int	size;

	while (data->max_d)
	{
		j = 0;
		size = data->size_a;
		while (j < size && check_order_list(data->bla))
		{
			if (data->bla->x % 2 == 0)
			{
				data->bla->x /= 2;
				op_pb(data);
			}
			else
			{
				data->bla->x /= 2;
				op_ra(data);
			}
			j++;
		}
		while (data->blb)
			op_pa(data);
		data->max_d--;
	}
}
