/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:03:45 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/17 21:46:48 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
			if ((*av)[i] != ' ' && ((*av)[i + 1] == ' ' || (*av)[i + 1] == '\0'))
				count++;
		av++;
	}
	return (count);
}

int	ft_extract_nbrs(char **av, t_stack *a, t_stack *b)
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
			nb = ft_atoi_plus(tab[i]);
			if (nb > INT_MAX || nb < INT_MIN 
					|| (nb == 0 && !ft_strchr("+-", *tab[i]) && ft_strlen(tab[i]) > 2))
				re = FALSE;
			ft_push(b, nb, 0);
			free(tab[i]);
		}
		free(tab);
	}
	// CHECK IF THERE IS ANY REPETION
	while (b->top > -1)
	{
		if (!ft_check(b, IS_ELEM_REPETITIVE))
			return (FALSE);
		ft_push(a, ft_pop(b), 0);
	}
	//I NEED TO CHECK IF THERE IS 
	return (re);
}

int	ft_creat_stacks(char **av, t_stack *a, t_stack *b)
{
	int		count;

	count = ft_count_nbrs(av);
	a->stack = (int *) malloc (sizeof(int) * count);
	b->stack = (int *) malloc (sizeof(int) * count);
	if (!a->stack || !b->stack)
		return (free(a->stack), free(b->stack), FALSE);
	a->n_elems = count;
	b->n_elems = count;
	a->top = -1;
	b->top = -1;
	if (ft_extract_nbrs(av, a, b) == FALSE)
		return (0);
	return (count);
}

void	ft_print_stack(t_stack *s)
{
	int	tmp;

	if (s->top == -1)
		return ;
	tmp = ft_pop(s);
	printf(" %d \n", tmp);
	ft_print_stack(s);
	ft_push(s, tmp, 0);
}
