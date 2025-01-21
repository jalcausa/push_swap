/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:29:33 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/21 20:17:09 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_2(t_stack *stack_a)
{
	if (stack_a->first->value > stack_a->last->value)
		sa(&stack_a);
}

void	sort_3(t_stack *stack_a)
{
	int	x;
	int	y;
	int	z;

	x = stack_a->first->value;
	y = stack_a->first->next->value;
	z = stack_a->last->value;
	if (x < y && y > z && x < z)
	{
		rra(&stack_a);
		sa(&stack_a);
	}
	else if (x < y && y > z && x > z)
	{
		rra(&stack_a);
	}
	else if (x > y && y < z && x < z)
		sa(&stack_a);
	else if (x > y && y < z && x > z)
		ra(&stack_a);
	else if (x > y && y > z && x > z)
	{
		sa(&stack_a);
		rra(&stack_a);
	}
}

void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	push_min(stack_a, stack_b);
	sort_3(stack_a);
	pa(&stack_a, &stack_b);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1 || is_sorted(stack_a->first))
		return ;
	else if (stack_a->size == 2)
		sort_2(stack_a);
	else if (stack_a->size == 3)
		sort_3(stack_a);
	else 
	{
		assign_indexes(stack_a);
		if (stack_a->size == 4)
			sort_4(stack_a, stack_b);
	}
	/*else if (stack_a->size == 5)
		sort_5(stack_a, stack_b);
	else
		quicksort(stack_a, stack_b);
	*/
}
