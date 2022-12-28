/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:23:37 by franmart          #+#    #+#             */
/*   Updated: 2022/12/28 21:16:07 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rotate_a(t_push_swap *ps)
{
	t_list	*first;
	t_list	*last;

	if (!ps->stack_a || ps->stack_a->next == NULL)
		return (0);
	first = ps->stack_a;
	ps->stack_a = ps->stack_a->next;
	last = ft_lstlast(ps->stack_a);
	first->next = 0;
	last->next = first;
	return (1);
}

int	rotate_b(t_push_swap *ps)
{
	t_list	*first;
	t_list	*last;

	if (!ps->stack_b || ps->stack_b->next == NULL)
		return (0);
	first = ps->stack_b;
	ps->stack_b = ps->stack_b->next;
	last = ft_lstlast(ps->stack_b);
	first->next = 0;
	last->next = first;
	return (1);
}

int	rotate_r(t_push_swap *ps)
{
	rotate_a(ps);
	rotate_b(ps);
	return (1);
}
