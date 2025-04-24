/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:57:58 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/04/24 15:48:46 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_stack.h"
# include "ft_printf.h"

char	**treat_args(int argc, char **args);
int		**to_int(char **args);
t_stack	**init_stack(char **args);
void	sort_algorithm(t_stack **a, t_stack **b);
void	sort_three(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	quick_sort(t_stack **a, t_stack **b);
void	clear_args(char **args);
void	clear_numbers(int **numbers);
void	clear_numbers_args(int **numbers, char **args);

#endif 
