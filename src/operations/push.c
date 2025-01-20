/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:42:23 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/20 10:11:40 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*node_to_move;

	if (!stack_a || !stack_b || !(*stack_b) || !((*stack_b)->first))
		return ;
	//Extraer el nodo a mover de la cima de stack_b
	node_to_move = (*stack_b)->first;
	(*stack_b)->first = node_to_move->next;
	//Si stack b no queda vacío, actualizar el prev del nuevo first
	if (((*stack_b)->first))
		(*stack_b)->first->prev = NULL;
	//Si queda vacío poner last a NULL
	else
		(*stack_b)->last = NULL;
	// Conectar el nodo extraído a la cima de stack a
	node_to_move->next = (*stack_a)->first;
	// Si el stack a no estaba vacío conectarlo con el primer nodo
	if ((*stack_a)->first)
		(*stack_a)->first->prev = node_to_move;
	// Si estaba vacío actualizar last
	else
		(*stack_a)->last = node_to_move;
	// Actualizar el puntero first de stack a
	(*stack_a)->first = node_to_move;
	node_to_move->prev = NULL;
	//Actualizar tamaños
	(*stack_a)->size += 1;
	(*stack_b)->size -= 1;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*node_to_move;

	if (!stack_b || !stack_a || !(*stack_a) || !((*stack_a)->first))
		return ;
	//Extraer el nodo a mover de la cima de stack_a
	node_to_move = (*stack_a)->first;
	(*stack_a)->first = node_to_move->next;
	//Si stack a no queda vacío, actualizar el prev del nuevo first
	if (((*stack_a)->first))
		(*stack_a)->first->prev = NULL;
	//Si queda vacío poner last a NULL
	else
		(*stack_a)->last = NULL;
	// Conectar el nodo extraído a la cima de stack a
	node_to_move->next = (*stack_b)->first;
	// Si el stack b no estaba vacío conectarlo con el primer nodo
	if ((*stack_b)->first)
		(*stack_b)->first->prev = node_to_move;
	// Si estaba vacío actualizar last
	else
		(*stack_b)->last = node_to_move;
	// Actualizar el puntero first de stack a
	(*stack_a)->first = node_to_move;
	node_to_move->prev = NULL;
	//Actualizar tamaños
	(*stack_b)->size += 1;
	(*stack_a)->size -= 1;
}
