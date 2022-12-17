/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:55:57 by oezzaou           #+#    #+#             */
/*   Updated: 2022/12/17 18:53:21 by oezzaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_elem_count(char **av);
int	*ft_extract_elem(char **av, int count);

int	main(int ac, char **av)
{
	int	count;
	int	*elem;

	(void)ac;
	count = ft_elem_count(av);
	elem = ft_extract_elem(av, count);
	if (!elem)
		return (0);
	return (0);
}

int	*ft_extract_elem(char **av, int count)
{
	int		*elem;
	char	**tab;

	elem = (int *) malloc(sizeof(int) * count);
	if (!elem)
		return (0);
	while (*av)
	{
		tab = ft_split(av, ' ');
		while (
	}
}

int	ft_elem_count(char **av, int *elem)
{
	int	count;
	int	i;
	char	**elem;

	while (*(++av))
	{
		elem = ft_split(*av, ' ');
		i = -1;
		while (elem[++i])
			count++;
		i = 0;
		while (elem[i])
			free(elem[i++]);
		free(elem);
	}
	return (count);
}
