/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:43:10 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/23 10:50:08 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	chunk_max_index(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{
	t_stack	*stack;
	t_node	*node;
	int		size;
	int		max_index;
	
	if (chunk->loc == TOP_A || chunk->loc == BOTTOM_A)
		stack = stack_a;
	else
		stack = stack_b;
	size = chunk->size;
	max_index = 0;
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		node = stack->first;
	else
		node = stack->last;
	while (size--)
	{
		if (node->index > max_index)
			max_index = node->index;
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
			node = node->next;
		else
			node = node->prev;
	}
	return (max_index);
}