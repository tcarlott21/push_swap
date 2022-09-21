/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:20:28 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:52:46 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **head)
{
	int	one;
	int	two;
	int	three;

	one = (*head)->value;
	two = (*head)->next->value;
	three = (*head)->next->next->value;
	if (one > two && three > two && three > one)
		sa(head);
	else if (one > two && one > three && two > three)
	{
		ra(head);
		sa(head);
	}
	else if (one > two && one > three && three > two)
		ra(head);
	else if (two > one && two > three && one > three)
		rra(head);
	else if (one < two && one < three && two > three)
	{
		rra(head);
		sa(head);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b, int argc, int *arr)
{
	if (argc == 3)
		sa(stack_a);
	else if (argc == 4)
		sort_three(stack_a);
	else if (argc == 5 || argc == 6)
		sort_five(stack_a, stack_b, argc);
	else if (argc > 6)
		sort_big(stack_a, stack_b, arr);
}

char	*ft_strjoinchar(char *s1, char c)
{
	char	*output;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	output = (char *) malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!output)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		output[i++] = s1[j++];
	output[i++] = c;
	output[i] = 0;
	free(s1);
	s1 = NULL;
	return (output);
}
