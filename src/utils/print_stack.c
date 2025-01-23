/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:34:18 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/23 14:34:30 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int	ai;
	int	b;

	// Usamos punteros auxiliares para recorrer los stacks sin modificarlos
	t_node *current_a = stack_a->first;
	t_node *current_b = stack_b->first;

	while (current_a || current_b)
	{
		// Imprimimos los valores de stack_a
		if (current_a)
		{
			a = current_a->value;
			ai = current_a->index;
			current_a = current_a->next;
		}
		else
			a = 0;

		// Imprimimos los valores de stack_b
		if (current_b)
		{
			b = current_b->value;
			//bi = current_b->index;
			current_b = current_b->next;
		}
		else
			b = 0;

		// Imprimimos los valores de los stacks
		printf("%d,%d     %d \n", a, ai, b);
	}
	printf("---------\nA     B \n\n");
}
