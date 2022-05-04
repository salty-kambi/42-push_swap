/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:39:15 by lsuau             #+#    #+#             */
/*   Updated: 2022/01/14 14:50:31 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

//i = place actuelle dans la liste
//n = valeur
//x = place final du chiffre dans la liste
typedef struct s_list
{
	int				i;
	int				n;
	int				x;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	int		size_a;
	int		size_b;
	int		max_d;
	t_list	*bla;
	t_list	*blb;
}	t_data;

t_list	*le_parsing(int argc, char **argv);
void	check_int(t_list *l, char *s);
void	check_double(t_list *l, int n);
void	check_digit(t_list *l, char *s);
void	l_error(t_list *l);

void	op_sa(t_data *data);
void	op_sb(t_data *data);
void	op_ss(t_data *data);
void	op_pa(t_data *data);
void	op_pb(t_data *data);
void	op_ra(t_data *data);
void	op_rb(t_data *data);
void	op_rr(t_data *data);
void	op_rra(t_data *data);
void	op_rrb(t_data *data);
void	op_rrr(t_data *data);

void	op_sas(t_data *data);
void	op_sbs(t_data *data);
void	op_sss(t_data *data);
void	op_pas(t_data *data);
void	op_pbs(t_data *data);
void	op_ras(t_data *data);
void	op_rbs(t_data *data);
void	op_rrs(t_data *data);
void	op_rras(t_data *data);
void	op_rrbs(t_data *data);
void	op_rrrs(t_data *data);

int		check_tout_bien_ranger_dans_l_ordre_comme_il_faut(t_data *data);
void	tri_trois(t_data *data);
void	tri_cinq(t_data *data);
void	tri_insert(t_data *data);
void	tri_radix(t_data *data);

t_list	*ft_lstnew(t_list *bl, int n);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstswap(t_list *a, t_list*b);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list *lst);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

int		max_digit(int x);
void	update_index(t_list *l, int n);
int		check_order_list(t_list *l);
void	put_order(t_data *data, int next_min, int x);
void	init_order(t_data *data);
void	data_init(int argc, char **argv, t_data *data, int n);

#endif