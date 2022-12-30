/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:20:24 by franmart          #+#    #+#             */
/*   Updated: 2022/12/30 20:21:19 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(t_push_swap *ps)
{
	int max;
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
	int	rotations_a;

	rotations_a = 0;
	if (!is_sorted(ps->a))
	{
		push_b(ps);
		push_b(ps);
	}
	sort_3(ps);
	while (!is_sorted(ps->a) || ps->b != NULL)
	{
		if (rotations_a != 0)
			push_a(ps);
		while (rotations_a > 0)
		{
			reverse_rotate_a(ps, 0);
			rotations_a--;
		}
		//ft_printf("Max B %d - Max A %d\n", get_max(ps->b),get_max(ps->a));
		if (*(int *)ps->b->content < *(int *)ps->a->content)
			push_a(ps);
		else if (*(int *)ps->b->content > get_max(ps->a))
		{
			push_a(ps);
			rotate_a(ps, 0);
		}
		else if (ps->b != NULL)
		{
			while (*(int *)ps->b->content > *(int *)ps->a->content)
			{
				rotate_a(ps, 0);
				rotations_a++;
			}
		}
	}
}

void	sort(t_push_swap *ps)
{
	if (ps->arr_len <= 3)
		sort_3(ps);
	else if (ps->arr_len <= 5)
		sort_5(ps);
}