/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:54:10 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/19 00:17:55 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_node **stack_a)
{
	t_node	*second_last;
	t_node	*last;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	second_last = *stack_a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = (*stack_a);
	last->prev = NULL;
	(*stack_a)->prev = last;
	(*stack_a) = last;
}

void	rrb(t_node **stack_b)
{
	t_node	*second_last;
	t_node	*last;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return ;
	second_last = *stack_b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = (*stack_b);
	last->prev = NULL;
	(*stack_b)->prev = last;
	(*stack_b) = last;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
