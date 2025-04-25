/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:58:22 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/24 20:48:31 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	clear_numbers(int **numbers)
{
	int	i;

	if (!numbers)
		return ;
	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
}

void	clear_stack(t_stack **stack)
{
	ft_stckclear(stack, free);
}

void	clear_numbers_args(int **numbers, char **args)
{
	clear_numbers(numbers);
	clear_args(args);
}

void	clear_numbers_stack(int **numbers, t_stack **stack)
{
	clear_numbers(numbers);
	clear_stack(stack);
}
