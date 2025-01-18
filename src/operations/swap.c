/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:13:44 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/18 23:50:01 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_node **stack_a)
{
	int	aux_val;
	int	aux_index;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	aux_val = (*stack_a)->value;
	aux_index = (*stack_a)->index;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->value = aux_val;
	(*stack_a)->next->index = aux_index;
}

void	sb(t_node **stack_b)
{
	int	aux_val;
	int	aux_index;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return ;
	aux_val = (*stack_b)->value;
	aux_index = (*stack_b)->index;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->index = (*stack_b)->next->index;
	(*stack_b)->next->value = aux_val;
	(*stack_b)->next->index = aux_index;
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
