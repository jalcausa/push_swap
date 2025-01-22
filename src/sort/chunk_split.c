/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:42:41 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/22 18:38:50 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	split_chunk(t_stack *stack_a, t_stack *stack_b,
	t_chunk *current_chunk, t_chunk_split *chunk_split)
{
	int	pivot_1;
	int	pivot_2;
	int	next_index;

	init_size(&chunk_split->min, &chunk_split->mid, &chunk_split->max);
	set_split_loc(current_chunk->loc, &chunk_split->min, &chunk_split->mid,
		&chunk_split->max);
	set_pivots(current_chunk->size, &pivot_1, &pivot_2);
	while (current_chunk->size--)
	{
		next_index = get_next_index(stack_a, stack_b, current_chunk);
		if (next_index < pivot_2)
			chunk_split->max.size += move_from_to(stack_a, stack_b,
					current_chunk->loc, chunk_split->max.loc);
		else if (next_index < pivot_1)
			chunk_split->mid.size += move_from_to(stack_a, stack_b,
					current_chunk->loc, chunk_split->mid.loc);
		else
			chunk_split->min.size += move_from_to(stack_a, stack_b,
					current_chunk->loc, chunk_split->min.loc);
	}
}

void	init_size(t_chunk *min, t_chunk *mid, t_chunk *max)
{
	min->size = 0;
	mid->size = 0;
	max->size = 0;
}

void	set_split_loc(t_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max)
{
	if (loc == TOP_A)
	{
		min->loc = BOTTOM_B;
		mid->loc = TOP_B;
		max->loc = BOTTOM_A;
	}
	else if (loc == BOTTOM_A)
	{
		min->loc = BOTTOM_B;
		mid->loc = TOP_B;
		max->loc = TOP_A;
	}
	else if (loc == TOP_B)
	{
		min->loc = BOTTOM_B;
		mid->loc = BOTTOM_A;
		max->loc = TOP_A;
	}
	else if (loc == BOTTOM_B)
	{
		min->loc = TOP_B;
		mid->loc = BOTTOM_A;
		max->loc = TOP_A;
	}
}

void	set_pivots(int size, int *pivot_1, int *pivot_2)
{
	*pivot_2 = size / 3;
	*pivot_1 = *pivot_2 * 2;
}

int	get_next_index(t_stack *stack_a, t_stack *stack_b, t_chunk *current_chunk)
{
	if (current_chunk->loc == TOP_A)
		return (stack_a->first->index);
	else if (current_chunk->loc == TOP_B)
		return (stack_b->first->index);
	else if (current_chunk->loc == BOTTOM_A)
		return (stack_a->last->index);
	else
		return (stack_b->last->index);
}
