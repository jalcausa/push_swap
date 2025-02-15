/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:11:04 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/23 13:03:11 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	t_chunk	first_chunk;

	first_chunk.loc = TOP_A;
	first_chunk.size = stack_a->size;
	rec_quicksort(stack_a, stack_b, &first_chunk);
}

void	rec_quicksort(t_stack *stack_a, t_stack *stack_b,
	t_chunk *current_chunk)
{
	t_chunk_split	chunk_split;

	chunk_to_top(stack_a, stack_b, current_chunk);
	if (current_chunk->size <= 2)
	{
		if (current_chunk->size == 2)
			sort_two(stack_a, stack_b, current_chunk);
		else if (current_chunk->size == 1)
			sort_one(stack_a, stack_b, current_chunk);
		return ;
	}
	split_chunk(stack_a, stack_b, current_chunk, &chunk_split);
	rec_quicksort(stack_a, stack_b, &chunk_split.max);
	rec_quicksort(stack_a, stack_b, &chunk_split.mid);
	rec_quicksort(stack_a, stack_b, &chunk_split.min);
}

void	sort_one(t_stack *stack_a, t_stack *stack_b, t_chunk *current_chunk)
{
	if (current_chunk->loc != TOP_A)
		move_from_to(stack_a, stack_b, current_chunk->loc, TOP_A);
	current_chunk->size -= 1;
}

void	sort_two(t_stack *stack_a, t_stack *stack_b, t_chunk *current_chunk)
{
	if (current_chunk->loc != TOP_A)
	{
		move_from_to(stack_a, stack_b, current_chunk->loc, TOP_A);
		move_from_to(stack_a, stack_b, current_chunk->loc, TOP_A);
	}
	if (stack_a->first->index > stack_a->first->next->index)
		sa(stack_a, 1);
	current_chunk->size -= 2;
}
