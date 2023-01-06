/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:23:15 by franmart          #+#    #+#             */
/*   Updated: 2023/01/06 12:43:37 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push_a(t_push_swap *ps)
{
	t_list	*new;
	t_list	*temp;

	if (ps->b == NULL)
		return ;
	temp = ps->b;
	new = malloc(sizeof(t_list));
	new->content = ps->b->content;
	new->next = ps->a;
	ft_lstadd_front(&ps->a, new);
	ps->b = ps->b->next;
	ps->b_size--;
	ps->a_size++;
	ft_lstdelone(temp, ft_do_nothing);
	ft_printf("pa\n");
}

void	push_b(t_push_swap *ps)
{
	t_list	*new;
	t_list	*temp;

	if (ps->a == NULL)
		return ;
	temp = ps->a;
	new = malloc(sizeof(t_list));
	new->content = ps->a->content;
	new->next = ps->b;
	ft_lstadd_front(&ps->b, new);
	ps->a = ps->a->next;
	ps->a_size--;
	ps->b_size++;
	ft_lstdelone(temp, ft_do_nothing);
	ft_printf("pb\n");
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
