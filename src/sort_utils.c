/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:42:11 by franmart          #+#    #+#             */
/*   Updated: 2022/12/31 13:13:27 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_max(t_list *stack)
{
	int		temp_max;
	t_list	*head;

	temp_max = INT_MIN;
	head = stack;
	while (head != NULL)
	{
		if (*(int *)head->content > temp_max)
			temp_max = *(int *)head->content;
		head = head->next;
	}
	return (temp_max);
}

int	get_min(t_list *stack)
{
	int		temp_min;
	t_list	*head;

	temp_min = INT_MAX;
	head = stack;
	while (head != NULL)
	{
		if (*(int *)head->content < temp_min)
			temp_min= *(int *)head->content;
		head = head->next;
	}
	return (temp_min);
}

void	n_rotations(t_push_swap *ps, char stack, int n, int reverse)
{
	int	i;

	i = 0;
	print_stacks(ps);
	ft_printf("N rotations: %d\n", n);
	while (i < n)
	{
		if (stack == 'a')
		{
			if (reverse == 1)
				reverse_rotate_a(ps, 0);
			else
				rotate_a(ps, 0);
		}
		if (stack == 'b')
		{
			if (reverse == 1)
				reverse_rotate_b(ps, 0);
			else
				rotate_b(ps, 0);
		}
		i++;
	}
}

int		get_median_index(t_list *stack, int min, int max)
{
	t_list 	*head;
	int		median_pos;
	int		i;

	i = 0;
	median_pos = -1;
	head = stack;
	while (head != NULL && median_pos == -1)
	{
		if (*(int *)head->content == min || *(int *)head->content == max)
			median_pos = i;
		head = head->next;
		i++;
	}
	return (median_pos);
}

/*
this functions calculates the minimum amount of moves to push min or max
value to the other stack.
*/
void	optimum_rotate(t_push_swap *ps, char stack_label, int min, int max)
{
	int		median_pos;
	t_list	*stack;
	int		size;

	if (stack_label == 'a')
		stack = ps->a;
	if (stack_label == 'b')
		stack = ps->b;
	size = ft_lstsize(stack);
	median_pos = get_median_index(stack, min, max);
	if (median_pos > size / 2)
		n_rotations(ps, stack_label, size - median_pos, 1);
	else
		n_rotations(ps, stack_label, median_pos, 0);
	if (stack_label == 'a')
		push_b(ps);
	if (stack_label == 'b')
		push_a(ps);
}