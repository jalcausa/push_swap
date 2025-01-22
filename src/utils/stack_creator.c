/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:22:03 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/22 17:07:04 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_node	*create_node(int value, int index)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = value;
	new_node->index = index;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

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
	while (new_stack != NULL && argv[i])
	{
		new_node = create_node(ft_atoi(argv[i++]), 0);
		if (!new_node)
		{
			free_stack(new_stack);
			return (NULL);
		}
		if (!new_stack->first)
			new_stack->first = new_node;
		else
		{
			new_stack->last->next = new_node;
			new_node->prev = new_stack->last;
		}
		new_stack->last = new_node;
		++new_stack->size;
	}
	return (new_stack);
}
