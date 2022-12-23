/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:52:28 by ysalmi            #+#    #+#             */
/*   Updated: 2022/11/27 17:23:58 by ysalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
//#include "get_next_line.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int	*random_arr(int min, int max, int size)
{
	int	*pool, *arr;
	int	i, j, max_step, tmp;

	if (max - min < size)
		return (0);
	pool = malloc((max - min) * sizeof(int));
	i = min - 1;
	while (++i < max)
		pool[i - min] = i;

	srand(time(NULL));
	i = -1;
	while (++i < max - min)
	{
		j = i + rand() % (max - min - i);
		tmp = pool[j];
		pool[j] = pool[i];
		pool[i] = tmp;
	}
	arr = malloc(size * sizeof(int));
	i = -1;
	while (++i < size)
		arr[i] = pool[i];
	for (int i = 0; i < size; i++)
		printf("%3d ", arr[i]);
	free(arr);
	free(pool);
	return (0);
}
int main(int c, char **v)
{
	(void)v;
	if (c == 4)
		random_arr(atoi(v[1]), atoi(v[2]), atoi(v[3]));
	return 0;
}
/*
int	main(int c, char **v)
{
	char	*s;
	int		i;
	int		line;

	ft_printf("%d\n", rand());
	line = m_atoi(v[1]);
	i = 0;
	while (i++ < line - 1)
	{
		s = get_next_line(3);
		free(s);
	}
	s = get_next_line(3);
	push_swap(&s, 1);
	free(s);
	return (0);
}*/
