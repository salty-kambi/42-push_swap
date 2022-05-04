/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:21:12 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/14 21:22:33 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rrs(t_data *data)
{
	op_ras(data);
	op_rbs(data);
}

void	op_rrrs(t_data *data)
{
	op_rras(data);
	op_rrbs(data);
}
