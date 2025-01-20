/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:36:11 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/20 18:49:46 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack **stack_a)
{
	t_node	*first;

	// Si el stack a está vacío o solo tiene un elemento no hacemos nada
	if (!stack_a || !*stack_a || !(*stack_a)->first || !(*stack_a)->first->next)
		return ;
	// Se extrae el primer elemento y se actualiza el previo del segundo a null
	first = (*stack_a)->first;
	first->next->prev = NULL;
	// Se actualiza el nuevo primer elemento del stack
	(*stack_a)->first = first->next;
	// Se inserta en la cola y se actualiza el next de la nueva cola a null
	first->prev = (*stack_a)->last;
	(*stack_a)->last->next = first;
	first->next = NULL;
	// Se actualiza el nuevo último nodo de la estructura stack
	(*stack_a)->last = first;
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	t_node	*first;

	// Si el stack b está vacío o solo tiene un elemento no hacemos nada
	if (!stack_b || !*stack_b || !(*stack_b)->first || !(*stack_b)->first->next)
		return ;
	// Se extrae el primer elemento y se actualiza el previo del segundo a null
	first = (*stack_b)->first;
	first->next->prev = NULL;
	// Se actualiza el nuevo primer elemento del stack
	(*stack_b)->first = first->next;
	// Se inserta en la cola y se actualiza el next de la nueva cola a null
	first->prev = (*stack_b)->last;
	(*stack_b)->last->next = first;
	first->next = NULL;
	// Se actualiza el nuevo último nodo de la estructura stack
	(*stack_b)->last = first;
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}
