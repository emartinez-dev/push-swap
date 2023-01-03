/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:44:12 by franmart          #+#    #+#             */
/*   Updated: 2023/01/03 18:26:24 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_big(t_push_swap *ps)
{
	int	min;

	if (is_sorted(ps->a))
		return ;
	while (ps->a->next != NULL && (ps->b != NULL || !is_sorted(ps->a)))
	{
		min = get_min(ps->a);
		optimum_rotate(ps, 'a', min, INT_MAX);
	}
	while (ps->b != NULL)
		push_a(ps);
	return ;
}

void	quicksort_a(t_push_swap *ps, int n)
{
	int	partition_len;
	int	median;

	if (n == 1)
		return ;
	partition_len = 0;
	median = get_median(ps->a);
	while (partition_len < n / 2)
	{
		if (*(int *)ps->a->content <= median)
		{
			push_b(ps);
			partition_len++;
		}
		else
			rotate_a(ps, 0);
	}
	quicksort_a(ps, n - partition_len);
	quicksort_b(ps);
}

void	quicksort_b(t_push_swap *ps)
{
	/* revisar esto, porque ya está funcionando casi */
	while (ps->b != NULL)
	{
		if (*(int *)ps->b->content < *(int *)ps->a->content)
			optimum_rotate(ps, 'b', INT_MIN, get_max(ps->b));
	}
}
