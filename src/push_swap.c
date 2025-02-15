/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:20:16 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/27 10:27:20 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	if (argc < 2)
		return (0);
	if (!arguments_ok(argc, argv))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		stack_a = create_stack_with_args(args, 0);
		free_args(args);
	}
	else
		stack_a = create_stack_with_args(argv, 1);
	stack_b = create_stack();
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
