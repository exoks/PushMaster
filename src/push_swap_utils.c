/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:23:51 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/21 21:04:16 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//====<[ ft_swap_nbrs: ]>=======================================================
void	ft_swap_nbrs(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

//====<[ ft_atoi_plus: ]>=======================================================
t_ll	ft_atoi_plus(char *str)
{
	int		s;
	t_ll	nb;

	s = 1;
	nb = 0;
	while (ft_strchr("\n\t\r\v\f ", *str))
		str++;
	if (*str == '-')
		s = -s;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		nb = (nb * 10) + (*(str++) - '0');
	return (nb * s);
}

//====<[ ft_get_limits: ]>======================================================
void	ft_get_limits(t_stack *s, int *limits, int flag)
{
	int	tmp;

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

//====<[ ft_get_index: ]>=======================================================
int	ft_get_index(int *s, int nbr)
{
	if (*s != nbr)
		return (1 + ft_get_index(++s, nbr));
	return (0);
}

//====<[ ft_pick_one: ]>========================================================
int	ft_pick_one(t_stack *s)
{
	int	elem;

	elem = ft_pop(s);
	ft_push(s, elem, 0);
	return (elem);
}
