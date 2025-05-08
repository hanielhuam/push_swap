/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:57:58 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/07 20:19:21 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_stack.h"
# include "ft_printf.h"

char	**treat_args(int argc, char **args);
int		**to_int(char **args);
t_stack	**init_stack(int **args);
int		check_order(t_stack *stack);
void	sort_algorithm(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	quick_sort(t_stack **a, t_stack **b);
void	show_stacks(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a, int reverse);
void	rotate_b(t_stack **b, int reverse);
void	r_rotate(t_stack **a, t_stack **b, int reverse);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	s_swap(t_stack **a, t_stack **b);
void	clear_args(char **args);
void	clear_numbers(int **numbers);
void	clear_numbers_args(int **numbers, char **args);
void	clear_stack(t_stack **stack);
void	clear_numbers_stack(int **numbers, t_stack **stack);
t_stack	*find_maxnode(t_stack **stack);
t_stack	*find_minnode(t_stack **stack);
t_list	*find_minnodes(t_stack **stack, t_list *list, int size);
t_list	*find_maxnodes(t_stack **stack, t_list *list, int size);
t_list	**init_minorlist(int size);
t_list	*exist_content(t_list *list);
void	clear_minorlist(t_list **list);
void	erase_content(t_list *list);
int		get_midian(t_list *ordered_list);
int		move_2b(t_stack **a, t_stack **b, t_stack *node);
int		move_2b_midian(t_stack **a, t_stack **b, t_stack *node, int midian);
void	move_2a(t_stack **a, t_stack **b, t_stack *node);
int		compare_nodes(t_stack *node1, t_stack *node2);
int		compare_positions(t_list *node1, t_list *node2);
t_stack	*best_node_2push(t_list *list, int size);

#endif 
