/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:37:11 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/01 21:22:34 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack **a)
{
	int	first_int;
	int	second_int;

	first_int = *((int *)(*a)->content);
	second_int = *((int *)(*a)->next->content);
	if (first_int > second_int)
		swap_a(a);
}

void	sort_three(t_stack **a)
{
	t_stack	*max;

	if (ft_stcksize(a) == 2)
	{
		sort_two(a);
		return ;
	}
	max = find_maxnode(a);
	if (max->index == 2)
		sort_two(a);
	if (max->index == 1)
	{
		rotate_a(a, 1);
		sort_two(a);
	}
	if (max->index == 0)
	{
		rotate_a(a, 0);
		sort_two(a);
	}
}
