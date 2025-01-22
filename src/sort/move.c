/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:27:49 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/22 18:41:10 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	move_from_to(t_stack *stack_a, t_stack *stack_b, t_loc from, t_loc to)
{
	if (from == TOP_A)
		move_from_top_a(stack_a, stack_b, to);
	else if (from == TOP_B)
		move_from_top_b(stack_a, stack_b, to);
	else if (from == BOTTOM_A)
		move_from_bottom_a(stack_a, stack_b, to);
	else
		move_from_bottom_b(stack_a, stack_b, to);
	return (1);
}

void	move_from_top_a(t_stack *stack_a, t_stack *stack_b, t_loc to)
{
	if (to == TOP_B)
		pb(stack_a, stack_b);
	else if (to == BOTTOM_A)
		ra(stack_a);
	else
	{
		pb(stack_a, stack_b);
		rb(stack_b);
	}
}

void	move_from_top_b(t_stack *stack_a, t_stack *stack_b, t_loc to)
{
	if (to == TOP_A)
		pa(stack_a, stack_b);
	else if (to == BOTTOM_B)
		rb(stack_b);
	else
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}

void	move_from_bottom_a(t_stack *stack_a, t_stack *stack_b, t_loc to)
{
	if (to == TOP_A)
		rra(stack_a);
	else if (to == TOP_B)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		rb(stack_b);
	}
}

void	move_from_bottom_b(t_stack *stack_a, t_stack *stack_b, t_loc to)
{
	if (to == TOP_B)
		rrb(stack_b);
	else if (to == TOP_A)
	{
		rrb(stack_b);
		pa(stack_a, stack_b);
	}
	else
	{
		rrb(stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}
