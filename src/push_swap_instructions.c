/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:52:15 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/20 00:42:22 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//====<[ ft_pop: ]>=============================================================
int	ft_pop(t_stack *s)
{
	if (s->top == -1)
		exit(EXIT_FAILURE);
	return ((s->stack)[s->top--]);
}

//====<[ ft_push: ]>============================================================
void	ft_push(t_stack *s, int elem, char *msg)
{
	if (s->size == s->top)
		return ;
	(s->stack)[++(s->top)] = elem;
	ft_putendl_fd(msg, STD_OUT);
}

//====<[ ft_swap: ]>============================================================
void	ft_swap(t_stack *f, t_stack *s, char *msg)
{
	int	tmp;
	int	tmp2;

	if (f->top <= 0)
		return ;
	tmp = ft_pop(f);
	tmp2 = ft_pop(f);
	ft_push(f, tmp, 0);
	ft_push(f, tmp2, 0);
	if (s)
		ft_swap(s, 0, 0);
	ft_putendl_fd(msg, STD_OUT);
}

//====<[ ft_rotate: ]>==========================================================
void	ft_rotate(t_stack *f, t_stack *s, char *msg)
{
	int	tmp;
	int	top;

	if (f->top <= 0)
		return ;
	top = s->top;
	tmp = ft_pop(f);
	while (f->top > -1)
		ft_push(s, ft_pop(f), 0);
	ft_push(f, tmp, 0);
	while (s->top != top)
		ft_push(f, ft_pop(s), 0);
	if (msg && !ft_strncmp(msg, RR, ft_strlen(msg)))
		ft_rotate(s, f, 0);
	ft_putendl_fd(msg, STD_OUT);
}

//====<[ ft_rev_rotate: ]>======================================================
void	ft_rev_rotate(t_stack *f, t_stack *s, char *msg)
{
	int	tmp;
	int	top;

	if (f->top <= 0)
		return ;
	top = s->top;
	while (f->top > 0)
		ft_push(s, ft_pop(f), 0);
	tmp = ft_pop(f);
	while (s->top != top)
		ft_push(f, ft_pop(s), 0);
	ft_push(f, tmp, 0);
	if (msg && !ft_strncmp(msg, RRR, ft_strlen(msg)))
		ft_rev_rotate(s, f, 0);
	ft_putendl_fd(msg, STD_OUT);
}
