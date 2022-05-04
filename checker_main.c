/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:40:38 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/19 21:29:23 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_error(t_data *data, char *s)
{
	write(2, "Error\n", 6);
	free(s);
	ft_lstclear(data->bla);
	ft_lstclear(data->blb);
	exit(1);
}

int	stcmp(const char *s1, const char *s2)
{
	int	x;

	x = 0;
	while (s1[x] && s2[x] && (s1[x] == s2[x]))
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

void	input_parse(t_data *data, char *s)
{
	if (!stcmp(s, "sa\n"))
		op_sas(data);
	else if (!stcmp(s, "sb\n"))
		op_sbs(data);
	else if (!stcmp(s, "ss\n"))
		op_sss(data);
	else if (!stcmp(s, "pa\n"))
		op_pas(data);
	else if (!stcmp(s, "pb\n"))
		op_pbs(data);
	else if (!stcmp(s, "ra\n"))
		op_ras(data);
	else if (!stcmp(s, "rb\n"))
		op_rbs(data);
	else if (!stcmp(s, "rr\n"))
		op_rrs(data);
	else if (!stcmp(s, "rra\n"))
		op_rras(data);
	else if (!stcmp(s, "rrb\n"))
		op_rrbs(data);
	else if (!stcmp(s, "rrr\n"))
		op_rrrs(data);
	else
		input_error(data, s);
	free(s);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*s;
	int		x;

	data_init(argc, argv, &data, 1);
	x = 1;
	while (x || s)
	{
		x = 0;
		s = get_next_line(0);
		if (s)
			input_parse(&data, s);
	}
	if (!check_order_list(data.bla) && !data.blb)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(data.bla);
	ft_lstclear(data.blb);
}
