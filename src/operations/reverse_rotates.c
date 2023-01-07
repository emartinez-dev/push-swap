/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:24:07 by franmart          #+#    #+#             */
/*   Updated: 2023/01/07 16:33:23 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	reverse_rotate_a(t_push_swap *ps, int mute)
{
	t_list	*penultimate;
	t_list	*last;

	if (!ps->a || ps->a->next == NULL)
		return ;
	penultimate = ps->a;
	last = ft_lstlast(ps->a);
	while (penultimate->next != last)
		penultimate = penultimate->next;
	penultimate->next = 0;
	last->next = ps->a;
	ps->a = last;
	if (!mute)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_push_swap *ps, int mute)
{
	t_list	*penultimate;
	t_list	*last;

	if (!ps->b || ps->b->next == NULL)
		return ;
	penultimate = ps->b;
	last = ft_lstlast(ps->b);
	while (penultimate->next != last)
		penultimate = penultimate->next;
	penultimate->next = 0;
	last->next = ps->b;
	ps->b = last;
	if (!mute)
		ft_printf("rrb\n");
}

void	reverse_rotate_r(t_push_swap *ps, int mute)
{
	reverse_rotate_a(ps, 1);
	reverse_rotate_b(ps, 1);
	if (!mute)
		ft_printf("rrr\n");
}
