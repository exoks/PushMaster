/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:56:23 by oezzaou           #+#    #+#             */
/*   Updated: 2022/12/20 19:28:21 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdio.h>
# define STD_ERROR 2
# define STD_OUT 1
# define TRUE 1
# define FALSE 0
# define SA ":\033[1;36m=> s\033[1;32ma\033[1;0m"
# define SB ":\033[1;36m=> s\033[1;32mb\033[1;0m"
# define SS ":\033[1;36m=> s\033[1;32ms\033[1;0m"
# define PA ":\033[1;36m=> \033[1;32mpa\033[1;0m"
# define PB ":\033[1;36m=> \033[1;32mpb\033[1;0m"
# define RA ":\033[1;36m=> \033[1;32mra\033[1;0m"
# define RB ":\033[1;36m=> \033[1;32mrb\033[1;0m"
# define RRA ":\033[1;36m=> \033[1;32mrra\033[1;0m"
# define RRB ":\033[1;36m=> \033[1;32mrrb\033[1;0m"
typedef struct s_stack
{
	int			top;
	int			*stack;
}				t_stack;

void	ft_rra_rrb(t_stack *f, t_stack *s, char *msg);
void	ft_ra_rb(t_stack *f, t_stack *s, char *msg);
int	ft_pa_pb(t_stack *f, t_stack *s, char *msg);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_sa_sb(t_stack *stack);
void	ft_push(t_stack *stack, int elem);
int		ft_pope(t_stack *stack);
int		ft_creat_stacks(int count, char **av, t_stack *a, t_stack *b);
int		ft_count_nbrs(char **av);
int		*ft_extract_nbrs(char **av, int *count);
#endif
