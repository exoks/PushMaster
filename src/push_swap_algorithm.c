/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:15:48 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/19 21:44:52 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*ft_guide_arr(t_stack *s, int flag)
{
	int	*guide;
	int	i;
	int	j;
	int	tmp;

	guide = (int *) malloc(sizeof(int) * (s->top + 1));
	if (!guide)
		return (0);
	i = -1;
	while (++i <= s->top)
		guide[i] = (s->stack)[i];
	if (flag == CREAT)
		return (guide);
	i = -1;
	while (++i <= s->top)
	{
		j = i;
		while (++j <= s->top)
		{
			if (guide[i] > guide[j])
			{
				tmp = guide[i];
				guide[i] = guide[j];
				guide[j] = tmp;
			}
		}
	}
	return (guide);
}

void	ft_sort_three(t_stack *a, t_stack *b)
{
	int	max[2];
	int	min[2];
	int	*tmp;
//	int	i;

	while (!ft_check(a, IS_STACK_SORTED))
	{
		int     top = a->top;
		/*i = top + 1;
		while (--i >= 0)
			tmp[top - i] = ft_pop(a);
		i = top + 1;
		while (--i >= 0)
			ft_push(a, tmp[i], 0);*/
		tmp = ft_guide_arr(a, CREAT);
		int	 i = -1;
		while (++i <= a->top)
			printf("tmp[i] :=> %d\n", tmp[i]);
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

void	ft_sort(t_stack *a, t_stack *b, int stp, int flag)
{
	int		max[2];
	int		tmp;
	char	*inst[3][2];

	inst[0][0] = PA;
	inst[0][1] = PB;
	inst[1][0] = RRB;
	inst[1][1] = RRA;
	inst[2][0] = RB;
	inst[2][1] = RA;
	while ((stp == ALL) * (a->top < a->n_elems - 1) + (stp == SOME) * (a->top < 1))
	{
		tmp = ft_pick_one(b);
		max[0] = tmp;
		ft_get_limits(b, &max[0], flag);
		if (tmp == max[0])
			ft_push(a, ft_pop(b), inst[0][!(stp == ALL)]);
		else if (max[1] < (b->top / 2))
			ft_rev_rotate(b, a, inst[1][!(stp == ALL)]);
		else
			ft_rotate(b, a, inst[2][!(stp == ALL)]);
	}
}

void	ft_redistribution(t_stack *a, t_stack *b, int range)
{
	int	index;
	int	*guide;
	int	tmp;

	guide = ft_guide_arr(a, CREAT | SWAP);
	while (a->top > -1)
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
