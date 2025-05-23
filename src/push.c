/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:06:21 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/03 16:23:18 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	ft_stckpush(b, a);
	ft_printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	ft_stckpush(a, b);
	ft_printf("pb\n");
}
