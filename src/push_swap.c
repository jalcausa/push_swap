/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:20:16 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/23 12:12:37 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int	ai;
	int	b;

	// Usamos punteros auxiliares para recorrer los stacks sin modificarlos
	t_node *current_a = stack_a->first;
	t_node *current_b = stack_b->first;

	while (current_a || current_b)
	{
		// Imprimimos los valores de stack_a
		if (current_a)
		{
			a = current_a->value;
			ai = current_a->index;
			current_a = current_a->next;
		}
		else
			a = 0;

		// Imprimimos los valores de stack_b
		if (current_b)
		{
			b = current_b->value;
			//bi = current_b->index;
			current_b = current_b->next;
		}
		else
			b = 0;

		// Imprimimos los valores de los stacks
		printf("%d,%d     %d \n", a, ai, b);
	}
	printf("---------\nA     B \n\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (0);
	if (!arguments_ok(argc, argv))
	{
		ft_printf("Error\n");
		exit(1);
	}
	stack_a = create_stack_with_args(argv);
	stack_b = create_stack();
	//print_stack(stack_a, stack_b);
	sort(stack_a, stack_b);
	//print_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
