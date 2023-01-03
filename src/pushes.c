/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:23:15 by franmart          #+#    #+#             */
/*   Updated: 2023/01/03 11:09:03 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push_a(t_push_swap *ps)
{
	t_list	*new;
	t_list	*temp;

	if (ps->b == NULL)
		return (0);
	temp = ps->b;
	new = malloc(sizeof(t_list));
	new->content = ps->b->content;
	new->next = ps->a;
	ft_lstadd_front(&ps->a, new);
	ps->b = ps->b->next;
	ft_lstdelone(temp, do_nothing);
	ft_printf("pa\n");
	return (1);
}

int	push_b(t_push_swap *ps)
{
	t_list	*new;
	t_list	*temp;

	if (ps->a == NULL)
		return (0);
	temp = ps->a;
	new = malloc(sizeof(t_list));
	new->content = ps->a->content;
	new->next = ps->b;
	ft_lstadd_front(&ps->b, new);
	ps->a = ps->a->next;
	ft_lstdelone(temp, do_nothing);
	ft_printf("pb\n");
	return (1);
}

void	push_n(t_push_swap *ps, char stack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (stack == 'a')
			push_a(ps);
		if (stack == 'b')
			push_b(ps);
		i++;
	}
}
