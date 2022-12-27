# include <stdio.h>
# include <stdlib.h>

int	ft_get_min(int *arr, int size)
{
	int	min;
	int	i;

	if (!arr)
		exit(EXIT_FAILURE);
	min = 0;
	i = -1;
	while(++i < size)
		if (arr[min] > arr[i])
			min = i;
	return (min);
}

int	main(int ac, char **av)
{
	int	*arr;
	int	i;
	int	tmp;

	arr = malloc(sizeof(int) * ac - 1);
	if (!arr)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < ac - 1)
		arr[i] = atoi(av[i + 1]);
	i = -1;
	while (++i < ac - 2)
	{
		tmp = arr[i];
		arr[i] = arr[ft_get_min(arr + i, ac - 1 - i) - i];
		arr[ft_get_min(arr + i, ac - 1 - i) - i]  = tmp;
		int	j = -1;
		while (++j < ac - 1)
			printf(" %d ", arr[j]);
		printf("\n=====================\n");
	}
	i = -1;
	while (++i < ac - 1)
		printf("%d ", arr[i]);
	printf("\n");
	return (0);
}
