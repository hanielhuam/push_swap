

#include "ft_stack.h"

t_stack *ft_stcknew(void *content)
{
	t_stack	*element;

	element = ft_calloc(1, sizeof(t_stack));
	if (!element)
		return (NULL);
	element->content = content;
	element->index = 0;
	element->next = element;
	element->before = element;
	return (element);
}
/*
#include <stdio.h>

void	print_t_stack(t_stack *element)
{
	printf("element->index = %d\n", element->index);
	printf("element->before = %p\n", element->before);
	printf("element->next = %p\n", element->next);
	printf("element->content = %d\n", *((int *)element->content));
}

int	main(void)
{
	int	nu;

	nu = 42;
	print_t_stack(ft_stcknew(&nu));
	return (0);
}*/
