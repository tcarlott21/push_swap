/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:29:55 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:51:22 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(char **argv, t_stack **head)
{
	int	j;

	j = 1;
	*head = create(ft_atoi(argv[j++]));
	while (argv[j])
	{
		add_list_back(ft_atoi(argv[j]), *head);
		j++;
	}
}

static int	ft_apply_instruction2(char *inst, t_stack **stack_a,
									t_stack **stack_b)
{
	if (!ft_strncmp(inst, "ra", 4))
		ra(stack_a);
	else if (!ft_strncmp(inst, "rb", 4))
		rb(stack_b);
	else if (!ft_strncmp(inst, "rr", 4))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(inst, "rra", 4))
		rra(stack_a);
	else if (!ft_strncmp(inst, "rrb", 4))
		rrb(stack_b);
	else if (!ft_strncmp(inst, "rrr", 4))
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

static void	ft_apply_instruction(char *inst, t_stack **stack_a,
		t_stack **stack_b)
{
	if (!inst)
		return ;
	if (!ft_strncmp(inst, "sa", 4))
		sa(stack_a);
	else if (!ft_strncmp(inst, "sb", 4))
		sb(stack_b);
	else if (!ft_strncmp(inst, "ss", 4))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(inst, "pa", 4))
		pa(stack_b, stack_a);
	else if (!ft_strncmp(inst, "pb", 4))
		pb(stack_a, stack_b);
	else if (!ft_apply_instruction2(inst, stack_a, stack_b))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

void	ft_read_stdin(t_stack **stack_a, t_stack **stack_b)
{
	char	*instruction;
	char	c;

	instruction = NULL;
	while (read(0, &c, 1))
	{
		if (c == '\n')
		{
			ft_apply_instruction(instruction, stack_a, stack_b);
			free(instruction);
			instruction = ft_strdup("");
		}
		else
			instruction = ft_strjoinchar(instruction, c);
	}
	free(instruction);
}
