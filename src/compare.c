/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:52:47 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/04 21:15:41 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_nodes(t_stack *node1, t_stack *node2)
{
	return (*((int *)node1->content) - *((int *)node2->content));
}

int	compare_positions(t_list *node1, t_list *node2)
{
	return (((t_stack *)node1->content)->index - \
			((t_stack *)node2->content)->index);
}
