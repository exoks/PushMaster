/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/10 01:40:52 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

// with recursivety
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

int	ft_check_whos_near(t_stack *s, int *arr, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= s->top)
	{
		j = -1;
		while (arr[++j] <= len)
			if ((s->stack)[s->top - i] == arr[j])
				return (s->top - i);
		j = -1;
		while (arr[++j] <= len)
			if ((s->stack)[i] == arr[j])
				return (i);
	}
	return (-1);
}

void	ft_best_algo(t_stack *a, t_stack *b, int flag)
{
	int	limits[2];
	int	tmp;
	int	pos;
	char	*msg1;
	char	*msg2;
	char	*msg3;

	msg1 = PA;
	msg2 = RRB;
	msg3 = RB;
	if (flag == MIN)
	{
		msg1 = PB;
		msg2 = RRA;
		msg3 = RA;
	}
        limits[0] = ft_pope(b);
 	limits[1] = limits[0];
        ft_push(b, limits[0], 0);
        while (1)
        {
                tmp = ft_pope(b);
                ft_push(b, tmp, 0);
                limits[0] = tmp;
                ft_get_limits(b, &limits[0], flag);
                pos = limits[1];
                if (tmp == limits[0])
                        ft_push(a, ft_pope(b), msg1);
                else if (pos < (b->top / 2))
                        ft_r_rotate(b, a, msg2);
                else
                      ft_rotate(b, a, msg3);
                if (b->top == -1/* || (ft_is_sorted(a) && flag == MIN)*/)
                {
                       // while (a->top < b->top && flag != MAX)
                      //          ft_push(a, ft_pope(b), PA);
                        break;
                }
        }
}

int     ft_is_exist(t_stack *s, int reference)
{
        int     i;

        i = -1;
        while (++i <= s->top)
                if ((s->stack)[i] <= reference)
                        return (1);
        return (0);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
//	int	limits[2];
	int	tmp;
//	int	pos;

	if (ac == 1)
		return (EXIT_FAILURE);
	if (!ft_creat_stacks(ac, &av[1], &a, &b))
		return (ft_putendl_fd("Error", STD_ERROR), 0);
	
//	ft_print_main_stack(&b, ac - 1);
	
//	int	*arr = ft_help_arr(&a);
	/*int	i = -1;
	while (++i <= a.top)
		printf(" %d ", arr[i]);
	printf("\n");*/
// it work only in case of separated args 

/******************* (update below algo) ****************************/
	int	reference;
	int	ref[50];
	int	i;

	i = -1;
	while (++i < 23)
		ref[i] = (ft_help_arr(&a))[((a.top * (i + 1))) / 23];
	reference = ref[1];
	i = 1;
	while (1)
	{
		//printf("reference :=> %d\n", reference);
		tmp = ft_pope(&a);
		int	tmp1 = ft_pope(&a);
		ft_push(&a, tmp1, 0);
		ft_push(&a, tmp, 0);
//		int	index = ft_check_whos_near(&a, arr, reference);
		if (tmp <= reference)
		{
			ft_push(&b, ft_pope(&a), PB);
			int	t1 = ft_pope(&b);
			ft_push(&b, t1, 0);
			if (b.top >= 1 && t1 <= ref[i - 1])
				ft_rotate(&b, &a, RB);
		}
		else
			ft_rotate(&a, &b, RA);
//		else
//			ft_r_rotate(&a, &b, RRA);
		if (i == 22)
		{
		//	ft_push(&b, ft_pope(&a), PB);
			ft_best_algo(&b, &a, MIN);
			ft_best_algo(&a, &b, MAX);
			break;
		}
		if (!ft_is_exist(&a, reference) && i < 22)
		{
			i++;
			reference = ref[++i];
		}
	}
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

// SOME TIPES TO PROVE MY CODE
	// 1 ===> TRY TO SEND SHANK AND SORTED AND RETURE IT (don't send it again)
	// 2 ===> THE last solution is to include rrr and rr
