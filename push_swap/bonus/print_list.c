/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:19:09 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:51:27 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_list(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "\n", 1);
	write (1, "A ", 2);
	while (stack_a)
	{
		ft_putnbr_fd(stack_a->value, 1);
		write(1, " ", 1);
		stack_a = stack_a->next;
	}
	write(1, "\n", 1);
	write(1, "B ", 2);
	while (stack_b)
	{
		ft_putnbr_fd(stack_b->value, 1);
		write(1, " ", 1);
		stack_b = stack_b->next;
	}
	write(1, "\n", 1);
}
