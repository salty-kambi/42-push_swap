/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:51:52 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/16 14:23:47 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		x;
	long	res;
	int		fact;

	x = 0;
	res = 0;
	fact = 1;
	while (str[x] == ' ' || (str[x] >= '\t' && str[x] <= '\r'))
		x++;
	if (str[x] == '-')
	{
		x++;
		fact = -1;
	}
	else if (str[x] == '+')
		x++;
	while (str[x] >= '0' && str[x] <= '9')
	{
		res = res * 10 + str[x++] - '0';
		if (res > 2147483648 && fact == -1)
			return (0);
		else if (res > 2147483647 && fact == 1)
			return (-1);
	}
	return (res * fact);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	update_index(t_list *l, int n)
{
	while (l)
	{
		l->i += n;
		l = l->next;
	}
}

int	max_digit(int x)
{
	int	max_d;

	max_d = 0;
	while (x)
	{
		max_d++;
		x /= 2;
	}
	return (max_d);
}

int	check_order_list(t_list *l)
{
	int	n;

	n = l->n;
	while (l)
	{
		if (n > l->n)
			return (1);
		n = l->n;
		l = l->next;
	}
	return (0);
}
