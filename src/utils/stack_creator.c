/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:22:03 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/20 13:42:53 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->first = NULL;
	new_stack->last = NULL;
	new_stack->size = 0;
	return (new_stack);
}

t_stack	*create_stack_with_args(char **argv)
{
	t_stack	*new_stack;
	t_node	*new_node;
	int		i;

	new_stack = create_stack();
	i = 1;
	while (argv[i])
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			free_stack(new_stack);
		new_node->value = ft_atoi(argv[i]);
		new_node->index = 0;
		new_node->prev = NULL;
		new_node->next = NULL;
		if (!new_stack->first)
			new_stack->first = new_node;
		else
		{
			new_stack->last->next = new_node;
			new_node->prev = new_stack->last;
		}
		new_stack->last = new_node;
		++new_stack->size;
		++i;
	}
	return (new_stack);
}