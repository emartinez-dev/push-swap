/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:44:12 by franmart          #+#    #+#             */
/*   Updated: 2023/01/05 17:51:34 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	align_stack(t_push_swap *ps)
{
	int		min;
	int		size;
	t_list	*a;
	int		i;

	a = ps->a;
	min = get_min(ps->a);
	size = ps->a_size;
	i = 0;
	while (*(int *)a->content != min)
	{
		a = a->next;
		i++;
	}
	if (i > size / 2)
		rotate_n(ps, 'a', size - i, 1);
	else
		rotate_n(ps, 'a', i, 0);
}

void	sort_best_insertion(t_push_swap *ps)
{
	int	size;

	size = ps->a_size;
	while (size > 2)
	{
		if (*(int *)ps->a->content != ps->min
			&& *(int *)ps->a->content != ps->max)
		{
			push_b(ps);
			size--;
			if (*(int *)ps->b->content > ps->median)
				rotate_b(ps, 0);
		}
		else
			rotate_a(ps, 0);
	}
	if (*(int *)ps->a->content < *(int *)ps->a->next->content)
		swap_a(ps, 0);
	while (ps->b != NULL)
		do_best_moves(ps);
	align_stack(ps);
}
