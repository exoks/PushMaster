/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/14 22:53:30 by oezzaou          ###   ########.fr       */
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

void	ft_sort_three(t_stack *a, t_stack *b)
{
	int	max[2];
	int	min[2];
	int	tmp[3];
	int	i;

	while (!ft_is_sorted(a))
	{
		int	top = a->top;
		i = top + 1;
		while (--i >= 0)
			tmp[top - i] = ft_pop(a);
		i = top + 1;
		while (--i >= 0)
			ft_push(a, tmp[i], 0);
		max[0] = tmp[0];
		min[0] = tmp[0];
		ft_get_limits(a, max, MAX);
		ft_get_limits(a, min, MIN);
		if (tmp[0] == max[0])
			ft_rotate(a, b, RA);
		else if (tmp[top] == min[0])
			ft_rev_rotate(a, b, RRA);
		else if (tmp[0] > tmp[1])
			ft_swap(a, 0, SA);
		else
			ft_push(b, ft_pop(a), PB);
	}
	while (b->top > -1)
		ft_push(a, ft_pop(b), PA);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	int	min[2];
	int	tmp;

	while (a->top > 2)
	{
		min[0] = ft_pick_one(a);
		ft_get_limits(a, &min[0], MIN);
		tmp = ft_pick_one(a);
		if (tmp == min[0])
			ft_push(b, ft_pop(a), PB);
		else if (min[1] >= (a->top / 2))
			ft_rotate(a, b, RA);
		else
			ft_rev_rotate(a, b, RRA);
	}
}
int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	
	if (ac == 1)
		return (0);
	if (!ft_creat_stacks(ac, &av[1], &a, &b))
		return (ft_putendl_fd("Error", STD_ERROR), 0);
	if (ft_is_sorted(&a))
		return (0);
	printf("WHAT TO DO  -> %d\n", ALL * (a.n_elems > 5) + SOME * (a.n_elems <= 5));
	ft_sort(&a, &b, ALL * (a.n_elems > 5) + SOME * (a.n_elems <= 5), MAX);
//	if (a.n_elems <= 5)
//		ft_sort_three(&a, &b);
//	else
//		ft_redistribution(&a, &b, a.n_elems / 15);
//	printf("\n========== A ==========\n");
//	ft_print_stack(&a);
	return (0);
}
