/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:23:37 by franmart          #+#    #+#             */
/*   Updated: 2023/01/03 11:09:22 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rotate_a(t_push_swap *ps, int mute)
{
	t_list	*first;
	t_list	*last;

	if (!ps->a || ps->a->next == NULL)
		return (0);
	first = ps->a;
	ps->a = ps->a->next;
	last = ft_lstlast(ps->a);
	first->next = 0;
	last->next = first;
	if (!mute)
		ft_printf("ra\n");
	return (1);
}

int	rotate_b(t_push_swap *ps, int mute)
{
	t_list	*first;
	t_list	*last;

	if (!ps->b || ps->b->next == NULL)
		return (0);
	first = ps->b;
	ps->b = ps->b->next;
	last = ft_lstlast(ps->b);
	first->next = 0;
	last->next = first;
	if (!mute)
		ft_printf("rb\n");
	return (1);
}

int	rotate_r(t_push_swap *ps)
{
	rotate_a(ps, 1);
	rotate_b(ps, 1);
	ft_printf("rr\n");
	return (1);
}

void	rotate_n(t_push_swap *ps, char stack, int n, int reverse)
{
	int	i;

	i = 0;
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
