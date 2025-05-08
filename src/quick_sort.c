/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:42:13 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/07 20:00:27 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
1 - ver qual é o tamanho do chunck que seria size/5
2 - retornar uma lista dos n menores
	saber preencher a lista quando for menor que n;
3 - pegar o nó da mediana dos n menosres
4 - calcular quel é o melhor nó para fazer o push b
   dentro disso tem que reordenar a lista para deixar nulo como a última posiçã
5 - enviar o melhor nó para b
	colocar o nó no melhor lugar em b 
		para isso verifique se o número é menor ou maior que a mediana
		além disso verifique se da para reutilizar algum movimento de a em b
6 - repetir os passos 4 e 5 até acabar com a lista
7 - repetir os passos 2 e 3 até a stack a for menor que 5 elementos.
8 - fazer o algorítmo do retorno a stack a até não tiver nada na stack b
	verificar se está indo de maneira ordenada.
*/

static int	bring_minors_2b(t_stack **a, t_stack **b, t_list *minors, int size)
{
	t_list	*init;
	t_stack	*temp;
	int	midian;

	init = minors;
	find_minnodes(a, minors, size);
	midian = get_midian(minors);
	while (exist_content(minors))
	{
		temp = best_node_2push(minors, ft_stcksize(a));
		if (move_2b_midian(a, b, temp, midian))
		{
			erase_content(init);
			return (1);
		}
	}
	return (0);
}

static void	bring_majors_2a(t_stack **a, t_stack **b, t_list *majors)
{
	t_stack	*temp;
	
	if (!ft_stcksize(b))
		return ;
	find_maxnodes(b, majors, 2);
	while (exist_content(majors))
	{
		temp = best_node_2push(majors, ft_stcksize(b));
		move_2a(a, b, temp);
		if (compare_nodes(*a, (*a)->next) > 0)
			swap_a(a);
	}
}

static int	calc_list_size(t_stack **a)
{
	if (ft_stcksize(a) < 30)
		return (2);
	else
		return (ft_stcksize(a) / 10);
}

void	quick_sort(t_stack **a, t_stack **b)
{
	int		size;
	t_list	**minors;

	size = calc_list_size(a);
	minors = init_minorlist((size));
	if (!minors)
		return ;
	while (ft_stcksize(a) > 5)
	{
		if (bring_minors_2b(a, b, *minors, size))
			break;
	}
	if (!check_order(*a))
		sort_algorithm(a, b);
	while (*b)
		bring_majors_2a(a, b, *minors);
	clear_minorlist(minors);
}
