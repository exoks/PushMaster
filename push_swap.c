/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2022/12/20 19:33:53 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_print_stack(t_stack *stack);
void	ft_rr(t_stack *f, t_stack *s);
void	ft_print_main_stack(t_stack *b, int count);

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		return (EXIT_FAILURE);
	if (!ft_creat_stacks(ac, &av[1], &a, &b))
		return (ft_putendl_fd("Error", STD_ERROR), 0);
	// it work only in case of separated args 
	ft_print_main_stack(&b, ac - 1);
	// push 3 element to stack b
	ft_pa_pb(&b, &a, PB);
	ft_pa_pb(&b, &a, PB);
	ft_pa_pb(&b, &a, PB);
	//rr to both A & B
	ft_rra_rrb(&a, &b, RRA);	
	printf("========== \033[1;36mSTACK A\033[1;0m ==========\n");
	ft_print_stack(&a);
	printf("========== \033[1;36mSTACK B\033[1;0m ==========\n");
	ft_print_stack(&b);
	return (0);
}

void	ft_print_main_stack(t_stack *b, int count)
{
	int	i;

	printf("========= \033[1;36mMAIN STACK\033[1;0m ========\n");
	i = -1;
	while (++i < count)
		printf("-> %-25d|\n", (b->stack)[i]);
	printf("=============================\n");
}

void	ft_print_stack(t_stack *stack)
{
	int	i;
	if (stack->top == -1)
		ft_putendl_fd("Empty Stack", STD_ERROR);
	while (stack->top > -1)
	{
		i = ft_pope(stack);
		printf("\033[1;32m->\033[1;0m %-25d|\n", i);
	}
	printf("=============================\n");
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

int	ft_pa_pb(t_stack *f, t_stack *s, char *msg)
{
	if (s->top < 0)
		return 0;
	ft_push(f, ft_pope(s));
	ft_putendl_fd(msg, 1);
	return (1);
}

void	ft_ra_rb(t_stack *f, t_stack *s, char *msg)
{
	int	tmp;
//	int	tmp2;
	int	i;

	// the problem that i have to swap the exact number from stack b to stack a
	if (f->top <= 0)
		return ;
	i = 0;
	tmp = ft_pope(f);
	while (ft_pa_pb(s, f, 0))
		++i;
	ft_push(f, tmp);
	while (i && ft_pa_pb(f, s, 0))
		i--;
	/*while(f->top > 0 && ft_pa_pb(s, f, 0))
		++i;
	tmp2 = ft_pope(f);
	ft_push(f, tmp);
	while (i && ft_pa_pb(f, s, 0))
		i--;
	ft_push(f, tmp2);*/
	ft_putendl_fd(msg, 1);
}

void	ft_rr(t_stack *f, t_stack *s)
{
	ft_ra_rb(s, f, 0);
	ft_ra_rb(f, s, 0);
	ft_putendl_fd(":=> rr", 1);
}

void	ft_rra_rrb(t_stack *f, t_stack *s, char *msg)
{
	int	tmp;
	int	i;

	if (f->top <= 0)
		return ;
	i = 0;
	while (f->top > 0 && ft_pa_pb(s, f, 0))
		++i;
	tmp = ft_pope(f);
	while (i && ft_pa_pb(f, s, 0))
		i--;
	ft_push(f, tmp);
	ft_putendl_fd(msg, 1);
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
