/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:48:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/24 15:43:27 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	**numbers;
	int	i;

	i = 0;
	numbers = to_int(treat_args(argc, argv));
	if (!numbers)
		return (-1);
	while (numbers[i])
		ft_printf("%d\n", *numbers[i++]);
	clear_numbers(numbers);
	return (0);
}
