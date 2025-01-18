/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:42:23 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/18 23:53:20 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_move;
	t_node	*new_b;

	if (!stack_a || !stack_b)
		return ;
	if (!(*stack_b))
		return ;
	node_to_move = *stack_b;
	new_b = (*stack_b)->next;
	*stack_b = new_b;
	node_to_move->next = *stack_a;
	*stack_a = node_to_move;
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_move;
	t_node	*new_a;

	if (!stack_a || !stack_b)
		return ;
	if (!(*stack_a))
		return ;
	node_to_move = *stack_a;
	new_a = (*stack_a)->next;
	*stack_a = new_a;
	node_to_move->next = *stack_b;
	*stack_b = node_to_move;
}
