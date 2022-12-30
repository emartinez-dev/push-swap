/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:20:24 by franmart          #+#    #+#             */
/*   Updated: 2022/12/30 18:01:12 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_2(t_push_swap *ps)
{
	if (!is_sorted(ps->a))
		rotate_a(ps, 0);
}

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

void	sort(t_push_swap *ps)
{
	if (ps->arr_len == 2)
		sort_2(ps);
	else if (ps->arr_len == 3)
		sort_3(ps);
}