/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:12:29 by jalcausa          #+#    #+#             */
/*   Updated: 2025/01/24 10:36:35 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}

int	valid_size(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
	}
	res = res * sign;
	if (res < INT_MIN || res > INT_MAX)
		return (0);
	else
		return (1);
}

int	is_repeated(int n, int pos, char **argv, int i)
{
	while (argv[i] && i < pos)
	{
		if (ft_atoi(argv[i]) == n)
			return (1);
		++i;
	}
	return (0);
}

int	more_arguments_ok(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		if (!valid_size(argv[i]))
			return (0);
		if (is_repeated(ft_atoi(argv[i]), i, argv, 1))
			return (0);
		++i;
	}
	return (1);
}

int	one_argument_ok(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		if (!is_number(args[i]))
			return (0);
		if (!valid_size(args[i]))
			return (0);
		if (is_repeated(ft_atoi(args[i]), i, args, 0))
			return (0);
		++i;
	}
	return (1);
}
