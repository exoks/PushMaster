/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/14 01:29:27 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

/*void	ft_sort_three(t_stack *a, t_stack *b)
{
	int	max[2];
	int	min[2];
	int	tmp[3];
	int	i;

	i = -1;
	while (++i < 3)
		tmp[i] = ft_pop(a);
	i = -1;
	while (++i < 3)
		ft_push(a, tmp[i], 0);
	ft_get_limits(a, max, MAX);
	ft_get_limits(a, min, MIN);
	while (1)
	{
		if (tmp[0] = max[0])
			ft_rotate(a, b, RA);
		else if (tmp[2] = min[0])
			ft_rev_rotate(a, b, RRA);
	}
}*/

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		return (0);
	if (!ft_creat_stacks(ac, &av[1], &a, &b))
		return (ft_putendl_fd("Error", STD_ERROR), 0);
	if (ft_is_sorted(&a))
		return (free(a.stack), free(b.stack), 0);
	ft_redistribution(&a, &b, 15);
	ft_sort(&a, &b, MAX);
//	ft_print_stack(&a);
	return (0);
}
