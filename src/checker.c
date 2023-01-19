/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/19 21:21:44 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	*get_next_line(int fd);
void	apply_instructions(char *line, t_stack *a, t_stack *b);

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*line;

	if (ac == 1)
		return (EXIT_SUCCESS);
	if (!ft_creat_stacks(&av[1], &a, &b))
		return (ft_putendl_fd("Error", STD_ERROR), EXIT_FAILURE);
	line = get_next_line(0);
	while (line)
	{
		apply_instructions(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	if (ft_check(&a, IS_STACK_SORTED) && b.top == -1)
		ft_putendl_fd("OK", STD_OUT);
	else
		ft_putendl_fd("KO", STD_OUT);
	return (free(a.stack), free(b.stack), EXIT_SUCCESS);
}

void	apply_instructions(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(SA, line, ft_strlen(line)))
		ft_swap(a, 0, SA);
	else if (!ft_strncmp(SB, line, ft_strlen(line)))
		ft_swap(b, 0, SB);
	else if (!ft_strncmp(SS, line, ft_strlen(line)))
		ft_swap(a, b, SS);
	else if (!ft_strncmp(PA, line, ft_strlen(line)))
		ft_push(a, ft_pop(b), PA);
	else if (!ft_strncmp(PB, line, ft_strlen(line)))
		ft_push(b, ft_pop(a), PB);
	else if (!ft_strncmp(RA, line, ft_strlen(line)))
		ft_rotate(a, b, RA);
	else if (!ft_strncmp(RB, line, ft_strlen(line)))
		ft_rotate(b, a, RB);
	else if (!ft_strncmp(RR, line, ft_strlen(line)))
		ft_rotate(a, b, RR);
	else if (!ft_strncmp(RRA, line, ft_strlen(line)))
		ft_rev_rotate(a, b, RRA);
	else if (!ft_strncmp(RRB, line, ft_strlen(line)))
		ft_rev_rotate(b, a, RRB);
	else if (!ft_strncmp(RRR, line, ft_strlen(line)))
		ft_rev_rotate(a, b, RRR);
}

char	*get_next_line(int fd)
{
	char	c;
	char	*buff;
	char	*tmp;

	buff = ft_strdup("");
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		tmp = ft_strjoin(buff, &c);
		free(buff);
		buff = tmp;
	}
	if (!*buff)
		return (NULL);
	return (buff);
}
