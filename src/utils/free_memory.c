/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:29:40 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/20 13:32:46 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_stack(t_stack	*s)
{
	t_node	*prev_nod;

	while (s->first)
	{
		prev_nod = s->first;
		s->first = s->first->next;
		free(prev_nod);
	}
	free(s);
}