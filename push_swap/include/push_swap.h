/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:29:54 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:53:05 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		input_check(char **argv);
t_stack	*create(int value);
void	add_list_back(int value, t_stack *head);
void	print_list(t_stack *stack_a, t_stack *stack_b);
void	init_stack(char **argv, t_stack **head);
void	*ft_prev_sort(int argc, char **argv);

void	ft_putnbr(int n);
void	sort(t_stack **stack_a, t_stack **stack_b, int argc, int *arr);
void	sort_three(t_stack **head);
void	sort_five(t_stack **stack_a, t_stack **stack_b, int argc);
void	sort_big(t_stack **datum_a, t_stack **datum_b, int *arr);

int		is_sorted_a(t_stack **head);
void	free_list(t_stack **head);
int		check_sort(char **argv);
void	ft_read_stdin(t_stack **stack_a, t_stack **stack_b);
char	*ft_strjoinchar(char *s1, char c);

t_stack	*add_list_front(int value, t_stack *head);
void	delete_last_stack(t_stack **head);
int		count_list(t_stack *head);

void	swap(t_stack **head);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	rotate(t_stack **head);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	reverse_rotate(t_stack **head);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **datum_a, t_stack **datum_b);

void	push(t_stack **src, t_stack **dst);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

#endif
