/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:20:16 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/20 13:56:26 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int	b;

	while (stack_a->first || stack_b->first)
	{
		if (stack_a->first)
		{
			if (stack_a)
				a = stack_a->first->value;
			stack_a->first = stack_a->first->next;
		}
		else
			a = 0;
		if (stack_b->first)
		{
			if (stack_b)
				b = stack_b->first->value;
			stack_b->first = stack_b->first->next;
		}
		else
			b = 0;
		printf("%d     %d \n", a, b);
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
	pb(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	(void) stack_b;
	return (0);
}
