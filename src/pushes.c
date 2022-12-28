/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:23:15 by franmart          #+#    #+#             */
/*   Updated: 2022/12/28 20:11:26 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push_a(t_push_swap *ps)
{
	t_list	*new;
	t_list	*temp;

	if (ps->stack_b == NULL)
		return (0);
	temp = ps->stack_b;
	new = malloc(sizeof(t_list));
	new->content = ps->stack_b->content;
	new->next = ps->stack_a;
	ft_lstadd_front(&ps->stack_a, new);
	ps->stack_b = ps->stack_b->next;
	ft_lstdelone(temp, do_nothing);
	return (1);
}

int	push_b(t_push_swap *ps)
{
	t_list	*new;
	t_list	*temp;

	if (ps->stack_a == NULL)
		return (0);
	temp = ps->stack_a;
	new = malloc(sizeof(t_list));
	new->content = ps->stack_a->content;
	new->next = ps->stack_b;
	ft_lstadd_front(&ps->stack_b, new);
	ps->stack_a = ps->stack_a->next;
	ft_lstdelone(temp, do_nothing);
	return (1);
}
