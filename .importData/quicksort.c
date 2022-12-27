#include <stdio.h>
#include <stdlib.h>

int	ft_partion(int *arr, int start, int end)
{
	int	pivot;
	int	i, j;
	int	tmp;

	if (start >= end)
		return (-1);
	if (!arr)
		return (0);
	pivot = start;
	i = start + 1;
	j = end;
	while (1)
	{
		while (++i < end && arr[pivot] > arr[i])
			;
		printf("arr[i] ==> %d\n", arr[i]);
		while (--j > start && arr[pivot] < arr[j])
			;
		printf("arr[j] ==> %d\n", arr[j]);
		tmp = arr[j];
		if (i < j)
		{
			arr[j] = arr[i];
			arr[i] = tmp;
		}
		if (i >= j)
		{
			arr[j] = arr[pivot];
			arr[pivot] = tmp;
			break;
		}
	}
	return (j);
}

void	ft_quick_sort(int *arr, int start, int end)
{
	int	re;

	if (start >= end)
		return ;
	re = ft_partion(arr, start, end);
	ft_quick_sort(arr, re + 1, end);
	ft_quick_sort(arr, 0, re - 1);
}

int	main(int ac, char **av)
{
	int	*arr;
	int	i;
	int	j, f;
	int	tmp;

	arr = (int *) malloc(sizeof(int) * ac - 1);
	if (!arr)
		return (0);
	i = -1;
	while (++i < ac - 1)
		arr[i] = atoi(av[i + 1]);
	ft_quick_sort(arr, 0, ac - 1);
	printf("\n=========================\n");
	i = -1;
	while (++i < ac - 1)
		printf(" %d ", arr[i]);
	printf("\n");
	return (0);
}
