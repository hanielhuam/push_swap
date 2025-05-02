/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:44:04 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/01 20:44:44 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a)
{
	ft_stckswap(a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **b)
{
	ft_stckswap(b);
	ft_printf("sb\n");
}

void	swap_s(t_stack **a, t_stack **b)
{
	ft_stckswap(a);
	ft_stckswap(b);
	ft_printf("ss\n");
}
