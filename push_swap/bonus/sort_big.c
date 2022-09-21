/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:38:00 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:52:32 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	find_assign_index(t_stack **head, int *arr)
{
	t_stack	*tmp_head;
	int		i;
	int		size;

	i = 0;
	size = count_list(*head);
	tmp_head = *head;
	while (tmp_head)
	{
		i = 0;
		while (i < size)
		{
			if (tmp_head->value == arr[i])
			{
				tmp_head->index = i;
				break ;
			}
			i++;
		}
		tmp_head = tmp_head->next;
	}
}

static int	find_max_index(t_stack **head, int *arr)
{
	t_stack	*tmp_head;
	int		i;
	int		max;

	i = 0;
	tmp_head = *head;
	max = MIN_INT;
	find_assign_index(head, arr);
	i = 0;
	while (i < count_list(*head))
	{
		if (tmp_head->index > max)
			max = tmp_head->index;
		tmp_head = tmp_head->next;
		i++;
	}
	return (max);
}

static int	find_search_elems_place(t_stack **head, int max)
{
	t_stack	*tmp_head;
	int		i;

	i = 0;
	tmp_head = *head;
	while (tmp_head->next)
	{
		if (tmp_head->index == max)
			break ;
		tmp_head = tmp_head->next;
		i++;
	}
	return (i);
}

static void	sort_b(t_stack **stack_a, t_stack **stack_b, int *arr)
{
	int	i;
	int	max;
	int	arguments;

	while (*stack_b)
	{
		arguments = (count_list(*stack_b)) / 2;
		max = find_max_index(stack_b, arr);
		i = find_search_elems_place(stack_b, max);
		if ((*stack_b)->index == max)
			pa(stack_b, stack_a);
		else if (i <= arguments && (*stack_b)->index != max)
			rb(stack_b);
		else if (i > arguments && (*stack_b)->index != max)
			rrb(stack_b);
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b, int *arr)
{
	int		i;

	i = 0;
	find_assign_index(stack_a, arr);
	while (*stack_a)
	{
		if ((*stack_a)->index <= i && i > 0)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= (i + 23))
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index >= i)
			ra(stack_a);
	}
	sort_b(stack_a, stack_b, arr);
}
