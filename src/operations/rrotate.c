/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:54:10 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/23 13:01:30 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack *stack_a, int print)
{
	t_node	*last;

	// Si el stack a está vacío o solo tiene un elemento no hacemos nada
	if (!stack_a || !stack_a->first || !stack_a->first->next)
		return ;
	// Extraemos el último elemento y actualizamos el nuevo last del stack
	last = stack_a->last;
	stack_a->last = last->prev;
	last->prev->next = NULL;
	//Insertamos el last en la cima del stack
	last->prev = NULL;
	last->next = stack_a->first;
	//Actualizamos el previo del primer nodo al nuevo primer nodo
	stack_a->first->prev = last;
	//Actualizamos el primer nodo del stack
	stack_a->first = last;
	if (print == 1)
		ft_printf("rra\n");
}

void	rrb(t_stack *stack_b, int print)
{
	t_node	*last;

	// Si el stack b está vacío o solo tiene un elemento no hacemos nada
	if (!stack_b || !stack_b->first || !stack_b->first->next)
		return ;
	// Extraemos el último elemento y actualizamos el nuevo last del stack
	last = stack_b->last;
	stack_b->last = last->prev;
	last->prev->next = NULL;
	//Insertamos el last en la cima del stack
	last->prev = NULL;
	last->next = stack_b->first;
	//Actualizamos el previo del primer nodo al nuevo primer nodo
	stack_b->first->prev = last;
	//Actualizamos el primer nodo del stack
	stack_b->first = last;
	if (print == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print == 1)
		ft_printf("rrr\n");
}
