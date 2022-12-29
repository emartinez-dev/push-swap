/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:22:49 by franmart          #+#    #+#             */
/*   Updated: 2022/12/29 16:45:58 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	swap_a(t_push_swap *ps, int mute)
{
	void	*ptr;

	if (ft_lstsize(ps->stack_a) < 2)
		return (0);
	ptr = ps->stack_a->content;
	ps->stack_a->content = ps->stack_a->next->content;
	ps->stack_a->next->content = ptr;
	if (!mute)
		ft_printf("sa\n");
	return (1);
}

int	swap_b(t_push_swap *ps, int mute)
{
	void	*ptr;

	if (ft_lstsize(ps->stack_b) < 2)
		return (0);
	ptr = ps->stack_b->content;
	ps->stack_b->content = ps->stack_b->next->content;
	ps->stack_b->next->content = ptr;
	if (!mute)
		ft_printf("sb\n");
	return (1);
}

int	swap_s(t_push_swap *ps)
{
	swap_a(ps, 1);
	swap_b(ps, 1);
	ft_printf("ss\n");
	return (1);
}
