/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:40:05 by franmart          #+#    #+#             */
/*   Updated: 2023/01/06 13:51:33 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	print_stacks(t_push_swap *ps)
{
	t_list	*stack_a;
	t_list	*stack_b;

	ft_printf("Stack A\n");
	stack_a = ps->a;
	stack_b = ps->b;
	while (stack_a != NULL)
	{
		ft_printf("%d\t", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\nStack B\n");
	while (stack_b != NULL)
	{
		ft_printf("%d\t", *(int *)stack_b->content);
		stack_b = stack_b->next;
	}
	ft_printf("\n\n");
}
