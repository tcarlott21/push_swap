/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:38:24 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:57:48 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create(int value)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (0);
	tmp->value = value;
	tmp->next = NULL;
	return (tmp);
}

void	add_list_back(int value, t_stack *head)
{
	t_stack	*tmp;
	t_stack	*a;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return ;
	tmp->value = value;
	tmp->next = NULL;
	a = head;
	while (a->next != NULL)
		a = a->next;
	a->next = tmp;
}

t_stack	*add_list_front(int value, t_stack *head)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (0);
	tmp->value = value;
	tmp->next = head;
	return (tmp);
}

void	delete_last_stack(t_stack **head)
{
	t_stack	*last;
	t_stack	*tmp_head;
	int		size;

	tmp_head = *head;
	size = count_list(*head);
	while (size > 2)
	{
		tmp_head = tmp_head-> next;
		size--;
	}
	last = tmp_head->next;
	free(last);
	tmp_head->next = NULL;
}

int	count_list(t_stack *head)
{
	int	i;

	i = 1;
	while (head->next)
	{
		head = head->next;
		i++;
	}
	return (i);
}
