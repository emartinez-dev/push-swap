/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:22:49 by franmart          #+#    #+#             */
/*   Updated: 2023/10/01 18:55:10 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_push_swap *ps, int mute)
{
	void	*ptr;

	if (ps->a_size < 2)
		return ;
	ptr = ps->a->content;
	ps->a->content = ps->a->next->content;
	ps->a->next->content = ptr;
	if (!mute)
		ft_printf("sa\n");
}

void	swap_b(t_push_swap *ps, int mute)
{
	void	*ptr;

	if (ps->b_size < 2)
		return ;
	ptr = ps->b->content;
	ps->b->content = ps->b->next->content;
	ps->b->next->content = ptr;
	if (!mute)
		ft_printf("sb\n");
}

void	swap_s(t_push_swap *ps, int mute)
{
	swap_a(ps, 1);
	swap_b(ps, 1);
	if (!mute)
		ft_printf("ss\n");
}
