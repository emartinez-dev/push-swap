/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:24:07 by franmart          #+#    #+#             */
/*   Updated: 2022/12/28 21:16:14 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	reverse_rotate_a(t_push_swap *ps)
{
	t_list	*penultimate;
	t_list	*last;

	if (!ps->stack_a || ps->stack_a->next == NULL)
		return (0);
	penultimate = ps->stack_a;
	last = ft_lstlast(ps->stack_a);
	while (penultimate->next != last)
		penultimate = penultimate->next;
	penultimate->next = 0;
	last->next = ps->stack_a;
	ps->stack_a = last;
	return (1);
}

int	reverse_rotate_b(t_push_swap *ps)
{
	t_list	*penultimate;
	t_list	*last;

	if (!ps->stack_b || ps->stack_b->next == NULL)
		return (0);
	penultimate = ps->stack_b;
	last = ft_lstlast(ps->stack_b);
	while (penultimate->next != last)
		penultimate = penultimate->next;
	penultimate->next = 0;
	last->next = ps->stack_b;
	ps->stack_b = last;
	return (1);
}

int	reverse_rotate_r(t_push_swap *ps)
{
	reverse_rotate_a(ps);
	reverse_rotate_b(ps);
	return (1);
}
