/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/03 16:15:22 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rsort_stack(t_stack *a, t_stack *b);

int	ft_is_sorted(t_stack *a)
{
	int	*arr;
	int		i;
	int		j;

	arr = a->stack;
	i = -1;
	while (++i < a->top)
	{
		j = i;
		while (++j <= a->top)
			if (arr[i] <= arr[j])
				return (0);
	}
	return (1);
}

void	ft_rsort_stack(t_stack *a, t_stack *b)
{
	int	tmp0, tmp1;

	while (1)
	{
		tmp0 = ft_pope(a);
		if (a->top == -1)
		{
			ft_push(b, tmp0, 0); //PB
			break;
		}
		tmp1 = ft_pope(a);
		ft_push(a, tmp1, 0);
		ft_push(a, tmp0, 0);
		if (tmp0 < tmp1)
			ft_swap(a, 0, SA);
		ft_push(b, ft_pope(a), PB); //PB
	}
}
//int	ft_get_limits(t_stack *a, int flag);

/*void	ft_sort_stack(t_stack *a, t_stack *b)
{
	int	tmp0, tmp1;

	while (1)
	{
		tmp0 = ft_pope(a);
		if (a->top == -1)
			break;
		tmp1 = ft_pope(a);
		ft_push(a, tmp1, 0);
		ft_push(a, tmp0, 0);
		if (tmp0 == ft_get_limits(a, MAX) && tmp1 == ft_get_limits(a, MIN))
			ft_rotate(a, b, RA);
		else if (tmp0 > tmp1)
			ft_swap(a, 0, SA);
		if (ft_is_sorted(a))
			break;
		ft_rotate(a, b, RA);
	}
}*/


/*int	ft_get_limits(t_stack *a, int flag)
{
	int	tmp;
	int	i;

	tmp = a->stack[0];
	i = -1;
	while (++i <= a->top)
		if ((flag == MAX) * (tmp < a->stack[i]) + (flag == MIN) * (tmp > a->stack[i]))
			tmp = a->stack[i];
	return (tmp);
}*/

// with recursivety
void	ft_get_limits(t_stack *s, int *limits)
{
	int	tmp;

	if (s->top == -1)
		return ;
	tmp = ft_pope(s);
	if (tmp < limits[0])
	{
		limits[0] = tmp;
		limits[1] = s->top + 1;
	}
	ft_get_limits(s, limits);
	ft_push(s, tmp, 0);
}

int	ft_get_index(t_stack *s, int nbr)
{
	int	tmp;

	tmp = ft_pope(s);
	if (tmp != nbr)
		return (1 + ft_get_index(s, nbr));
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

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
//	int	limits[2];
//	int	tmp;
//	int	pos;

	if (ac == 1)
		return (EXIT_FAILURE);
	if (!ft_creat_stacks(ac, &av[1], &a, &b))
		return (ft_putendl_fd("Error", STD_ERROR), 0);
//	int	*arr = ft_help_arr(&a);
//	int	i = -1;
//	while (++i <= a.top)
//		printf(" %d ", arr[i]);
// it work only in case of separated args 
//	 ft_print_main_stack(&b, ac - 1);

/*int	ft_get_index(int nb, t_stack *s)
{
	int	tmp;

	tmp = ft_pope(s);
	if (nb != tmp)
		return (0 + ft_get_index(nb, s));
	ft_push(&a, 0, 0);
	return (s->top);
}*/

/******************* (update below algo) ****************************/

	printf(" %d ", ft_get_index(&a, 0));

/******************* (BEST ALGO (until now))*************************/
/*	limits[0] = ft_pope(&a);
	limits[1] = limits[0];
	ft_push(&a, limits[0], 0);
	while (1)
	{
		tmp = ft_pope(&a);
		ft_push(&a, tmp, 0);
		limits[0] = tmp;
		ft_get_limits(&a, &limits[0]);
		pos = limits[1];
		if (tmp == limits[0])
			ft_push(&b, ft_pope(&a), PB);
		else if (pos < (a.top / 2))
			ft_r_rotate(&a, &b, RRA);
		else if (pos >= (a.top / 2))
			ft_rotate(&a, &b, RA);
		if (a.top == -1 || ft_is_sorted(&a))
		{
			while (b.top > -1)
				ft_push(&a, ft_pope(&b), PA);
			break;
		}
	}*/
/******************************* (WORST ALGO) ******************************/
// 	while (!ft_is_sorted(&a))
//		ft_sort_stack(&a, &b);
/******************************** PRINT STACKS ***************************/
//	printf("========== \033[1;36mSTACK A\033[1;0m ==========\n");        
//	ft_print_stack(&a);
//	printf("========== \033[1;36mSTACK B\033[1;0m ==========\n");
//	ft_print_stack(&b);
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

void	ft_r_rotate(t_stack *f, t_stack *s, char *msg)
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
		ft_r_rotate(s, f, 0);
	ft_putendl_fd(msg, STD_OUT);
}

// After each operations you have to check both stacks if sorted
// 1|=> check if the max is on the top ra
// 2|=> if the last args are < max / 2 rra
// 3|=> 
