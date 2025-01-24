/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:20:16 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/24 10:02:44 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (!one_argument_ok(argv[1]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	else
	{
		if (!arguments_ok(argc, argv))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	stack_a = create_stack_with_args(argv);
	stack_b = create_stack();
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
