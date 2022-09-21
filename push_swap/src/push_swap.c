/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:34:14 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 15:01:03 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sort(char **argv)
{
	int	j;

	j = 1;
	while ((argv [j + 1] != (void *)0) && \
		(ft_atoi(argv[j]) < ft_atoi(argv[j + 1])))
		j++;
	if (argv[j + 1] == (void *)0)
		return (1);
	return (0);
}

void	free_list(t_stack **head)
{
	if ((*head)->next != NULL)
		free_list(&(*head)->next);
	free(*head);
}

static void	push_swap(int argc, char **argv)
{
	int		*arr;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		exit(0);
	if (input_check(argv))
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	if (check_sort(argv))
		exit (0);
	init_stack(argv, &stack_a);
	arr = ft_prev_sort(argc, argv);
	sort(&stack_a, &stack_b, argc, arr);
	free_list(&stack_a);
	free(arr);
}

static void	ft_free(char **argv, int i)
{
	while (i != 0)
	{
		free(argv[i - 1]);
		i--;
	}
	free(argv);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;

	j = argc;
	if (argc == 2)
	{
		str = "a ";
		argv[1] = ft_strjoin(str, argv[1]);
		argv = ft_split(argv[1], ' ');
		if (argv[0] == NULL)
			exit(0);
		i = 0;
		argc = 0;
		while (argv[i++])
			argc++;
	}
	push_swap(argc, argv);
	if (j == 2)
		ft_free(argv, i);
}
