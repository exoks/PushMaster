/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:56:23 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/17 21:39:41 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>
# include <limits.h>
# define STD_ERROR 2
# define STD_OUT 1
# define TRUE 1
# define FALSE 0
# define ALL 3
# define SOME 4
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"
# define MAX 2
# define MIN 3
# define IS_STACK_SORTED 10
# define IS_ELEM_REPETITIVE 11

typedef long long int t_ll;

typedef struct s_stack
{
	int			top;
	int			*stack;
	int			n_elems;
}				t_stack;

t_ll	ft_atoi_plus(char *s);
int 	ft_check(t_stack *s, int flag);
void	ft_sort_three(t_stack *a, t_stack *b);
void    ft_redistribution(t_stack *a, t_stack *b, int range);
void    ft_sort(t_stack *a, t_stack *b, int steps, int flag);
void	ft_get_limits(t_stack *s, int *limits, int flag);
int		ft_get_index(int *s, int nbr);
int		ft_pick_one(t_stack *s);
void	ft_rev_rotate(t_stack *f, t_stack *s, char *msg);
void	ft_rotate(t_stack *f, t_stack *s, char *msg);
void	ft_swap(t_stack *f, t_stack *s, char *msg);
void	ft_push(t_stack *stack, int elem, char *msg);
int		ft_pop(t_stack *stack);
int		ft_creat_stacks(char **av, t_stack *a, t_stack *b);

void	ft_print_stack(t_stack *s);
#endif
