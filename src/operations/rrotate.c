/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:54:10 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/20 10:55:31 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack **stack_a)
{
	t_node	*last;

	// Si el stack a está vacío o solo tiene un elemento no hacemos nada
	if (!stack_a || !*stack_a || !(*stack_a)->first || !(*stack_a)->first->next)
		return ;
	// Extraemos el último elemento y actualizamos el nuevo last del stack
	last = (*stack_a)->last;
	(*stack_a)->last = last->prev;
	last->prev->next = NULL;
	//Insertamos el last en la cima del stack
	last->prev = NULL;
	last->next = (*stack_a)->first;
	//Actualizamos el previo del primer nodo al nuevo primer nodo
	(*stack_a)->first->prev = last;
	//Actualizamos el primer nodo del stack
	(*stack_a)->first = last;
}

void	rrb(t_stack **stack_b)
{
	t_node	*last;

	// Si el stack b está vacío o solo tiene un elemento no hacemos nada
	if (!stack_b || !*stack_b || !(*stack_b)->first || !(*stack_b)->first->next)
		return ;
	// Extraemos el último elemento y actualizamos el nuevo last del stack
	last = (*stack_b)->last;
	(*stack_b)->last = last->prev;
	last->prev->next = NULL;
	//Insertamos el last en la cima del stack
	last->prev = NULL;
	last->next = (*stack_b)->first;
	//Actualizamos el previo del primer nodo al nuevo primer nodo
	(*stack_b)->first->prev = last;
	//Actualizamos el primer nodo del stack
	(*stack_b)->first = last;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
