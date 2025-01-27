/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_ok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:24:16 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/27 10:24:44 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	arguments_ok(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!one_argument_ok(args))
		{
			write(2, "Error\n", 6);
			free_args(args);
			exit(1);
		}
		free_args(args);
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
