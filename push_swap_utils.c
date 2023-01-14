/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:03:45 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/14 14:49:24 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_get_limits(t_stack *s, int *limits, int flag)
{
	int     tmp;

	if (s->top == -1)
		return ;
	tmp = ft_pop(s);
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

int	ft_pick_one(t_stack *s)
{
	int     elem;

	elem = ft_pop(s);
	ft_push(s, elem, 0);
	return (elem);
}

int	ft_count_nbrs(char **av)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (av[++i])
	{
		j = -1;
		if (!*av[i])
			return (0);
		while (av[i][++j])
			if (av[i][j] != ' ' && (av[i][j + 1] == ' ' || av[i][j + 1] == '\0'))
				count++;
	}
	return (count);
}

// This function needs to be optimazed more
int	*ft_extract_nbrs(char **av, int *count)
{
	int		*tmp;
	char	**tab;
	int		i;
	int		j;

	*count = ft_count_nbrs(av);
	tmp = (int *) malloc(sizeof(int) * *count);
	if (!*count || !tmp)
		return  (0);
	i = 0;
	while (*av)
	{
		tab = ft_split(*av++, ' ');
		j = -1;
		while (tab[++j])
		{
			tmp[i++] = ft_atoi(tab[j]);
			if (!tmp[i - 1] && ft_strlen(tab[j]) > 1)
				return (0);
			free(tab[j]);
		}
		free(tab);
	}
	return (tmp);
}

int	ft_creat_stacks(int count, char **av, t_stack *a, t_stack *b)
{
	int		i;
	int		j;

	count = 0;
	b->stack = ft_extract_nbrs(av, &count);
	a->stack = (int *) malloc (sizeof(int) * count);
	a->n_elems = count;
	b->n_elems = count;
	if (!a->stack || !b->stack)
		return (0);
	a->top = -1;
	b->top = -1;
	i = -1;
	while (++i < count)
	{
		j = i;
		while (++j < count)
			if ((b->stack)[i] == (b->stack)[j])
				return (0);
	}
	i = -1;
	while (++i < count)
		ft_push(a, (b->stack)[count - i - 1], 0);
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
