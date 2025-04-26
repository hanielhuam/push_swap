/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:59:42 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/26 19:04:18 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stack *a)
{
	int		min;
	t_stack	*init;

	min = *((int *)a->content);
	init = a;
	a = a->next;
	while (a != init)
	{
		if (min > *((int *)a->content))
			return (0);
		min = *((int *)a->content);
		a = a->next;
	}
	return (1);
}
