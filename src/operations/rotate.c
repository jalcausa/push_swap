/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:36:11 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/18 23:53:01 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_node **stack_a)
{
	t_node	*first;
	t_node	*aux;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	first = *stack_a;
	first->next->prev = NULL;
	(*stack_a) = first->next;
	aux = (*stack_a);
	while (aux->next)
		aux = aux->next;
	aux->next = first;
	first->prev = aux;
	first->next = NULL;
}

void	rb(t_node **stack_b)
{
	t_node	*first;
	t_node	*aux;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return ;
	first = *stack_b;
	first->next->prev = NULL;
	(*stack_b) = first->next;
	aux = (*stack_b);
	while (aux->next)
		aux = aux->next;
	aux->next = first;
	first->prev = aux;
	first->next = NULL;
}

void	rb(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
