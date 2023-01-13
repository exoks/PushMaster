/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/13 23:53:26 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*ft_help_arr(t_stack *s)
{
	int	*arr;
	int	i;
	int	j;
	int	tmp;

	arr = (int *) malloc(sizeof(int) * (s->top + 1));
	if (!arr)
		return (0);
	i = -1;
	while (++i <= s->top)
		arr[i] = (s->stack)[i];
	i = -1;
	while (++i <= s->top)
	{
		j = i;
		while (++j <= s->top)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return (arr);
}

void	ft_sort(t_stack *a, t_stack *b, int flag)
{
	int	max[2];
	int	tmp;

	max[0] = ft_pick_one(b);
	max[1] = max[0];
	while (b->top > -1)
	{
		tmp = ft_pick_one(b);
		max[0] = tmp;
		ft_get_limits(b, &max[0], flag);
		if (tmp == max[0])
			ft_push(a, ft_pop(b), PA);
		else if (max[1] < (b->top / 2))
			ft_rev_rotate(b, a, RRB);
		else
			ft_rotate(b, a, RB);
	}
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

void	ft_redistribution(t_stack *a, t_stack *b, int range)
{
	int	index;
	int	*guide;
	int	tmp;

//	if (range == 0)
//		ft_sort_three(a, b);
	guide = ft_help_arr(a);
	while (a->top != -1)
	{
		tmp = ft_pick_one(a);
		index = ft_get_index(guide, tmp);
		if ((index >= b->top + 1 && index <= b->top + 1 + range)
				|| index < b->top + 1)
		{
			ft_push(b, ft_pop(a), PB);
			if (index < b->top + 1)
				ft_rotate(b, a, RB);
		}
		else
			ft_rotate(a, b, RA);
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
//	if (ft_is_sorted(&a))
//		return (free(a.stack), free(b.stack), 0);
	ft_redistribution(&a, &b, 15);
	ft_sort(&a, &b, MAX);
//	ft_print_stack(&a);
	return (0);
}

void	ft_swap(t_stack *f, t_stack *s, char *msg)
{
	int	tmp;
	int	tmp2;

	if (f->top <= 0)
		return ;
	tmp = ft_pop(f);
	tmp2 = ft_pop(f);
	ft_push(f, tmp, 0);
	ft_push(f, tmp2, 0);
	if (s)
		ft_swap(s, 0, 0);
	ft_putendl_fd(msg, STD_OUT);
}

void	ft_rotate(t_stack *f, t_stack *s, char *msg)
{
	int	tmp;
	int	top;

	if (f->top <= 0)
		return ;
	top = s->top;
	tmp = ft_pop(f);
	while (f->top > -1)
		ft_push(s, ft_pop(f), 0);
	ft_push(f, tmp, 0);
	while (s->top != top)
		ft_push(f, ft_pop(s), 0);
	if (msg && !ft_strncmp(msg, RR, ft_strlen(msg)))
		ft_rotate(s, f, 0);
	ft_putendl_fd(msg, STD_OUT);
}

void	ft_rev_rotate(t_stack *f, t_stack *s, char *msg)
{
	int	tmp;
	int	top;

	if (f->top <= 0)
		return ;
	top = s->top;
	while (f->top > 0)
		ft_push(s, ft_pop(f), 0);
	tmp = ft_pop(f);
	while (s->top != top)
		ft_push(f, ft_pop(s), 0);
	ft_push(f, tmp, 0);
	if (msg && !ft_strncmp(msg, RRR, ft_strlen(msg)))
		ft_rev_rotate(s, f, 0);
	ft_putendl_fd(msg, STD_OUT);
}
