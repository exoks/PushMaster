/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/11 23:31:26 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_get_limits(t_stack *s, int *limits, int flag)
{
	int	tmp;

	if (s->top == -1)
		return ;
	tmp = ft_pope(s);
	if ((flag == MIN) * (tmp < limits[0]) + (flag == MAX) * (tmp > limits[0]))
	{
		limits[0] = tmp;
		limits[1] = s->top + 1;
	}
	ft_get_limits(s, limits, flag);
	ft_push(s, tmp, 0);
}

int	ft_get_index(int *s, int nbr)
{
	if (*s != nbr)
		return (1 + ft_get_index(++s, nbr));
	return (0);
}

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

void	ft_best_algo(t_stack *a, t_stack *b, int flag)
{
	int	max[2];
	int	tmp;
	int	position;

	max[0] = ft_pope(b);
	max[1] = max[0];
	ft_push(b, max[0], 0);
	while (b->top > -1)
	{
		tmp = ft_pope(b);
		ft_push(b, tmp, 0);
		max[0] = tmp;
		ft_get_limits(b, &max[0], flag);
		position = max[1];
		if (tmp == max[0])
			ft_push(a, ft_pope(b), PA);
		else if (position < (b->top / 2))
			ft_rev_rotate(b, a, RRB);
		else
			ft_rotate(b, a, RB);
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int	tmp;
	int	index;
	int	*guide;

	if (ac == 1)
		return (EXIT_FAILURE);
	if (!ft_creat_stacks(ac, &av[1], &a, &b))
		return (ft_putendl_fd("Error", STD_ERROR), 0);
	guide = ft_help_arr(&a);
	while (a.top != -1)
	{
		tmp = ft_pope(&a);
		ft_push(&a, tmp, 0);
		index = ft_get_index(guide, tmp);
		if ((index >= b.top + 1 && index <= b.top + 22)
				|| index < b.top + 1)
		{
			ft_push(&b, ft_pope(&a), PB);
			if (index < b.top + 1)
				ft_rotate(&b, &a, RB);
		}
		else
			ft_rotate(&a, &b, RA);
	}
	ft_best_algo(&a, &b, MAX);
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
	ft_putendl_fd(msg, STD_OUT);
}

void	ft_rotate(t_stack *f, t_stack *s, char *msg)
{
	int	tmp;
	int	i;

	if (f->top <= 0)
		return ;
	i = 0;
	tmp = ft_pope(f);
	while (f->top > -1 && ft_push(s, ft_pope(f), 0))
		++i;
	ft_push(f, tmp, 0);
	while (i && ft_push(f, ft_pope(s), 0))
		i--;
	if (msg && !ft_strncmp(msg, RR, ft_strlen(msg)))
		ft_rotate(s, f, 0);
	ft_putendl_fd(msg, STD_OUT);
}

void	ft_rev_rotate(t_stack *f, t_stack *s, char *msg)
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
	if (msg && !ft_strncmp(msg, RRR, ft_strlen(msg)))
		ft_rev_rotate(s, f, 0);
	ft_putendl_fd(msg, STD_OUT);
}
