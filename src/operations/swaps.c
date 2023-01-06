/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:22:49 by franmart          #+#    #+#             */
/*   Updated: 2023/01/06 11:38:57 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	swap_a(t_push_swap *ps, int mute)
{
	void	*ptr;

	if (ps->a_size < 2)
		return (0);
	ptr = ps->a->content;
	ps->a->content = ps->a->next->content;
	ps->a->next->content = ptr;
	if (!mute)
		ft_printf("sa\n");
	return (1);
}

int	swap_b(t_push_swap *ps, int mute)
{
	void	*ptr;

	if (ps->b_size < 2)
		return (0);
	ptr = ps->b->content;
	ps->b->content = ps->b->next->content;
	ps->b->next->content = ptr;
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
