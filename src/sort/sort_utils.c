/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:29:38 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/20 18:44:28 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_node *stack)
{
	int	prev;
	
	if (!stack || !(stack->next))
		return (1);
	prev = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (prev > stack->value)
			return (0);
		prev = stack->value;
		stack = stack->next;
	}
	return (1);
}