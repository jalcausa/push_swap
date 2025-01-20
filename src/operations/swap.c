/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:13:44 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/20 11:12:23 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack **stack_a)
{
	int	aux_val;
	int	aux_index;

	if (!stack_a || !*stack_a || !(*stack_a)->first || !(*stack_a)->first->next)
		return ;
	// Se intercambian los valores y los índices de los dos primeros nodos
	aux_val = (*stack_a)->first->value;
	aux_index = (*stack_a)->first->index;
	(*stack_a)->first->value = (*stack_a)->first->next->value;
	(*stack_a)->first->index = (*stack_a)->first->next->index;
	(*stack_a)->first->next->value = aux_val;
	(*stack_a)->first->next->index = aux_index;
}

void	sb(t_stack **stack_b)
{
	int	aux_val;
	int	aux_index;

	if (!stack_b || !*stack_b || !(*stack_b)->first || !(*stack_b)->first->next)
		return ;
	// Se intercambian los valores y los índices de los dos primeros nodos
	aux_val = (*stack_b)->first->value;
	aux_index = (*stack_b)->first->index;
	(*stack_b)->first->value = (*stack_b)->first->next->value;
	(*stack_b)->first->index = (*stack_b)->first->next->index;
	(*stack_b)->first->next->value = aux_val;
	(*stack_b)->first->next->index = aux_index;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
