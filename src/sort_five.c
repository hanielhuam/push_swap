/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:40:16 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/03 17:13:11 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*smoller;

	smoller = find_minnode(a);
	if (move_2b(a, b, smoller) && !*b)
		return ;
	sort_three(a);
	move_2a(a, b, *b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_list	**menores;

	if (ft_stcksize(a) < 5)
	{
		sort_four(a, b);
		return ;
	}
	(void) menores;
}
