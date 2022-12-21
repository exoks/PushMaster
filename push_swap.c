/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2022/12/21 20:05:49 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		return (EXIT_FAILURE);
	if (!ft_creat_stacks(ac, &av[1], &a, &b))
		return (ft_putendl_fd("Error", STD_ERROR), 0);
	// it work only in case of separated args 
	ft_print_main_stack(&b, ac - 1);
	// push 3 element to stack b
	ft_push(&b, ft_pope(&a), PB);
	ft_push(&b, ft_pope(&a), PB);
	ft_push(&b, ft_pope(&a), PB);
	//rr to both A & B
	//ft_rra_rrb(&a, &b, RRA);
//	ft_rotate(&b, &a, RR);
	/************************* PRINT STACKS ***************************/
	printf("========== \033[1;36mSTACK A\033[1;0m ==========\n");
	ft_print_stack(&a);
	printf("========== \033[1;36mSTACK B\033[1;0m ==========\n");
	ft_print_stack(&b);
	return (0);
}

void	ft_swap(t_stack *f, t_stack *s, char *msg)
{
	int	tmp;
	int	tmp2;

	if (f->top <= 0)
		return ;
	tmp = ft_pope(f);
	tmp2 = ft_pope(f);
	ft_push(f, tmp, 0);
	ft_push(f, tmp2, 0);
	if (s)
		ft_swap(s, 0, 0);
	ft_putendl_fd(msg, 2);
}

void	ft_rotate(t_stack *f, t_stack *s, char *msg)
{
	int	tmp;
	int	i;

	(void)msg;
	if (f->top <= 0)
		return ;
	i = 0;
	tmp = ft_pope(f);
	while (ft_push(s, ft_pope(f), 0))
		++i;
	ft_push(f, tmp, 0);
	while (i && ft_push(f, ft_pope(s), 0))
		i--;
	printf("last \n");
//	if (!ft_strncmp(msg, ":=> rr", ft_strlen(RR)))
//		ft_rotate(s, f, 0);
//	ft_putendl_fd(msg, 2);
}

/*void	ft_rr(t_stack *f, t_stack *s)
{
	ft_ra_rb(s, f, 0);
	ft_ra_rb(f, s, 0);
	ft_putendl_fd(":=> rr", 1);
}*/

void	ft_rra_rrb(t_stack *f, t_stack *s, char *msg)
{
	int	tmp;
	int	i;

	if (f->top <= 0)
		return ;
	i = 0;
	while (f->top > 0 && ft_push(s, ft_pope(f), 0))
		++i;
	tmp = ft_pope(f);
	while (i && ft_push(f, ft_pope(s), 0))
		i--;
	ft_push(f, tmp, 0);
	ft_putendl_fd(msg, 1);
}
