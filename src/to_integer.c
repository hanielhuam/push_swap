/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:32:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/09 19:28:43 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

static int	verify_num(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	if (!ft_isdigit(arg[i++]))
		return (1);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i++]))
			return (1);
	}
	return (0);
}

static int	check_repeat(int **numbers, int *nu, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (*numbers[i] == *nu)
			return (1);
		i++;
	}
	return (0);
}

static int	*num_builder(int **numbers, char **args, int index)
{
	long	templ;
	int		*tempi;

	if (verify_num(args[index]))
		return (NULL);
	templ = ft_atol(args[index]);
	if (templ > INT_MAX || templ < INT_MIN)
		return (NULL);
	tempi = ft_calloc(1, sizeof(int));
	if (!tempi)
	{
		ft_putstr_fd("Allocation Error!", 2);
		clear_numbers_args(numbers, args);
		exit(-1);
	}
	*tempi = (int)templ;
	if (check_repeat(numbers, tempi, index))
	{
		free(tempi);
		return (NULL);
	}
	numbers[index] = tempi;
	return (tempi);
}

int	**to_int(char **args)
{
	int	**numbers;
	int	i;

	if (!args || !args[0])
		return (NULL);
	numbers = ft_calloc(count_args(args) + 1, sizeof(int *));
	if (!numbers)
	{
		ft_putstr_fd("Allocation Error!", 2);
		clear_args(args);
		return (NULL);
	}
	i = 0;
	while (args[i])
	{
		if (!num_builder(numbers, args, i++))
		{
			ft_printf("Error\n");
			clear_numbers_args(numbers, args);
			return (NULL);
		}
	}
	clear_args(args);
	return (numbers);
}
