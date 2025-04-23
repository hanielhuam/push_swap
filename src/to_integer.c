/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:32:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/23 17:45:20 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t count_args(char **args)
{
	size_t	i;

	i = 0;
	while(args[i])
		i++;
	return i;
}

static int verify_num(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
	}
	return (0);
}

int	check_repeat(int *numbers, int nu, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (numbers[i] == nu)
			return (1);
		i++;
	}
	return (0);
}

static int	num_builder(int *numbers, char **args, int index)
{
	long	temp;
	if (verify_num(args[index]))
		return (0);
	temp = ft_atol(args[index]);
	if (temp > INT_MAX || temp < INT_MIN)
		return (0);
	if (check_repeat(numbers, (int)temp, index))
		return (0);
	numbers[index] = (int)temp;
	return (numbers[index]);
}

int	*to_int(char **args)
{
	int	*numbers;
	int	i;

	if (!args || !args[0])
		return (NULL);
	numbers = ft_calloc(count_args(args) + 1, sizeof(int));
	if (!numbers)
	{
		free(args);
		return (NULL);
	}
	i = 0;
	while(args[i])
	{
		if (!num_builder(numbers, args, i++))
		{
			clear_numbers_args(numbers, args);
			return (NULL);
		}
	}
	clear_args(args);
	return (numbers);
}
