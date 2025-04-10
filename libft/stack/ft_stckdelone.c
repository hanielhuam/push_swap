

void	ft_stckdelone(t_stck *element, void (*del)(void*))
{
	t_stck	*temp;

	if (!element)
		return ;
	del(element->content);
	free(element);
}

#include <stdio.h>

int	*newint_point(int nu)
{
	int	*nup;

	nup = ft_calloc(1, sizeof(int));
	*nup = nu;
	return (nup);
}

void	print_t_stack(t_stack *element)
{
	printf("element->index = %d\n", element->index);
	printf("element->before = %p\n", element->before);
	printf("element->next = %p\n", element->next);
	printf("element->content = %d\n", *((int *)element->content));
}

void	print_stack(t_stack **stack)
{
	t_stack	*temp;

	print_t_stack(*stack);
	temp = (*stack)->next;
	while (temp != *stack)
	{
		printf("\n");
		print_t_stack(temp);
		temp = temp->next;
	}
	printf("\n");
}

void	del_stck(void * content)
{
	free(content);
}

int	main(void)
{
	int	*nu;
	t_stack *el;

	nu = newint_point(42);
	el = ft_stcknew(nu);
	printf("addres of nu is %p\naddres of el is %p\n", el, nu);
	ft_stckdelone(el, del_stck);
	printf("after delone\n");
	printf("addres of nu is %p\naddres of el is %p\n", el, nu);
	return (0);
}
