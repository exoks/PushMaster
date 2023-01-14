/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:15:48 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/14 17:59:06 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "push_swap.h"

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
	int     max[2];
	int     tmp;
        
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

void	ft_redistribution(t_stack *a, t_stack *b, int range)
{       
	int	index;
	int	*guide;
	int	tmp;

	guide = ft_help_arr(a);
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
