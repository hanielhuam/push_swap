/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:55:51 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/01 20:58:04 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a, int reverse)
{
	ft_stckrotate(a, reverse);
	if (reverse)
		ft_printf("rra\n");
	else
		ft_printf("ra\n");
}

void	rotate_b(t_stack **b, int reverse)
{
	ft_stckrotate(b, reverse);
	if (reverse)
		ft_printf("rrb\n");
	else
		ft_printf("rb\n");
}

void	r_rotate(t_stack **a, t_stack **b, int reverse)
{
	ft_stckrotate(a, reverse);
	ft_stckrotate(b, reverse);
	if (reverse)
		ft_printf("rrr\n");
	else
		ft_printf("rr");
}
