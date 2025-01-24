/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:20:16 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/24 10:44:46 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	arguments_ok(int argc, char **argv)
{
	char **args;
	
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!one_argument_ok(args))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	else
	{
		args = argv;
		if (!more_arguments_ok(argc, args))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!arguments_ok(argc, argv))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	if (argc == 2)
		stack_a = create_stack_with_args(ft_split(argv[1], ' '), 0);
	else
		stack_a = create_stack_with_args(argv, 1);
	stack_b = create_stack();
	sort(stack_a, stack_b);
	//free(args);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
