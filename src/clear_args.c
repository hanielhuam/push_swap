/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:58:22 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/23 16:31:13 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_args(char **args)
{
	int	i;

	i = 0;
	while(args[i])
		free(args[i]);
	free(args);
}

void	clear_numbers_args(int *numbers, char **args)
{
	free(numbers);
	clear_args(args);
}
