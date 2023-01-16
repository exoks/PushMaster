/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2023/01/16 22:27:32 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	*get_next_line(int fd);
void	apply_instructions(char *line, t_stack *a, t_stack *b);

int     main(int ac, char **av)
{
        t_stack a;
        t_stack b;
		char	*line;

        if (ac == 1)
                return (0);
        if (!ft_creat_stacks(ac, &av[1], &a, &b))
                return (ft_putendl_fd("Error", STD_ERROR), 0);
        if (ft_is_sorted(&a))
                return (0);
//		printf("\n========== A ==========\n");
//		ft_print_stack(&a);
		line = get_next_line(0);
		while (line)
		{
			apply_instructions(line, &a, &b);
	//		printf("%s", line);
			/*if (!ft_strncmp(SA, line, ft_strlen(line)))
				ft_swap(&a, 0, SA);
			else if (!ft_strncmp(SB, line, ft_strlen(line)))
				ft_swap(&b, 0, SB);
			else if (!ft_strncmp(SS, line, ft_strlen(line)))
				ft_swap(&a, &b, SS);
			else if (!ft_strncmp(PA, line, ft_strlen(line)))
				ft_push(&a, ft_pop(&b), PA);
			else if (!ft_strncmp(PB, line, ft_strlen(line)))
				ft_push(&b, ft_pop(&a), PB);
			else if (!ft_strncmp(RA, line, ft_strlen(line)))
				ft_rotate(&a, &b, RA);
			else if (!ft_strncmp(RB, line, ft_strlen(line)))
				ft_rotate(&b, &a, RB);
			else if (!ft_strncmp(RR, line, ft_strlen(line)))
				ft_rotate(&a, &b, RR);
			else if (!ft_strncmp(RRA, line, ft_strlen(line)))
				ft_rev_rotate(&a, &b, RRA);
			else if (!ft_strncmp(RRB, line, ft_strlen(line)))
				ft_rev_rotate(&b, &a, RRB);
			else if (!ft_strncmp(RRR, line, ft_strlen(line)))
				ft_rev_rotate(&a, &b, RRR);*/
			free(line);
			line = get_next_line(0);
		}
//      	printf("\n========== A ==========\n");
//            ft_print_stack(&a);
//		printf("b.top => %d\n", b.top);
//		printf("is sorted :=>  %d\n", ft_is_sorted(&a));
		if (ft_is_sorted(&a) && b.top == -1)
			ft_putendl_fd("OK", STD_OUT);
		else
			ft_putendl_fd("KO", STD_OUT);
        return (0);
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

char    *get_next_line(int fd)
{
        char    c;
        char    *buff;
        char    *tmp;

        buff = ft_strdup("");
        while (read(fd, &c, 1) > 0 && c != '\n')
        {
                tmp = ft_strjoin(buff, &c);
                free(buff);
                buff = tmp;
        }
		if (!*buff)
        	return (0);
		return (buff);
}

void	ft_check(t_stack *s, int elem, int *res)
{
	int	tmp;

	if (s->top == -1)
		return ;
	tmp = ft_pop(s);
	if (elem > tmp && *res == TRUE)
		*res = FALSE;
	ft_check(s, tmp, res);
	ft_push(s, tmp, 0);
}

int	ft_is_sorted(t_stack *s)
{
	int	res;
	int	tmp;

	res = TRUE;
	tmp = ft_pop(s);
	ft_check(s, tmp, &res);
	ft_push(s, tmp, 0);
	return (res);
}
