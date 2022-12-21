/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:56:23 by oezzaou           #+#    #+#             */
/*   Updated: 2022/12/21 19:45:10 by oezzaou          ###   ########.fr       */
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
# define SA ":\033[1;36m=> \033[1;32msa\033[1;0m"
# define SB ":\033[1;36m=> \033[1;32msb\033[1;0m"
# define SS ":\033[1;36m=> \033[1;32mss\033[1;0m"
# define PA ":\033[1;36m=> \033[1;32mpa\033[1;0m"
# define PB ":\033[1;36m=> \033[1;32mpb\033[1;0m"
# define RA ":\033[1;36m=> \033[1;32mra\033[1;0m"
# define RB ":\033[1;36m=> \033[1;32mrb\033[1;0m"
# define RR ":\033[1;36m=> \033[1;32mrr\033[1;0m"
# define RRA ":\033[1;36m=> \033[1;32mrra\033[1;0m"
# define RRB ":\033[1;36m=> \033[1;32mrrb\033[1;0m"

typedef struct s_stack
{
	int			top;
	int			*stack;
	int			n_elems;
}				t_stack;

void    ft_print_stack(t_stack *stack);
void    ft_print_main_stack(t_stack *b, int count);
void	ft_rra_rrb(t_stack *f, t_stack *s, char *msg);
void	ft_rotate(t_stack *f, t_stack *s, char *msg);
void	ft_swap(t_stack *f, t_stack *s, char *msg);
int		ft_push(t_stack *stack, int elem, char *msg);
int		ft_pope(t_stack *stack);
int		ft_creat_stacks(int count, char **av, t_stack *a, t_stack *b);
int		ft_count_nbrs(char **av);
int		*ft_extract_nbrs(char **av, int *count);
#endif
