/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:38:51 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:51:15 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_integer(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_duplicate(char **argv)
{
	int	number;
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		number = ft_atoi(argv[i]);
		while (argv[j])
		{
			if (number == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static long	ft_atol(char *str)
{
	int		i;
	long	number;
	long	sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10;
		number = number + str[i] - '0';
		i++;
	}
	number = number * sign;
	return (number);
}

static int	is_stackover(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > MAX_INT || ft_atol(argv[i]) < MIN_INT)
			return (1);
		i++;
	}
	return (0);
}

int	input_check(char **argv)
{
	if (is_integer(argv) == 1 || is_stackover(argv) == 1
		|| is_duplicate(argv) == 1)
		return (1);
	return (0);
}
