/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:42:13 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/05/02 21:16:07 by hmacedo-         ###   ########.fr       */
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
7 - repetir os passos 2 e 3 até a lista for menor que 5 elementos.
*/
void	quick_sort(t_stack **a, t_stack **b)
{
	(void)a;
	(void)b;
}
