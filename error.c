/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:29:27 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/12 21:52:08 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	l_error(t_list *l)
{
	ft_lstclear(l);
	write(2, "Error\n", 6);
	exit(1);
}

int	full_zero(char *s)
{
	int	x;

	x = 1;
	while (ft_isdigit(s[x]))
	{
		if (s[x] != '0')
			return (1);
		x++;
	}
	return (0);
}

void	check_int(t_list *l, char *s)
{
	int	x;

	x = 0;
	if (s[x] == '-')
		x++;
	if (!ft_isdigit(s[x]))
		l_error(l);
	while (ft_isdigit(s[x]))
		x++;
	if ((x < 10 && s[0] != '-') || (x < 11 && s[0] == '-'))
		return ;
	if (s[0] == '-' && ft_atoi(s) == 0 && full_zero(s))
		l_error(l);
	if (s[0] != '-' && ft_atoi(s) == -1)
		l_error(l);
}

void	check_double(t_list *l, int n)
{
	while (l)
	{
		if (l->n == n)
			l_error(l);
		l = l->next;
	}
}

void	check_digit(t_list *l, char *s)
{
	int	x;

	x = 0;
	if (s[x] == '-')
		x++;
	while (s[x])
	{
		if (!ft_isdigit(s[x]))
			l_error(l);
		x++;
	}
}
