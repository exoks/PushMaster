/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:03:45 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/24 15:34:20 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//====<[ ft_search: ]>==========================================================
void	ft_search(t_stack *s, int elem, int *res, int flag)
{
	int	tmp;

	if (s->top == -1)
		return ;
	tmp = ft_pop(s);
	if (flag == IS_STACK_SORTED && elem > tmp && *res == TRUE)
		*res = FALSE;
	if (flag == IS_STACK_REV_SORTED && elem > tmp)
		*res += 1;
	if (flag == IS_ELEM_REPETITIVE && elem == tmp && *res == TRUE)
		*res = FALSE;
	if (flag == IS_STACK_SORTED || flag == IS_STACK_REV_SORTED)
		ft_search(s, tmp, res, flag);
	else
		ft_search(s, elem, res, flag);
	ft_push(s, tmp, 0);
}

//====<[ ft_check: ]>===========================================================
int	ft_check(t_stack *s, int flag)
{
	int	res;
	int	tmp;

	res = TRUE;
	tmp = ft_pop(s);
	ft_search(s, tmp, &res, flag);
	ft_push(s, tmp, 0);
	return (res);
}

//====<[ ft_count_nbrs: ]>======================================================
int	ft_count_nbrs(char **av)
{
	int	i;
	int	count;

	count = 0;
	while (*av)
	{
		i = -1;
		if (!**av)
			return (0);
		while ((*av)[++i])
			if ((*av)[i] != ' ' &&
					((*av)[i + 1] == ' ' || (*av)[i + 1] == '\0'))
				count++;
		av++;
	}
	return (count);
}

//====<[ ft_fill_stack: ]>======================================================
int	ft_fill_stack(char **av, t_stack *b)
{
	char	**tab;
	t_ll	nb;
	int		i;
	int		re;

	re = TRUE;
	while (*av)
	{
		tab = ft_split(*av++, ' ');
		i = -1;
		while (tab[++i])
		{
			nb = (ft_strchr("+-", *tab[i]) != NULL && ft_strlen(tab[i]) > 1);
			while (tab[i][nb])
				if (!ft_isdigit(tab[i][nb++]))
					re = FALSE;
			nb = ft_atoi_plus(tab[i]);
			if (nb > INT_MAX || nb < INT_MIN)
				re = FALSE;
			ft_push(b, nb, 0);
			free(tab[i]);
		}
		free(tab);
	}
	return (re);
}

//====<[ ft_creat_stacks: ]>====================================================
int	ft_creat_stacks(char **av, t_stack *a, t_stack *b)
{
	int		count;

	if (!av)
		return (FALSE);
	count = ft_count_nbrs(av);
	a->stack = (int *) malloc (sizeof(int) * count);
	b->stack = (int *) malloc (sizeof(int) * count);
	if (!(a->stack) || !(b->stack))
		return (free(a->stack), free(b->stack), FALSE);
	a->size = count;
	b->size = count;
	a->top = -1;
	b->top = -1;
	if (ft_fill_stack(av, b) == FALSE)
		return (free(a->stack), free(b->stack), FALSE);
	while (b->top > -1)
	{
		if (!ft_check(b, IS_ELEM_REPETITIVE))
			return (free(a->stack), free(b->stack), FALSE);
		ft_push(a, ft_pop(b), 0);
	}
	return (count);
}
