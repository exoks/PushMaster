#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

t_stack	*ft_lstnew(int a)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->nb = a;
	node->next = 0;
	return (node);
}

t_stack	*ft_lstlast(t_stack *stack)
{
	while (stack)
	{
		if (stack->next == 0)
			return (stack);
		stack = stack->next;
	}
	return (0);
}

t_stack	*ft_push(t_stack	*stack, int elem)
{
	if (stack)
		(ft_lstlast(stack))->next = ft_lstnew(elem);
	else
		stack = ft_lstnew(elem);
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack	*lst;
	int		i;

	lst = 0;
	i = ac - 1;
	while (i > 0)
		lst = ft_push(lst, atoi(av[--i]));
	while (lst)
	{
		printf(" %d ", lst->nb);
		lst = lst->next;
	}
	return (0);
}	
