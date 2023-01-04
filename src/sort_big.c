/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:44:12 by franmart          #+#    #+#             */
/*   Updated: 2023/01/04 18:39:18 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_big(t_push_swap *ps)
{
	while (ft_lstsize(ps->a) > 2)
	{
		if (*(int *)ps->a->content != ps->min &&
			*(int *)ps->a->content != ps->max)
		{
			push_b(ps);
			if (*(int *)ps->b->content > ps->median)
				rotate_b(ps, 0);
		}
		else
			rotate_a(ps, 0);
	}
	if (*(int *)ps->a->content < *(int *)ps->a->next->content)
		swap_a(ps, 0);
	insertion_sort(ps);
	reverse_rotate_a(ps, 0);
}
void	insertion_sort(t_push_swap *ps)
{
	while (ps->b != NULL)
	{
		optimum_rotate(ps, 'b', INT_MIN, get_max(ps->b));
	}
}
