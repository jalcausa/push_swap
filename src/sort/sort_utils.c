/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:29:38 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/21 18:56:42 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_node *stack)
{
	int	prev;
	
	if (!stack || !(stack->next))
		return (1);
	prev = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (prev > stack->value)
			return (0);
		prev = stack->value;
		stack = stack->next;
	}
	return (1);
}

void	assign_indexes(t_stack *stack_a)
{
	int		index;
	t_node	*current;
	t_node	*min_node;

	index = 1;
	while (index <= stack_a->size)
	{
		current = stack_a->first;
		min_node = NULL;
		while (current)
		{
			if (current->index == 0 && (!min_node
				|| current->value < min_node->value))
			{
				min_node = current;
			}
			current = current->next;
		}
		if (min_node)
		{
			min_node->index = index;
			++index;
		}
	}
}
/*
void	push_min(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	int		min;

	current = stack_a->first;
	min = current->value;
	while (current->next)
}
*/
