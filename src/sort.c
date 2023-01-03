/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:20:24 by franmart          #+#    #+#             */
/*   Updated: 2023/01/03 16:54:39 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(t_push_swap *ps)
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

void	sort_5(t_push_swap *ps)
{
	int		min;
	int		max;

	min = get_min(ps->a);
	max = get_max(ps->a);
	while (ft_lstsize(ps->a) > 3)
	{
		if (*(int *)ps->a->content == min || *(int *)ps->a->content == max)
			push_b(ps);
		else
			optimum_rotate(ps, 'a', min, max);
	}
	sort_3(ps);
	while (ps->b != NULL)
	{
		if (*(int *)ps->b->content == min)
			push_a(ps);
		else if (*(int *)ps->b->content == max)
		{
			push_a(ps);
			rotate_a(ps, 0);
		}
	}
}

void	sort(t_push_swap *ps)
{
	if (ps->a == NULL || is_sorted(ps->a))
		return ;
	if (ps->arr_len == 2)
		swap_a(ps, 0);
	else if (ps->arr_len == 3)
		sort_3(ps);
	else if (ps->arr_len <= 5)
		sort_5(ps);
	else
		quicksort_a(ps, ps->arr_len);
}
