/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:44:12 by franmart          #+#    #+#             */
/*   Updated: 2023/01/07 18:37:15 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort(t_push_swap *ps)
{
	if (ps->a == NULL || is_sorted(ps->a))
		return ;
	get_stats(ps);
	if (ps->arr_len == 2)
		swap_a(ps, 0);
	else if (ps->arr_len == 3)
		sort_three(ps);
	else if (ps->arr_len <= 5)
		sort_five(ps);
	else
		split_and_sort(ps);
}

void	align_stack(t_push_swap *ps)
{
	int		min;
	t_list	*a;
	int		i;

	a = ps->a;
	min = get_min(ps->a);
	i = 0;
	while (*(int *)a->content != min)
	{
		a = a->next;
		i++;
	}
	if (i > ps->a_size / 2)
		rotate_n(ps, 'a', ps->a_size - i, 1);
	else
		rotate_n(ps, 'a', i, 0);
}

void	split_and_sort(t_push_swap *ps)
{
	while (ps->a_size > 2)
	{
		if (*(int *)ps->a->content != ps->min
			&& *(int *)ps->a->content != ps->max)
		{
			push_b(ps, 0);
			if (*(int *)ps->b->content > ps->median)
				rotate_b(ps, 0);
		}
		else
			rotate_a(ps, 0);
	}
	if (*(int *)ps->a->content < *(int *)ps->a->next->content)
		swap_a(ps, 0);
	while (ps->b != NULL)
		cheapest_insertion(ps);
	align_stack(ps);
}
