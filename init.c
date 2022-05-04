/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:33:22 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/19 21:29:34 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_tout_bien_ranger_dans_l_ordre_comme_il_faut(t_data *data)
{
	int		n;
	t_list	*l;

	if (data->blb)
		return (1);
	if (data->bla)
	{
		l = data->bla;
		n = l->n;
		while (l)
		{
			if (n > l->n)
				return (0);
			n = l->n;
			l = l->next;
		}
	}
	ft_lstclear(data->bla);
	ft_lstclear(data->blb);
	return (1);
}

void	put_order(t_data *data, int next_min, int x)
{
	t_list	*l;

	l = data->bla;
	while (l->n != next_min)
		l = l->next;
	l->x = x;
}

int	find_min(t_data *data)
{
	t_list	*l;
	int		min;

	l = data->bla;
	min = l->n;
	while (l)
	{
		if (l->n < min)
			min = l->n;
		l = l->next;
	}
	put_order(data, min, 1);
	return (min);
}

void	init_order(t_data *data)
{
	t_list	*l;
	int		x;
	int		min;
	int		next_min;

	x = 2;
	min = find_min(data);
	while (x <= data->size_a)
	{
		l = data->bla;
		next_min = 2147483647;
		while (l)
		{
			if (l->n > min && l->n < next_min)
				next_min = l->n;
			l = l->next;
		}
		put_order(data, next_min, x);
		x++;
		min = next_min;
	}
	data->max_d = max_digit(x);
}

void	data_init(int argc, char **argv, t_data *data, int n)
{
	if (argc == 1)
		exit(0);
	data->bla = le_parsing(argc, argv);
	data->blb = 0;
	if (check_tout_bien_ranger_dans_l_ordre_comme_il_faut(data))
	{
		if (n)
			write(1, "OK\n", 3);
		exit(0);
	}
	data->size_a = ft_lstsize(data->bla);
	data->size_b = 0;
	data->max_d = 0;
	init_order(data);
}
