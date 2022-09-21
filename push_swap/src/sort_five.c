/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:07:06 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:58:32 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_min(t_stack **head)
{
	t_stack	*tmp_head;
	int		min;

	min = MAX_INT;
	tmp_head = *head;
	while (tmp_head)
	{
		if (min > tmp_head->value)
			min = tmp_head->value;
		tmp_head = tmp_head->next;
	}
	return (min);
}

static void	ft_moves(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int		small;
	t_stack	*tmp;

	tmp = *stack_a;
	small = find_min(stack_a);
	if (tmp->next->value == small)
		sa(stack_a);
	else if (tmp->next->next->value == small)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (tmp->next->next->next->value == small && argc == 6)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if ((tmp->next->next->next->value == small && argc == 5)
		|| (tmp->value != small && argc == 6))
		rra(stack_a);
	pb(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int	i;

	i = argc;
	while (argc != 4)
		ft_moves(stack_a, stack_b, argc--);
	sort_three(stack_a);
	pa(stack_b, stack_a);
	if (i == 6)
		pa(stack_b, stack_a);
}
