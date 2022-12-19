/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2022/12/19 19:44:20 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		return (EXIT_FAILURE);
	if (!ft_creat_stacks(ac, &av[1], &a, &b))
		return (ft_putendl_fd("Error", STD_ERROR), 0);
	ft_sa_sb(&a);
	int	i = ft_pope(&a);
	while (i)
	{
		printf("-> %d\n", i);
		i = ft_pope(&a);
	}
	return (0);
}

void	ft_sa_sb(t_stack *stack)
{
	int	tmp;
	int	tmp2;

	if (stack->top <= 0)
		return ;
	tmp = ft_pope(stack);
	tmp2 = ft_pope(stack);
	ft_push(stack, tmp);
	ft_push(stack, tmp2);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa_sb(a);
	ft_sa_sb(b);
}

void	ft_pa_pb(t_stack *f, t_stack *s)
{
	if (s->top < 0)
		return ;
	ft_push(f, ft_pope(s));
}

void	ft_ra_rb(t_stack *f, t_stack *s)
{
	int	tmp;

	tmp = ft_pope(f);
	while (ft_pa_pb(b, a))
}

/*int	*ft_process_input(char **av, int *count, int *arr, int flag)
{
	int		i;
	char	**elem;
	int		j;

	j = 0;
	if (flag == FILL)
		arr = (int *) malloc(sizeof(int) * (*count));
	while (*(++av))
	{
		elem = ft_split(*av, ' ');
		i = 0;
		while (elem[i])
		{
			if (flag == COUNT)
				(*count)++;
			if (flag == FILL)
			{
				arr[j++] = ft_atoi(elem[i]);
				if (!arr[j - 1] && ft_strlen(elem[i]) > 1)
					return (ft_putendl_fd("Error \n", 2), 0);
			}
			free(elem[i++]);
		}
		free(elem);
	}
	return (arr);
}*/
