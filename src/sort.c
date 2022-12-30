/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:20:24 by franmart          #+#    #+#             */
/*   Updated: 2022/12/30 18:14:24 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(t_push_swap *ps)
{
	int max;
	int	min;

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

void	sort_5(t_push_swap *ps)
{
	if (!is_sorted(ps->a))
	{
		push_b(ps);
		push_b(ps);
		sort_3(ps);
	}
}

void	sort(t_push_swap *ps)
{
	if (ps->arr_len <= 3)
		sort_3(ps);
	else if (ps->arr_len <= 5)
		sort_5(ps);
}