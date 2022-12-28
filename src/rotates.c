/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:23:37 by franmart          #+#    #+#             */
/*   Updated: 2022/12/28 20:53:57 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rotate_a(t_push_swap *ps)
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

int	rotate_b(t_push_swap *ps)
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

int	rotate_r(t_push_swap *ps)
{
	rotate_a(ps);
	rotate_b(ps);
	return (1);
}