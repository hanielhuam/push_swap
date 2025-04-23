/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:05:10 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/22 19:27:04 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*joinall_args(int argc, char **argv)
{
	char *result;
	char *temp;
	int	i;

	result = ft_strdup(argv[1]);
	if (!result)
		return (NULL);
	i = 2;
	while(i < argc)
	{
		temp = ft_strjoin(result, " ");
		free(result);
		if (!temp)
			return (NULL);
		result = ft_strjoin(temp, argv[i++]);
		free(temp);
		if (!result)
			return (NULL);
	}
	return (result);
}

char	**treat_args(int argc, char **argv)
{
	char	**result;
	if (argc <= 1)
		return (NULL);
	result = ft_split(joinall_args(argc, argv), ' ');
	if (!result || !result[0])
	{
		ft_putstr_fd("alocation error", 2);
		return (NULL);
	}
	return (result);
}
