/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:56:23 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/24 15:47:09 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//====<[ Include guards: ]>=====================================================
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//====<[ Headers: ]>============================================================
# include "libft.h"
# include <limits.h>

//====<[ Macros: ]>=============================================================
# define STD_ERROR 2
# define STD_OUT 1
# define TRUE 1
# define FALSE 0

//====<[ Flags: guide ]>==========================
# define CREAT 11
# define SORT 12

//====<[ Flags: ft_sort ]>========================
# define ALL 3
# define SOME 4

//====<[ Instructions: ]>=========================
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

//====<[ Flags: ft_get_limits ]>==================
# define MAX 5
# define MIN 6

//====<[ Flags: ft_check ]>=======================
# define IS_STACK_SORTED 10
# define IS_STACK_REV_SORTED 11
# define IS_ELEM_REPETITIVE 12

//===<[ typedef: ]>=============================================================
typedef long long int	t_ll;

typedef struct s_stack
{
	int			top;
	int			*stack;
	int			size;
}				t_stack;

//====<[ Prototypes: ]>=========================================================
void	ft_swap_nbrs(int *a, int *b);
t_ll	ft_atoi_plus(char *s);
int		ft_check(t_stack *s, int flag);
void	ft_sort_three(t_stack *a, t_stack *b);
void	ft_redistribution(t_stack *a, t_stack *b, int range);
void	ft_sort(t_stack *a, t_stack *b, int steps, int flag);
void	ft_get_limits(t_stack *s, int *limits, int flag);
int		ft_get_index(int *s, int nbr);
int		ft_pick_one(t_stack *s);
void	ft_rev_rotate(t_stack *f, t_stack *s, char *msg);
void	ft_rotate(t_stack *f, t_stack *s, char *msg);
void	ft_swap(t_stack *f, t_stack *s, char *msg);
void	ft_push(t_stack *stack, int elem, char *msg);
int		ft_pop(t_stack *stack);
int		ft_creat_stacks(char **av, t_stack *a, t_stack *b);

#endif
//==============================================================================
