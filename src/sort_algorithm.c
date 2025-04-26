/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:49:40 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/26 19:00:43 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algorithm(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stcksize(a);
	if (size == 1 || check_order(*a))
		return ;
	ft_printf("Passou por aqui");
	if (size <= 3)
		sort_three(a, b);
}
