/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/24 15:31:20 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
	if (a.size > 5 && ft_check(&a, IS_STACK_REV_SORTED) <= (3 * a.size / 4))
	{
		ft_redistribution(&a, &b, a.size * 0.0375 + 11.75);
		ft_sort(&a, &b, ALL, MAX);
		return (free(a.stack), free(b.stack), EXIT_SUCCESS);
	}
	ft_sort(&b, &a, SOME * (a.size > 3), MIN);
	ft_sort_three(&a, &b);
	return (free(a.stack), free(b.stack), EXIT_SUCCESS);
}
