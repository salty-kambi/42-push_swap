/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:56:17 by lsuau             #+#    #+#             */
/*   Updated: 2021/12/11 18:09:07 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*little_parsing(char *s)
{
	t_list	*l;
	int		x;

	x = 0;
	l = 0;
	while (s[x])
	{
		if (ft_isdigit(s[x]) || s[x] == '-')
		{
			check_int(l, s + x);
			check_double(l, ft_atoi(s + x));
			ft_lstadd_back(&l, ft_lstnew(l, ft_atoi(s + x)));
			if (s[x] == '-')
				x++;
			while (ft_isdigit(s[x]))
				x++;
			if (s[x] == '-')
				l_error(l);
		}
		else if (s[x] == ' ')
			x++;
		else
			l_error(l);
	}
	return (l);
}

t_list	*big_parsing(int argc, char **argv)
{
	t_list	*l;
	int		x;

	x = 1;
	l = 0;
	while (x < argc)
	{
		check_digit(l, argv[x]);
		check_int(l, argv[x]);
		check_double(l, ft_atoi(argv[x]));
		ft_lstadd_back(&l, ft_lstnew(l, ft_atoi(argv[x])));
		x++;
	}
	return (l);
}

t_list	*le_parsing(int argc, char **argv)
{
	t_list	*l;

	l = 0;
	if (argc == 2)
		l = little_parsing(argv[1]);
	else if (argc > 2)
		l = big_parsing(argc, argv);
	return (l);
}
