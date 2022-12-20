/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:03:45 by oezzaou           #+#    #+#             */
/*   Updated: 2022/12/20 17:34:12 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_pope(t_stack *stack)
{
	if (stack->top == -1)
	{
		ft_putendl_fd("Stack is Empty", 2);
		exit(EXIT_FAILURE);
	}
	return ((stack->stack)[stack->top--]);
}

void	ft_push(t_stack *stack, int elem)
{
	(stack->stack)[++(stack->top)] = elem;
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

int	*ft_extract_nbrs(char **av, int *count)
{
	int		*tmp;
	char	**tab;
	int		i;

	*count = ft_count_nbrs(av);
	tmp = (int *) malloc(sizeof(int) * *count);
	if (!*count || !tmp)
		return  (0);
	i = 0;
	while (*av)
	{
		tab = ft_split(*av++, ' ');
		while (*tab)
		{
			tmp[i++] = ft_atoi(*tab);
			if (!tmp[i - 1] && ft_strlen(*tab) > 1)
				return (0);
			free(*tab++);
		}
	}
	return (tmp);
}

int	ft_creat_stacks(int count, char **av, t_stack *a, t_stack *b)
{
	int		i;
	int		j;

	(void)count;
	b->stack = ft_extract_nbrs(av, &count);
	a->stack = (int *) malloc (sizeof(int) * count);
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
		ft_push(a, (b->stack)[count - i - 1]);
	return (count);
}
