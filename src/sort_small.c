/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:20:24 by franmart          #+#    #+#             */
/*   Updated: 2023/10/01 18:53:17 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
this functions calculates the minimum amount of moves to push min or max
value to the other stack.
*/
void	push_minmax(t_push_swap *ps, char stack_label, int min, int max)
{
	int		mid_point;
	t_list	*stack;
	int		size;

	if (stack_label == 'a')
	{
		stack = ps->a;
		size = ps->a_size;
	}
	if (stack_label == 'b')
	{
		stack = ps->b;
		size = ps->b_size;
	}
	mid_point = get_min_or_max(stack, min, max);
	if (mid_point >= size / 2)
		rotate_n(ps, stack_label, size - mid_point, 1);
	else
		rotate_n(ps, stack_label, mid_point, 0);
	if (stack_label == 'a')
		push_b(ps, 0);
	if (stack_label == 'b')
		push_a(ps, 0);
}

void	sort_three(t_push_swap *ps)
{
	int	max;
	int	min;

	if (is_sorted(ps->a))
		return ;
	max = get_max(ps->a);
	min = get_min(ps->a);
	if (*(int *)ps->a->content == max && *(int *)ps->a->next->content == min)
		rotate_a(ps, 0);
	if (*(int *)ps->a->content == max && *(int *)ps->a->next->content != min)
	{
		swap_a(ps, 0);
		reverse_rotate_a(ps, 0);
	}
	if (*(int *)ps->a->content == min && *(int *)ps->a->next->content == max)
	{
		swap_a(ps, 0);
		rotate_a(ps, 0);
	}
	if (*(int *)ps->a->content != min && *(int *)ps->a->next->content == max)
		reverse_rotate_a(ps, 0);
	if (*(int *)ps->a->content != max && *(int *)ps->a->next->content == min)
		swap_a(ps, 0);
}

void	sort_five(t_push_swap *ps)
{
	int		min;
	int		max;

	min = get_min(ps->a);
	max = get_max(ps->a);
	while (ft_lstsize(ps->a) > 3)
	{
		if (*(int *)ps->a->content == min || *(int *)ps->a->content == max)
			push_b(ps, 0);
		else
			push_minmax(ps, 'a', min, max);
	}
	sort_three(ps);
	while (ps->b != NULL)
	{
		if (*(int *)ps->b->content == min)
			push_a(ps, 0);
		else if (*(int *)ps->b->content == max)
		{
			push_a(ps, 0);
			rotate_a(ps, 0);
		}
	}
}
