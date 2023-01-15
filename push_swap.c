/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/15 21:49:08 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int     main(int ac, char **av)
{
        t_stack a;
        t_stack b;

        if (ac == 1)
                return (0);
        if (!ft_creat_stacks(ac, &av[1], &a, &b))
                return (ft_putendl_fd("Error", STD_ERROR), 0);
        if (ft_is_sorted(&a))
                return (0);
        if (a.n_elems > 5)
        {
                ft_redistribution(&a, &b, 30);
                ft_sort(&a, &b, ALL, MAX);
                return (0);
        }
        if (a.n_elems > 3)
                ft_sort(&b, &a, SOME, MIN);
        ft_sort_three(&a, &b);
//      printf("\n========== A ==========\n");
//      ft_print_stack(&a);
        return (0);
}

void	ft_check(t_stack *s, int elem, int *res)
{
	int	tmp;

	if (s->top == -1)
		return ;
	tmp = ft_pop(s);
	if (elem > tmp && *res == TRUE)
		*res = FALSE;
	ft_check(s, tmp, res);
	ft_push(s, tmp, 0);
}

int	ft_is_sorted(t_stack *s)
{
	int	res;
	int	tmp;

	res = TRUE;
	tmp = ft_pop(s);
	ft_check(s, tmp, &res);
	ft_push(s, tmp, 0);
	return (res);
}
