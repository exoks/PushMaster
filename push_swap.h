/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:56:23 by oezzaou           #+#    #+#             */
/*   Updated: 2022/12/19 19:23:37 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>
# define STD_ERROR 2
# define STD_OUT 1

typedef struct s_stack
{
	int			top;
	int			*stack;
}				t_stack;

void	ft_pa_pb(t_stack *f, t_stack *s);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_sa_sb(t_stack *stack);
void	ft_push(t_stack *stack, int elem);
int		ft_pope(t_stack *stack);
int		ft_creat_stacks(int ac, char **av, t_stack *a, t_stack *b);
int		ft_count_nbrs(char **av);
int		*ft_extract_nbrs(char **av, int *count);
#endif
