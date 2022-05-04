/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:56:45 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/19 21:30:06 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data_init(argc, argv, &data, 0);
	if (data.size_a == 2)
		op_sa(&data);
	else if (data.size_a <= 24)
		tri_insert(&data);
	else
		tri_radix(&data);
	ft_lstclear(data.bla);
	ft_lstclear(data.blb);
}
