/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:29:38 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/22 15:08:17 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_node *node)
{
	int	prev;
	
	if (!node || !node->next)
		return (1);
	prev = node->value;
	node = node->next;
	while (node)
	{
		if (prev > node->value)
			return (0);
		prev = node->value;
		node = node->next;
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

void	push_min(t_stack *stack_a, t_stack *stack_b, int pos)
{
	t_node	*cur;
	
	while ((cur = stack_a->first))
	{
		if (cur->index == pos)
		{
			pb(stack_a, stack_b);
			break ;
		}
		else
		{
			ra(stack_a);
		}
	}
}
