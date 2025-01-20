/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:29:33 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/20 18:58:23 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_2(t_stack *stack_a)
{
	if (stack_a->first->value > stack_a->last->value)
		sa(&stack_a);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1 || is_sorted(stack_a->first))
		return ;
	else if (stack_a->size == 2)
		sort_2(stack_a);
	(void) stack_b;
	/*else if (stack_a->size == 3)
		sort_3(stack_a);
	else if (stack_a->size == 4)
		sort_4(stack_a, stack_a);
	else if (stack_a->size == 5)
		sort_5(stack_a, stack_b);
	else
		quicksort(stack_a, stack_b);
	*/
}
