/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:14:18 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:52:08 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack **head)
{
	t_stack	*tmp_head;

	if (!(*head))
		exit (0);
	tmp_head = *head;
	while (tmp_head->next)
		tmp_head = tmp_head->next;
	*head = add_list_front(tmp_head->value, *head);
	delete_last_stack(head);
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_stack **datum_a, t_stack **datum_b)
{
	reverse_rotate(datum_a);
	reverse_rotate(datum_b);
}
