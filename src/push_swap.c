/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/19 21:06:42 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//void	ft_show_stacks(t_stack *a, t_stack *b);

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	if (!ft_creat_stacks(&av[1], &a, &b))
		return (ft_putendl_fd("Error", STD_ERROR), EXIT_FAILURE);
	if (ft_check(&a, IS_STACK_SORTED))
		return (free(a.stack), free(b.stack), EXIT_SUCCESS);
	if (a.n_elems > 5)
	{
		ft_redistribution(&a, &b, 30);
		ft_sort(&a, &b, ALL, MAX);
		return (EXIT_SUCCESS);
	}
	if (a.n_elems > 3)
		ft_sort(&b, &a, SOME, MIN);
	ft_sort_three(&a, &b);
//	ft_show_stacks(&a, &b);
	return (EXIT_SUCCESS);
}
/*
void	ft_show_stacks(t_stack *a, t_stack *b)
{
	printf("\n========== A ==========\n");
	ft_print_stack(a);
	printf("\n========== B ==========\n");
	ft_print_stack(b);
}
*/
