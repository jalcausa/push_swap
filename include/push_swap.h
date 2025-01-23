/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:27:14 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/23 10:50:43 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "../libft/libft.h"
/* Double linked list */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*first;
	t_node	*last;
	int		size;
}	t_stack;

/* Chunk structure*/
typedef enum	e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}	t_loc;

typedef struct s_chunk
{
	t_loc	loc;
	int			size;
}	t_chunk;

typedef struct s_chunk_split
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}	t_chunk_split;

/* Operations */
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* Argument check */
int		is_number(char *str);
int		valid_size(const char *str);
int		is_repeated(int n, int pos, char **argv);
int		arguments_ok(int argc, char **argv);

/*Stack utils */
t_stack	*create_stack(void);
t_stack	*create_stack_with_args(char **argv);
void	free_stack(t_stack	*s);

/* Sort utils */
int		is_sorted(t_node *node);
void	assign_indexes(t_stack *stack_a);
void	push_min(t_stack *stack_a, t_stack *stack_b, int pos);

/* Sort*/
void	sort(t_stack *stack_a, t_stack *stack_b);
void	sort_2(t_stack *stack_a);
void	sort_3(t_stack *stack_a);
void	sort_5(t_stack *stack_a, t_stack *stack_b);

/* Quicksort*/
void	quicksort(t_stack *stack_a, t_stack *stack_b);
void	rec_quicksort(t_stack *stack_a, t_stack *stack_b, t_chunk *current_chunk);
void	sort_one(t_stack *stack_a, t_stack *stack_b, t_chunk *current_chunk);
void	sort_two(t_stack *stack_a, t_stack *stack_b, t_chunk *current_chunk);
void	chunk_to_top(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk);

/* move */
int		move_from_to(t_stack *stack_a, t_stack *stack_b, t_loc from, t_loc to);
void	move_from_top_a(t_stack *stack_a, t_stack *stack_b, t_loc to);
void	move_from_top_b(t_stack *stack_a, t_stack *stack_b, t_loc to);
void	move_from_bottom_a(t_stack *stack_a, t_stack *stack_b, t_loc to);
void	move_from_bottom_b(t_stack *stack_a, t_stack *stack_b, t_loc to);

/* Split*/
void	split_chunk(t_stack *stack_a, t_stack *stack_b, 
	t_chunk *current_chunk, t_chunk_split *chunk_split);
void	init_size(t_chunk *min, t_chunk *mid, t_chunk *max);
void	set_split_loc(t_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max);
void	set_pivots(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk,
	int *pivot_1, int *pivot_2);
int		get_next_index(t_stack *stack_a, t_stack *stack_b, t_chunk *current_chunk);
int		chunk_max_index(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk);