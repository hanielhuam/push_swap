

#include "ft_stack.h"

void	ft_stckdelone(t_stck *element, void (*del)(void*))
{
	t_stck	*temp;

	if (!element)
		return ;
	temp = element->next;
	while (temp->index > element->index)
	{
		temp->index -= 1;
		temp = temp->next;
	}
	del()
}
