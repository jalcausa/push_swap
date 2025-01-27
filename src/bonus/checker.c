/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:55:37 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/27 10:22:40 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_operations(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(stack_a, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(stack_b, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
	{
		ss(stack_a, stack_b, 0);
	}
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(stack_a, stack_b, 0);
	else
		ft_operations_2(line, stack_a, stack_b);
}

void	ft_operations_2(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(line, "ra\n", 3))
		ra(stack_a, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(stack_b, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(stack_a, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(stack_b, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(stack_a, stack_b, 0);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	ft_check(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		ft_operations(line, stack_a, stack_b);
		line = get_next_line(0);
	}
	if (stack_a->first && !stack_b->first && is_sorted(stack_a->first))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
	ft_check(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
